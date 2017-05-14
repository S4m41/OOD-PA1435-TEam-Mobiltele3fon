#pragma once
#include "Item.hpp"
class Inventory
{
public:
	Inventory();
	~Inventory();
	bool addItem(Item* itemToAdd);
	bool dropItem(Item* itemToDrop);
	Item* itemInSlot(int slotID);
protected:
private:
	bool isSlotEmpty(int slotID);
	bool removeItem(int slotID);
	(Item*)* items;//storebetter


	struct 
	{
		int vectormax = 10;
	}Storageinfo;//överflödigt? till information om items arrayen
};

