#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Entity.hpp"
//#include "Alternative.hpp"

class Weapon;
class HealthBar;
namespace sf
{
	class Color;
	class RectangleShape;
}

class Character : public Entity
{
public:
	virtual ~Character();

	//bool Hit(int damage);
	//bool TryMoveCharacter(sf::Vector2f* direction);
	//Alternative* Interact();//TODO change return type
	//Alternative SelectAlternative(Alternative* alternative);
	//void Die();//TODO remove this? should be in characterhandler

	void SetMovement(sf::Vector2f movement);
	void SetWalkingSpeed(float speed);
	void ChangeHealth(int health);

	void Update();

	sf::Vector2f GetMovement() const;
	float GetWalkingSpeed() const;
	int GetHealth() const;

	float GetRadius() const;

protected:
	Character(sf::Color color);

private:
	sf::Vector2f m_movement;
	float m_walkingSpeed;

	sf::Color* m_color;
	float m_radius;

	HealthBar* m_healthBar;
	Weapon* m_activeWeapon;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif