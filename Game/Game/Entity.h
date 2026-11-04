#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>

class IEntity
{
public:
	virtual ~IEntity() = default;
	virtual sf::Vector2f GetPosition() = 0;
	virtual void SetPosition(sf::Vector2f pos) = 0;

	virtual void Update() = 0;
	virtual bool Active() = 0;
	virtual void Kill() = 0;

	virtual float Angle() = 0;
	virtual void SetAngle(float angle) = 0;
	virtual sf::Color Colour() = 0;
	virtual float Size() = 0;
	virtual int Points() = 0;
private:

};

class Entity : public IEntity
{
public:
	Entity(sf::Vector2f pos = { 0.f, 0.f }, sf::Color col = sf::Color::Red, float size = 30.f, int points = 3, float angle = 0.f);

	virtual sf::Vector2f GetPosition() override;
	virtual void SetPosition(sf::Vector2f pos) override;

	virtual void Update() override;
	bool Active() override;
	void Kill() override;

	virtual float Angle() override;
	virtual void SetAngle(float angle) override;
	virtual sf::Color Colour() override;
	virtual float Size() override;
	virtual int Points() override;
private:
	bool m_active;
	sf::Vector2f m_pos;
	sf::Color m_colour;
	float m_size;// fixed for now, add w/l later
	float m_angle;
	int m_points;
};
