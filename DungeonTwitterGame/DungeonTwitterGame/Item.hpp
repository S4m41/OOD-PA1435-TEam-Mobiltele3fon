#ifndef ITEM_HPP
#define ITEM_HPP
//#include <SFML\Graphics\Drawable.hpp>
#include "SpriteEntity.hpp"

//enum ITEM_EFFECT_TYPE
//{
//	HEAL_EFFECT,
//};
//
//
//struct ItemStats
//{
//
//	ItemStats() {}
//};
//
//struct ItemEffect
//{
//	ITEM_EFFECT_TYPE type;
//	unsigned int value;
//
//	ItemEffect() : type(HEAL_EFFECT), value(0) {}
//};
//
//struct ItemInfo
//{
//	ItemStats stats;
//	ItemEffect effect;
//
//	ItemInfo() : stats(), effect() {}
//};

namespace sf
{
	class Sprite;
	class Texture;
}

class Item : public SpriteEntity//public sf::Drawable
{
public:
	virtual ~Item();

	/*ItemInfo GetItemInfo() const;
	ItemStats GetItemStats() const;
	ItemEffect GetItemEffect() const;*/

	//sf::Sprite* GetSprite() const;

protected:
	Item(char* textureName);

private:
	/*sf::Texture* m_texture;
	sf::Sprite* m_sprite;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;*/

	/*ItemInfo m_info;*/
};
#endif
