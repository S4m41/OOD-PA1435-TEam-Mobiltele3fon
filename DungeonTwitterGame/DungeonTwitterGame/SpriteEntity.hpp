#ifndef SPRITE_ENTITY_HPP
#define SPRITE_ENTITY_HPP
#include "Entity.hpp"

namespace sf
{
	class Texture;
	class Sprite;
	class RenderTarget;
	class RenderStates;
}

class SpriteEntity : public Entity
{
public:
	virtual ~SpriteEntity();
	
	void SetPosition(sf::Vector2f position) override;

	sf::Sprite* GetSprite();

protected:
	SpriteEntity(char* textureName);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::Texture* m_texture;
	sf::Sprite* m_sprite;
};

#endif