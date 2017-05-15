#ifndef ITEM_HPP
#define ITEM_HPP

enum ITEM_EFFECT_TYPE
{
	HEAL_EFFECT,
};


struct ItemStats
{

	ItemStats() {}
};

struct ItemEffect
{
	ITEM_EFFECT_TYPE type;
	unsigned int value;

	ItemEffect() : type(HEAL_EFFECT), value(0) {}
};

struct ItemInfo
{
	ItemStats stats;
	ItemEffect effect;

	ItemInfo() : stats(), effect() {}
};

class Item
{
public:
	Item();
	~Item();

	ItemInfo GetItemInfo() const;
	ItemStats GetItemStats() const;
	ItemEffect GetItemEffect() const;
private:
	ItemInfo m_info;

};
#endif // !ITEM_HPP
