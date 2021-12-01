
/* Generated from GenMyModel */

#ifndef DEF_MAP
#define DEF_MAP

#include "Room.hpp"
#include "Wall.hpp"
#include <vector>

class Map
{
private :
	std::vector<Room> RoomList;
	std::vector<Wall> wallList;
public :
	std::vector<Wall> getWallList();
	Map();
};


#endif
