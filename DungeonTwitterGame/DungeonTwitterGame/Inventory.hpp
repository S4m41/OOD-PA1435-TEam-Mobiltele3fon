#pragma once
#include "Item.hpp"
class Inventory
{
public:
	Inventory();
	~Inventory();
	bool addItem(Item* itemToAdd);
	/*disowns item caller beware!, 
	only checks pointer not object, removes first pointer encoutered not caring for duplicates
	returns false if no item in slot */
	bool dropItem(Item* itemToDrop);
	//disowns item caller beware!, returns false if no item in slot 
	bool dropItem(int slotID);
	Item* itemInSlot(int slotID);
protected:
private:
	bool isSlotEmpty(int slotID);
	//erases the item on slotID, no delete on item called!! returns false if empty
	bool removeItem(int slotID);

	Item** items;//storebetter
	//expand container
	bool expand();
	struct 
	{
		int vectormax = 10;
		int _INCREMENT = 5;
	}Storageinfo;//överflödigt? till information om items arrayen
};

