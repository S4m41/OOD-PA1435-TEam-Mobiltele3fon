#ifndef ITEMENTITY_HPP
#define ITEMENTITY_HPP
#include "Entity.hpp"

class Item;
namespace sf
{
	class Sprite;
	class Texture;
}

class ItemEntity : public Entity
{
public:
	ItemEntity(Item* item);
	~ItemEntity();
	void Update() {};
	void SetPosition(sf::Vector2f position) override;

	Item* GetItem();
protected:
	Item* m_containedItem;
	sf::Texture* m_texture;
	sf::Sprite* m_sprite;

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
#endif


