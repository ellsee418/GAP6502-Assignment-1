#pragma once
#include "Entity.h"
#include "Button.h"
#include "common.h"

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

inline bool IsCollidingMouse(sf::Vector2f mousePos, sf::FloatRect bounds)
{
	return bounds.contains(mousePos);
}

inline void HandleCollidingEntity(IEntity* entity, IEntity* other)
{
	if (!IsCollidingEntity(entity, other)) return;
	
	entity->OnEntityCollision(other);
	other->OnEntityCollision(entity);
}

inline void HandleCollidingBounds(IEntity* entity)
{
	// better but not great lol
	sf::Vector2f pos = entity->GetPosition();
	sf::Vector2f vel = entity->GetVelocity();
	float size = entity->Size();
	float minX, minY, maxX, maxY;

	minX = pos.x - size; minY = pos.y - size;
	maxX = pos.x + size; maxY = pos.y + size;
	
	bool collided = false;
	if (minX < 0 || maxX > WIN_WIDTH)
	{
		collided = true;
		vel.x *= -1;
	}

	if (minY < 0 || maxY > WIN_HEIGHT)
	{
		collided = true;
		vel.y *= -1;
	}

	if (collided) entity->OnBoundsCollision();
	entity->SetVelocity(vel);

	// always make sure enemies are spawned at least e->Size() away 
	// from window borders otherwise InitBeyblade()
	// they do get unstuck eventually but could be outside window
}