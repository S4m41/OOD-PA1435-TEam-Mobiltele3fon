#include "Inventory.hpp"



Inventory::Inventory()
{
	items = new Item*[Storageinfo.vectormax];
	for (int i = 0; i < Storageinfo.vectormax; i++) {
		items[i] = nullptr;
	}
}


Inventory::~Inventory()
{
	for (int i = 0; i < Storageinfo.vectormax; i++) {
		delete items[i];
	}
	delete items;
}

int Inventory::addItem(Item * itemToAdd)
{
	int index = -1;//default value

	int i = 0;
	for (; items[i] != nullptr; i++) {
		if (i < Storageinfo.vectormax) {
			if (!expand()) {
				index = -2;//cant expand
			}
			i++;
			break;
		}
	}

	if (!isSlotEmpty(i) || index < -1)//dont add to full slot or when container fails
		index = -1;
	else {
		items[i] = itemToAdd;
		index = i;
	}
	return index;
}

bool Inventory::dropItem(Item * itemToDrop)
{
	for (int i = 0; i < Storageinfo.vectormax; i++) {
		if (itemToDrop == items[i]) {
			return dropItem(i);
		}
	}
	return false;
}

bool Inventory::dropItem(int slotID)
{
	bool succsess = false;
	succsess = removeItem(slotID);
	return succsess;
}

Item * Inventory::itemInSlot(int slotID)
{
	if (isSlotEmpty(slotID))
		return nullptr;
	return items[slotID];
}

bool Inventory::isSlotEmpty(int slotID)
{
	if (slotID > Storageinfo.vectormax)
		return true;
	if (items[slotID] == nullptr)
		return true;
	return false;
}

bool Inventory::removeItem(int slotID)//call delete?
{
	if (isSlotEmpty(slotID))
		return false;

	items[slotID] = nullptr;

	if (isSlotEmpty(slotID))
		return true;
	return false;

}

bool Inventory::expand()//expand container, no failure route throw perhaps? 
{
	Item** items_new = new Item*[Storageinfo.vectormax];
	int i = 0;
	for (; i < Storageinfo.vectormax; i++) {
		items_new[i] = items[i];
	}
	for (; i < Storageinfo._INCREMENT + Storageinfo.vectormax; i++) {
		items_new[i] = nullptr;
	}
	Storageinfo.vectormax += Storageinfo._INCREMENT;
	delete items;
	items = items_new;
	return true;
}
