#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <SFML\Graphics\Drawable.hpp>

namespace sf
{
	class Color;
}

class Entity : public sf::Drawable
{
public:
	Entity(sf::Color color, float size = 20.0f);
	~Entity();

	virtual void Update() = 0;

	void SetPosition(sf::Vector2f position);
	sf::Vector2f GetPosition() const;
	float GetRadius() const;
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

protected:
	sf::Vector2f m_position;
	sf::Color* m_color;
	float m_radius;


};

#endif


