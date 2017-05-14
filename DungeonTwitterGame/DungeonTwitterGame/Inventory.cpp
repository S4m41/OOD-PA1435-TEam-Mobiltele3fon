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

bool Inventory::addItem(Item * itemToAdd)
{
	bool fail = false;
	int i = 0;
	for (; items[i] != nullptr; i++) {
		if (i < Storageinfo.vectormax) {
			fail = fail || !expand();
			i++;
			break;
		}
	}
	if (!isSlotEmpty(i))
		fail = fail || true;
	else
		items[i] = itemToAdd;
	return !fail;
}

bool Inventory::isSlotEmpty(int slotID)
{
	if (slotID> Storageinfo.vectormax)
		return true;
	if (items[slotID] == nullptr)
		return true;
	return false;
}

bool Inventory::expand()//expand
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
