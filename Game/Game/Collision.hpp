#pragma once
#include "Entity.h"
#include "common.h"

// think inline is fine for this. fits the use case.
inline bool IsCollidingEntity(IEntity* entity, IEntity* other)
{
	if (entity == other) return false; 
	if (!entity->Collides() || !other->Collides()) return false;

	sf::Vector2f pos = entity->GetPosition();
	float size = entity->Size();

	float minX = pos.x - size; float minY = pos.y - size;
	float maxX = pos.x + size; float maxY = pos.y + size;

	sf::Vector2f oPos = other->GetPosition();
	float oSize = other->Size();

	float oMinX = oPos.x - oSize; float oMinY = oPos.y - oSize;
	float oMaxX = oPos.x + oSize; float oMaxY = oPos.y + oSize;

	if (minX > oMaxX || oMinX > maxX) return false;
	if (minY > oMaxY || oMinY > maxY) return false;

	return true;
}

inline void HandleCollidingEntity(IEntity* entity, IEntity* other)
{
	if (!IsCollidingEntity(entity, other)) return;

	printf("collision\n");
}

inline void HandleCollidingBounds(IEntity* entity)
{
	sf::Vector2f pos = entity->GetPosition();
	float size = entity->Size();
	float minX, minY, maxX, maxY;

	minX = pos.x - size; minY = pos.y - size;
	maxX = pos.x + size; maxY = pos.y + size;
	

	if (minX < 0)
		pos.x = size;

	if (pos.x > WIN_WIDTH - size)
		pos.x = WIN_WIDTH - size;

	if (pos.y < 0 + size)
		pos.y = size;

	if (pos.y > WIN_HEIGHT - size)
		pos.y = WIN_HEIGHT - size;

	//if (pos.x < 0 + size)
	//	pos.x = size;

	//if (pos.x > WIN_WIDTH - size)
	//	pos.x = WIN_WIDTH - size;

	//if (pos.y < 0 + size)
	//	pos.y = size;

	//if (pos.y > WIN_HEIGHT - size)
	//	pos.y = WIN_HEIGHT - size;

	entity->SetPosition(pos);
}