#pragma once
#include "Entity.h"
#include "common.h"

//perhaps handle this somewhere else
inline bool IsCollidingEntity(IEntity* entity, IEntity* other)
{
	if (!entity->Collides() || !other->Collides()) return false;


}

inline void HandleCollidingBounds(IEntity* entity)
{
	// add velocity
	sf::Vector2f pos = entity->GetPosition();
	float size = entity->Size();

	if (pos.x < 0 + size)
		pos.x = size;

	if (pos.x > WIN_WIDTH - size)
		pos.x = WIN_WIDTH - size;

	if (pos.y < 0 + size)
		pos.y = size;

	if (pos.y > WIN_HEIGHT - size)
		pos.y = WIN_HEIGHT - size;

	entity->SetPosition(pos);
}