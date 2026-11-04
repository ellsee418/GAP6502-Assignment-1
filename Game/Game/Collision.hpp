#pragma once
#include "Entity.h"
#include "common.h"

//perhaps handle this somewhere else
inline bool IsCollidingEntity(IEntity* entity, IEntity* other)
{
	if (!entity->Collides() || !other->Collides()) return false;


}

inline bool IsCollidingBounds(IEntity* entity)
{
	
}