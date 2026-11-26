#pragma once
#include <cstdint>
#include <stdio.h>

using byte = unsigned char;

static const size_t sSlabSizes[] = { 8,16,32,64,128 };
static const size_t sNumSlabs = sizeof(sSlabSizes) / sizeof(sSlabSizes[0]);

class MemoryManager
{
public:
	~MemoryManager() = default;
	void DeInit();
	void Reset();

	static MemoryManager* Get();

	void* Allocate(const size_t size);// cant make const ref
	void Deallocate(void* deleted);

	MemoryManager(MemoryManager& other) = delete;
	void operator=(const MemoryManager&) = delete;
protected:
	MemoryManager();
	static MemoryManager* sInstance;
private:
	struct Slab;
	struct MetaData // linked list pool for reusing memory
	{
		MetaData* next;
		Slab* slab;
		size_t objSize;
		bool isFree;
	};
	struct Slab
	{
		size_t chunkSize;
		byte* start;
		byte* end;
		MetaData* freeStore;
	};

	void AllocateSlab(const size_t& slabIndex);
	void* HeapAllocate(const size_t& size);
	void HeapDeallocate(void* deleted, MetaData* header);

	void Init();
	void CleanUp();

	Slab m_slabs[sNumSlabs];
	static const size_t HEADER_SIZE = sizeof(MetaData);
};
