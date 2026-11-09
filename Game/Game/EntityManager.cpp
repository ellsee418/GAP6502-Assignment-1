#include "EntityManager.h"
#include "Collision.hpp"
#include "Renderer.h"
#include "Entity.h"


EntityManager* EntityManager::sInstance = nullptr;

EntityManager* EntityManager::Get()
{
	if (!sInstance) Init();
	return sInstance;
}

void EntityManager::Init()
{
	sInstance = new EntityManager();
}

void EntityManager::DeInit()
{
	ResetEntities();
	delete sInstance;
	sInstance = nullptr;
}

void EntityManager::Update()
{
	HandleEntities();
	Renderer::Get().Render(m_entities);
}

void EntityManager::AddEntity(IEntity* entity)
{
	m_entities.push_back(entity);
}

void EntityManager::ResetEntities()
{
	for (int i = 0; i < m_entities.size(); ++i)
	{
		if (m_entities[i])
			delete m_entities[i];
	}
	m_entities.clear();
}

void EntityManager::HandleEntities()
{
	for (int i = 0 ; i < m_entities.size(); ++i)
	{
		IEntity* e = m_entities[i];
		e->Update();
		if (!e->Active()) continue;
		HandleCollidingBounds(e);

		for (int j = 0; j < m_entities.size(); ++j)
		{
			IEntity* o = m_entities[j];
			if (!e->Active() || !o->Active()) continue;
			HandleCollidingEntity(e, o);
		}
	}
}

EntityManager::EntityManager()
{
}

EntityManager::~EntityManager()
{
	ResetEntities();
}
