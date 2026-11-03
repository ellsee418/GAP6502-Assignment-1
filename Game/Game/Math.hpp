#pragma once
#include <cmath>
#include <SFML/System/Vector2.hpp>

//why doesnt smfl have this smh
inline float Length(const sf::Vector2f& vec) { return std::sqrtf(vec.x * vec.x + vec.y * vec.y); }

inline sf::Vector2f Normalize(const sf::Vector2f& vec) { return vec / Length(vec); }