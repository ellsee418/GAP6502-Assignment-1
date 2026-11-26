#include "MemoryManager.h"
#include "Logger.h"
#include <stdlib.h>
#include <memory>

#ifdef TEST
#define SLAB_SIZE 512 * 1024 // val * KB
#else
#define SLAB_SIZE 32 * 1024 // val * KB
#endif


MemoryManager* MemoryManager::sInstance = nullptr;

MemoryManager::MemoryManager()
{
	Init();
}

void MemoryManager::Init()
{
	LOGA(SYSTEM,"[MemoryManager] Beginning slab allocation... Size: %i ", SLAB_SIZE);
	for (size_t i = 0; i < sNumSlabs; ++i)
	{
		try {AllocateSlab(i);}
		catch (std::bad_alloc())
		{
			LOGA(WARNING, "Bad alloc in slab allocation: Slab Index %zu ", i);
			Reset();
		}
	}
	LOGA(SUCCESS, "[MemoryManager] Slab allocation finalised.\n ");
}

void MemoryManager::DeInit()
{
	CleanUp();
	free(sInstance);
	sInstance = nullptr;
}

void MemoryManager::Reset()
{
	LOGA(SYSTEM, "[MemoryManager] Resetting...");
	DeInit();
	Init();
	LOGA(SUCCESS, "[MemoryManager] Reset Successful...");
}

void MemoryManager::CleanUp()
{
	LOGA(SYSTEM, "[MemoryManager] Initiating Clean Up...");
	for (size_t i = 0; i < sNumSlabs; ++i)
	{
		Slab& slab = m_slabs[i];
		free(slab.start);
		slab.start = nullptr;
	}
	LOGA(SUCCESS, "[MemoryManager] Finalised Clean Up.");
}

MemoryManager* MemoryManager::Get()
{
	if (!sInstance)
	{
		LOGA(SUCCESS, "[MemoryManager] Created instance.");
		void* ptr = static_cast<MemoryManager*>(malloc(sizeof(MemoryManager)));
		sInstance = new(ptr) MemoryManager();
	}
	return sInstance;
}

// CAST TYPES - specific for safety
// const_cast		 ->		add/remove const specifier from a variable.
// static_cast		 ->		compile time conversion for compatible types that compiler deems safe. e.g int -> char
// dynamic_cast		 ->		runtime conversion for base and derived class using polymorphic structure e.g IEntity* -> Entity*
// reinterpret_cast	 ->		converts a pointer type to another pointer type. no compile or runtime check during conversion. used
//							mainly to convert to raw byte in low level memory manipulation. 
//							e.g int* intPtr 10; char* charPtr = reinterpret_cast<char*>(var); -> same address, char* can be used for 
//							byte manipulation.


void MemoryManager::AllocateSlab(const size_t& slabIndex)
{
	if (slabIndex > sNumSlabs)
	{
		LOGF(ERROR, "Slab allocation refused. Slab Index: %zu is out of range: %zu ", slabIndex, sNumSlabs);
		return;
	}

	Slab& slab = m_slabs[slabIndex];

	size_t payloadSize = sSlabSizes[slabIndex];
	slab.chunkSize = HEADER_SIZE + payloadSize; // header + data = chunk
	size_t numChunks = SLAB_SIZE / slab.chunkSize;

	slab.start = reinterpret_cast<byte*>(malloc(SLAB_SIZE));
	if (!slab.start) throw std::bad_alloc();

	slab.freeStore = nullptr;
	for (size_t i = 0; i < numChunks; ++i) // init slab headers
	{
		MetaData* header = reinterpret_cast<MetaData*>(slab.start + (i * slab.chunkSize)); // find address of header
		header->slab = &slab;
		header->next = slab.freeStore;
		slab.freeStore = header; // first will be nullptr to mark the end of linked list
	}
	slab.end = reinterpret_cast<byte*>(slab.start + SLAB_SIZE);
	// chunk size here ignores header size for console output
	LOGF(SYSTEM, "Slab %zu Allocated. Chunk Size: %zu + Header Size: %zu \n", slabIndex, payloadSize, HEADER_SIZE);
}

