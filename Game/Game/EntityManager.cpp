#include "EntityManager.h"
#include "Collision.hpp"
#include "Renderer.h"
#include "Entity.h"

EntityManager* EntityManager::Get()
{
	static EntityManager* sInstance = new EntityManager();
	return sInstance;
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
}

void EntityManager::HandleEntities()
{
	for (int i = 0 ; i < m_entities.size(); ++i)
	{
		IEntity* e = m_entities[i];
		if (!e->Active()) continue;
		e->Update();
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

}
