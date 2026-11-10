#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Button
{
public:
    Button(const sf::Font& font, std::string text, sf::Vector2f pos,
        sf::Vector2f size = { 200.f, 60.f });

    bool Clicked();
    void Hover();

    sf::FloatRect GetBounds();
    sf::RectangleShape& GetShape();
    sf::Text& GetText();
    void SetPosition(sf::Vector2f pos);
private:
    void CentreText();

    sf::RectangleShape  m_shape;
    sf::Text            m_text;
    bool                m_hovered;
};

