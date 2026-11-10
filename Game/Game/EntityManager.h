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
private:
	EntityManager();
	EntityManager(const EntityManager&) = delete;
	static EntityManager* sInstance;
	static void Init();

	std::vector<IEntity*> m_entities;
};

