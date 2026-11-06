#include "Button.h"
#include "Collision.hpp"
#include "InputManager.h"
#include "Renderer.h"


Button::Button(const sf::Font& font, std::string text, sf::Vector2f pos, sf::Vector2f size)
    : m_hovered(false)
{
    m_shape.setPosition(pos);
    m_shape.setSize(size);
    m_shape.setFillColor(sf::Color(60, 60, 60));
    m_shape.setOutlineThickness(2.f);
    m_shape.setOutlineColor(sf::Color(200, 200, 200));

    m_text.setFont(font);
    m_text.setString(text);
    m_text.setCharacterSize(24);
    m_text.setFillColor(sf::Color::White);

    CentreText();
}

bool Button::Clicked()
{
    return InputManager::Get().GetMouseDown(0) && m_hovered;// left mouse
}

void Button::Hover()
{
    sf::Vector2f mouse = (sf::Vector2f)InputManager::Get().GetMousePos();
    m_hovered = IsCollidingMouse(mouse, GetBounds());

    if (m_hovered)
        m_shape.setFillColor(sf::Color(200, 200, 200));
    else
        m_shape.setFillColor(sf::Color(60, 60, 60));
}

sf::RectangleShape& Button::GetShape()
{
    return m_shape;
}

sf::Text& Button::GetText()
{
    return m_text;
}

void Button::SetPosition(sf::Vector2f pos)
{
    m_shape.setPosition(pos);
    CentreText();
}

void Button::CentreText()
{
    sf::FloatRect textRect = m_text.getLocalBounds();

    m_text.setOrigin(textRect.left + textRect.width / 2.f,
        textRect.top + textRect.height / 2.f);

    sf::Vector2f centre = m_shape.getPosition() + m_shape.getSize() / 2.f;
    m_text.setPosition(centre);
}
