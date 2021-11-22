

#include "..\Header\Map.hpp"
#include <vector>

Map::Map() {
	Wall wall1;
	sf::Vector2f p1, p2;
	p1.x = 0;
	p1.y = 0;
	p2.x = 200;
	p2.y = 0;
	Wall wall2(p1, p2);
	p1.y = 200;
	p2.y = 200;
	Wall wall3(p1, p2);
	p1.x = 200;
	p1.y = 0;
	Wall wall4(p1, p2);
	wallList.push_back(wall1);
	wallList.push_back(wall2);
	wallList.push_back(wall3);
	wallList.push_back(wall4);
}
std::vector<Wall> Map::getWallList() {
	return wallList;
}