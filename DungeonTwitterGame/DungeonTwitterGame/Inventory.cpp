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
	bool ret = false;
	int i = 0;
	for (; items[i] != nullptr; i++) {
		if (i < Storageinfo.vectormax) {
			ret = ret||expand();
			i++;
			break;
		}
	}
		
	return ret;
}
