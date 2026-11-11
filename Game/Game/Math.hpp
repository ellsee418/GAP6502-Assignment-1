#pragma once
#include "common.h"
#include <cmath>
#include <random>
#include <SFML/System/Vector2.hpp>

inline void InitRand() { srand(time(NULL)); } 

inline float Length(const sf::Vector2f& vec) { return std::sqrtf(vec.x * vec.x + vec.y * vec.y); }

inline sf::Vector2f Normalize(const sf::Vector2f& vec) { return vec / Length(vec); }

// https://www.geeksforgeeks.org/cpp/generate-a-random-float-number-in-cpp/
inline int RandomInt(const int& a, const int& b)
{
    if (a > b)
        return RandomInt(b, a);
    if (a == b)
        return a;
    return a + (rand() % (b - a));
}

inline float RandomFloat(const int& a, const int& b)
{
    if (a > b)
        return RandomFloat(b, a);
    if (a == b)
        return a;

    return (float)RandomInt(a, b) + (float)(rand()) / (float)(RAND_MAX);
}

inline float Distance(const sf::Vector2f& lhs, const sf::Vector2f& rhs)
{
    float dx = abs(rhs.x - lhs.x);
    float dy = abs(rhs.y - lhs.y);
    return sqrtf(dx * dx + dy * dy);
}

inline sf::Vector2f RandomPosition(const sf::Vector2f& avoidPos)
{
    sf::Vector2f newPos = { 0.f, 0.f };
    const float padding = 30.f;
    do
    {
        newPos.x = RandomFloat(padding, WIN_WIDTH -  padding);
        newPos.y = RandomFloat(padding, WIN_HEIGHT - padding);

    } while (Distance(newPos, avoidPos) < padding);

    return newPos;
}