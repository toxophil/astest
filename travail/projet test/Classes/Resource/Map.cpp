

#include "..\Header\Map.hpp"
#include <vector>

Map::Map() {
	int64_t x, y, h, w;
	x = 0;
	y = 0;
	h = 200;
	w = 200;
	Wall wall1(x, y, h, w);
	x = 300;
	y = 0;
	Wall wall2(x, y, h, w);
	x = 0;
	y = 300;
	Wall wall3(x, y, h, w);
	x = 300;
	y = 300;
	Wall wall4(x, y, h, w);
	wallList.push_back(wall1);
	wallList.push_back(wall2);
	wallList.push_back(wall3);
	wallList.push_back(wall4);
}
std::vector<Wall> Map::getWallList() {
	return wallList;
}