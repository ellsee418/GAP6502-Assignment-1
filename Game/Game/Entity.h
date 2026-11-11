#pragma once
#include "common.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>

enum class EntityType {Entity, Character, Player, Enemy, Projectile};

class IEntity
{
public:
	virtual ~IEntity() = default;

	virtual void			Update() = 0;
	virtual bool			Active() const = 0;
	virtual void			Kill() = 0;
	virtual bool			Collides() const = 0;
	virtual bool			ShouldDraw() const = 0;
	virtual EntityType		Type() const = 0;
	virtual float			Size() const = 0;
	virtual int				Points() const = 0;

	virtual sf::Vector2f	GetPosition() const = 0;
	virtual void			SetPosition(sf::Vector2f pos) = 0;
	virtual float			GetAngle() const = 0;
	virtual void			SetAngle(float angle) = 0;
	virtual sf::Vector2f	GetVelocity() const = 0;
	virtual void			SetVelocity(sf::Vector2f vel) = 0;
	virtual sf::Color		GetColour() const = 0;
	virtual void			SetColour(sf::Color col) = 0;

	virtual void			OnBoundsCollision() = 0;
	virtual void			OnEntityCollision(IEntity* other) = 0;
private:

};

class Entity : public IEntity
{
public:
	Entity(sf::Vector2f pos = { 0.f, 0.f }, sf::Color col = sf::Color::Red, float size = 30.f, int points = 3, float angle = 0.f);

	virtual void			Update() override;
			bool			Active() const override;
			void			Kill() override;
	virtual bool			Collides() const override;
	virtual bool			ShouldDraw() const override;
	virtual EntityType		Type() const override;
	virtual float			Size() const override;
	virtual int				Points() const override;

	virtual sf::Vector2f	GetPosition() const override;
	virtual void			SetPosition(sf::Vector2f pos) override;
	virtual float			GetAngle() const override;
	virtual void			SetAngle(float angle) override;
			sf::Vector2f	GetVelocity() const override;
			void			SetVelocity(sf::Vector2f vel) override;
	virtual sf::Color		GetColour() const override;
	virtual void			SetColour(sf::Color col) override;

	virtual void			OnBoundsCollision() override {};
	virtual void			OnEntityCollision(IEntity* other) override {};

protected:
	bool			m_active, m_collides, m_draw;
	sf::Vector2f	m_pos;
	sf::Color		m_colour;
	float			m_size;
	float			m_angle;
	int				m_points;
	sf::Vector2f	m_velocity;
	EntityType		m_type;
};
