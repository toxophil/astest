#ifndef DEF_INVENTORY
#define INVENTORY

#include "..\Header\Item.hpp"
#include "Player.hpp"

#include <vector>


class Inventory : public Player
{
private :
	std::vector<Item> inventory
public:
	Inventory();
};


#endif
