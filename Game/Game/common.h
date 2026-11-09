#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <stdio.h>

const sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
const unsigned int WIN_WIDTH = (desktop.width * 0.5f);
const unsigned int WIN_HEIGHT = (desktop.height * 0.75f);