#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <SFML\Graphics\Drawable.hpp>

namespace sf
{
	class Sprite;
	class Texture;
}

class Entity : public sf::Drawable
{
public:
	Entity();
	~Entity();

	virtual void Update() = 0;

	virtual void SetPosition(sf::Vector2f position);
	sf::Vector2f GetPosition() const;

protected:
	sf::Vector2f m_position;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;
};

#endif