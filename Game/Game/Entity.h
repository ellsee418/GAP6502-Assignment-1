#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>

class IEntity
{
public:
	virtual ~IEntity() = default;

	virtual void			Update() = 0;
	virtual bool			Active() = 0;
	virtual void			Kill() = 0;
	virtual bool			Collides() = 0;
	virtual float			Size() = 0;
	virtual int				Points() = 0;

	virtual sf::Vector2f	GetPosition() = 0;
	virtual void			SetPosition(sf::Vector2f pos) = 0;
	virtual float			GetAngle() = 0;
	virtual void			SetAngle(float angle) = 0;
	virtual sf::Vector2f	GetVelocity() = 0;
	virtual void			SetVelocity(sf::Vector2f vel) = 0;
	virtual sf::Color		GetColour() = 0;
	virtual void			SetColour(sf::Color col) = 0;

	virtual void			OnBoundsCollision() = 0;
private:

};

class Entity : public IEntity
{
public:
	Entity(sf::Vector2f pos = { 0.f, 0.f }, sf::Color col = sf::Color::Red, float size = 30.f, int points = 3, float angle = 0.f);

	virtual void			Update() override;
			bool			Active() override;
			void			Kill() override;
	virtual bool			Collides() override;
	virtual float			Size() override;
	virtual int				Points() override;

	virtual sf::Vector2f	GetPosition() override;
	virtual void			SetPosition(sf::Vector2f pos) override;
	virtual float			GetAngle() override;
	virtual void			SetAngle(float angle) override;
			sf::Vector2f	GetVelocity() override;
			void			SetVelocity(sf::Vector2f vel) override;
	virtual sf::Color		GetColour() override;
	virtual void			SetColour(sf::Color col) override;

	virtual void			OnBoundsCollision() {};
protected:
	bool			m_active, m_collides;
	sf::Vector2f	m_pos;
	sf::Color		m_colour;
	float			m_size;// fixed for now, add w/l later
	float			m_angle;
	int				m_points;
	sf::Vector2f	m_velocity;
};
