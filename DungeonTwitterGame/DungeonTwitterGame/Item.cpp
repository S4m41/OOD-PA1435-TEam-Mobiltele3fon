#include "Item.hpp"

Item::Item()
{
	m_info = ItemInfo();
}

Item::~Item()
{

}

ItemInfo Item::GetItemInfo() const
{
	return m_info;
}

ItemStats Item::GetItemStats() const
{
	return m_info.stats;
}

ItemEffect Item::GetItemEffect() const
{
	return m_info.effect;
}
