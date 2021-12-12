#include "..\Header\Item.hpp"
#include <vector>


class Inventory
{
private :
	uint8_t _maxNbItems;
	std::vector<Item*> _inventory;
public:
	Inventory();

	void setMaxNbItems(uint8_t);
	uint8_t getMaxNbItems() const;

	void removeFromInventory(uint8_t);
	void addToInventory(Item*);

	std::vector<Item*>& getItems();
	Item*& getItem(uint8_t index);

	void clear();
};

