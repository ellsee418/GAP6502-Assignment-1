#pragma once
#include <vector>

class IEntity;
class EntityManager
{
public:
	static EntityManager* Get();
	void Update();
	void AddEntity(IEntity* entity);
	void ResetEntities();
	void HandleEntities();



	~EntityManager();
private:
	EntityManager();
	EntityManager(const EntityManager&) = delete;

	std::vector<IEntity*> m_entities;
};

