#include "BulletFactory.h"
#include "EntityManager.h"
#include "Projectile.h"


BulletFactory::BulletFactory()
{

}

BulletFactory::~BulletFactory()
{
}



BulletFactory& BulletFactory::Get()
{
    static BulletFactory sInstance;
    return sInstance;
}

void BulletFactory::Init()
{
    
}

void BulletFactory::Create(sf::Vector2f target, sf::Vector2f spawn)
{
    EntityManager::Get()->AddEntity(new Projectile(spawn, target));
}
