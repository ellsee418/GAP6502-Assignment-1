#pragma once
#include <vector>

class IEntity;

class EntityManager
{
public:
	static EntityManager* Get();

	void DeInit();

	void Update();
	void AddEntity(IEntity* entity);
	void ResetEntities();
	void HandleEntities();
	void FreeDeadProjectiles();

	~EntityManager();
	EntityManager(EntityManager& other) = delete;
	void operator=(const EntityManager&) = delete;
private:
	EntityManager();
	static EntityManager* sInstance;
	static void Init();

	std::vector<IEntity*> m_entities;
};

