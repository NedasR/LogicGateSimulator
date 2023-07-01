#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#define PI 3.14
namespace Utils
{
	float calculateAngle(sf::Vector2f& origin, sf::Vector2f& target,float angleAdjust = 90.f);

	float calculateLineDist(sf::Vector2f& origin, sf::Vector2f& target);
};