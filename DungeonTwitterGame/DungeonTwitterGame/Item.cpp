#include "Item.hpp"
//#include <string>
//#include <SFML\Graphics\Texture.hpp>
//#include <SFML\Graphics\Sprite.hpp>
//#include <SFML\Graphics\RenderTarget.hpp>
//#include <SFML\Graphics\RenderStates.hpp>

//Item::Item()
//{
//	m_info = ItemInfo();
//}

Item::Item(char* textureName) : SpriteEntity(textureName)
{
	/*m_texture = new sf::Texture;
	m_texture->loadFromFile("Assets/" + std::string(textureName));
	m_sprite = new sf::Sprite(*m_texture);*/
}
Item::~Item()
{
	/*if (m_texture)
	{
		delete m_texture;
		m_texture = nullptr;
	}
	if (m_sprite)
	{
		delete m_sprite;
		m_sprite = nullptr;
	}*/
}
//
//sf::Sprite* Item::GetSprite() const
//{
//	return m_sprite;
//}
//
//void Item::draw(sf::RenderTarget& target, sf::RenderStates states) const
//{
//	target.draw(*m_sprite, states);
//}

//ItemInfo Item::GetItemInfo() const
//{
//	return m_info;
//}
//
//ItemStats Item::GetItemStats() const
//{
//	return m_info.stats;
//}
//
//ItemEffect Item::GetItemEffect() const
//{
//	return m_info.effect;
//}