inline void* MemoryManager::Allocate(const size_t size)
{
	if (size == 0) return nullptr;

	size_t slabIdx = 0;
	for (slabIdx; slabIdx < sNumSlabs; ++slabIdx)
		if (size <= sSlabSizes[slabIdx])
		{
			LOGF(SYSTEM, "Allocate: slab: %zu size: %zu\n", slabIdx, sSlabSizes[slabIdx]);
			break;
		}

	Slab& slab = m_slabs[slabIdx];

	if (slabIdx == sNumSlabs 
		|| !slab.freeStore) return HeapAllocate(size);

	MetaData* header = slab.freeStore;
	slab.freeStore = header->next;
	header->objSize = size;
	header->isFree = false;

	LOGF(INFO, "Allocating: %p Next Addr: %p\n", (void*)header, (void*)header->next);

	void* value = reinterpret_cast<byte*>(header) + HEADER_SIZE;
	return value;
}

inline void* MemoryManager::HeapAllocate(const size_t& size)
{
	LOGF(WARNING, "Allocate: Object cannot fit in any slab.\n");

	size_t allocSize = size + HEADER_SIZE;
	void* fullBlock = malloc(allocSize);
	if (!fullBlock) throw std::bad_alloc();

	MetaData* header = reinterpret_cast<MetaData*>(fullBlock);
	header->next = nullptr;
	header->slab = nullptr;
	header->objSize = size;
	header->isFree = false;

	void* value = reinterpret_cast<byte*>(header) + HEADER_SIZE;
	LOGF(INFO, "Allocate: Heap Allocation\nHeader:\nSize: %zu Addr: %p\nObj:\nSize: %zu Addr: %p\n", HEADER_SIZE, (void*)header, size, (void*)value);
	return value;
}

inline void MemoryManager::Deallocate(void* deleted)
{
	if (!deleted) return;
	MetaData* header = reinterpret_cast<MetaData*>(
		reinterpret_cast<byte*>(deleted) - HEADER_SIZE);
	if (!header) return;
	if (header->isFree)
	{
		LOGF(ERROR, "Error trying to free %p. Memory has already been deallocated.\n", header);
		return;
	}
	if (!header->slab) return HeapDeallocate(deleted, header);

	Slab& slab = *header->slab;

	LOGF(INFO, "Deallocating: %p Next Addr: %p\n", (void*)header, (void*)header->next);

	header->isFree = true;
	header->next = slab.freeStore;
	slab.freeStore = header;
}

inline void MemoryManager::HeapDeallocate(void* deleted, MetaData* header)
{
	LOGF(INFO, "Deallocate: Heap Deallocation\nHeader:\nSize: %zu Addr: %p\nObj:\nSize: %zu Addr: %p\n", HEADER_SIZE, (void*)header, header->objSize, (void*)deleted);
	if(header)
		free(header);
	header = nullptr;
	return;
}

// GLOBAL
void* operator new (size_t size)
{
	LOGF(INFO, "Allocate called. size: %zu\n", size);
	return MemoryManager::Get()->Allocate(size);
}

void* operator new[](size_t size)
{
	LOGF(INFO, "Allocate[] called. size: %zu\n", size);
	return MemoryManager::Get()->Allocate(size);
}

void operator delete(void* ptrToDelete)
{
	LOGF(INFO, "Deallocate called. ptr: %p\n", ptrToDelete);
	MemoryManager::Get()->Deallocate(ptrToDelete);
}

void operator delete[](void* ptrToDelete)
{
	LOGF(INFO, "Deallocate[] called. ptr: %p\n", ptrToDelete);
	MemoryManager::Get()->Deallocate(ptrToDelete);
}