#pragma once
#include "Item.hpp"
#include <vector>
class Inventory
{
public:
	Inventory();
	~Inventory();
protected:
private:
	bool isSlotEmpty(int slotID);
	bool removeItem(int slotID);
	std::vector<Item*> items;//storebetter

};

