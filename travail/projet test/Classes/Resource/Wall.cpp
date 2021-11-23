

#include "..\Header\Wall.hpp"

Wall::Wall() {
	point1.x = 0;
	point1.y = 0;
	point2.x = 0;
	point2.y = 200;
}
Wall::Wall(sf::Vector2f p1, sf::Vector2f p2) {
	point1.x = p1.x;
	point1.y = p1.y;
	point2.x = p2.x;
	point2.y = p2.y;
}

sf::Vector2f Wall::getPoint1() {
	return point1;
}

sf::Vector2f Wall::getPoint2() {
	return point2;
}