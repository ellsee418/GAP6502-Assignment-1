#pragma once
#include <cmath>
#include <random>
#include <SFML/System/Vector2.hpp>

inline void InitRand() { srand(time(NULL)); } 

inline float Length(const sf::Vector2f& vec) { return std::sqrtf(vec.x * vec.x + vec.y * vec.y); }

inline sf::Vector2f Normalize(const sf::Vector2f& vec) { return vec / Length(vec); }

// https://www.geeksforgeeks.org/cpp/generate-a-random-float-number-in-cpp/
inline int randomInt(int a, int b)
{
    if (a > b)
        return randomInt(b, a);
    if (a == b)
        return a;
    return a + (rand() % (b - a));
}

inline float randomFloat(int a, int b)
{
    if (a > b)
        return randomFloat(b, a);
    if (a == b)
        return a;

    return (float)randomInt(a, b) + (float)(rand()) / (float)(RAND_MAX);
}