#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <SFML\Graphics\Drawable.hpp>
//#include "Alternative.hpp"

class HealthBar;
namespace sf
{
	class Color;
	class RectangleShape;
}

class Character : public sf::Drawable
{
public:
	virtual ~Character();

	virtual void Update();

	//bool Hit(int damage);
	//bool TryMoveCharacter(sf::Vector2f* direction);
	//Alternative* Interact();//TODO change return type
	//Alternative SelectAlternative(Alternative* alternative);
	//void Die();//TODO remove this? should be in characterhandler

	void SetPosition(sf::Vector2f position);
	void SetMovement(sf::Vector2f movement);
	void SetWalkingSpeed(float speed);
	void ChangeHealth(int health);

	sf::Vector2f GetPosition() const;
	sf::Vector2f GetMovement() const;
	float GetWalkingSpeed() const;
	int GetHealth() const;

protected:
	Character(sf::Color color);

private:
	sf::Vector2f m_position;
	sf::Vector2f m_movement;
	float m_walkingSpeed;

	int m_radius;

	sf::Color* m_color;
	HealthBar* m_healthBar;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif