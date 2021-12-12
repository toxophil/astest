#include "..\Header\Inventory.hpp"
#include <vector>

Inventory::Inventory()
{
	_maxNbItems = 5;
}

void Inventory::setMaxNbItems(uint8_t nb) {
	_maxNbItems = nb;
}
uint8_t Inventory::getMaxNbItems() const {
	return _maxNbItems;
}

void Inventory::removeFromInventory(uint8_t index) {
	_inventory.erase(std::next(_inventory.begin()+index));
}
void Inventory::addToInventory(Item* item) {
	_inventory.push_back(item);
}

std::vector<Item*>& Inventory::getItems() {
	return _inventory;
}

Item*& Inventory::getItem(uint8_t index) {
	return _inventory[index];
}

void Inventory::clear() {
	_inventory.clear();
}