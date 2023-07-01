#include "Utils.hpp"

float  Utils::calculateAngle(sf::Vector2f& origin, sf::Vector2f& target,float angleAdjust)
{
	return std::atan2f(origin.y - target.y, origin.x - target.x) * (180.f / PI) + angleAdjust;
}

float  Utils::calculateLineDist(sf::Vector2f& origin, sf::Vector2f& target)
{
	float dx = target.x - origin.x;
	float dy = target.y - origin.y;
	return std::sqrt(dx * dx + dy * dy);
}