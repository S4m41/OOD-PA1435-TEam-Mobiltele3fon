#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Entity.hpp"

class Weapon;
class HealthBar;
class Inventory;
class Item;

namespace sf
{
	class Color;
	class RectangleShape;
}

class Character : public Entity
{
public:
	virtual ~Character();

	void SetMovement(sf::Vector2f movement);
	void SetWalkingSpeed(float speed);
	void ChangeHealth(int health);

	void Update();

	sf::Vector2f GetMovement() const;
	float GetWalkingSpeed() const;
	int GetHealth() const;

	float GetRadius() const;
	Weapon* GetActiveWeapon() const;
	bool Attack();

	bool GiveItem(Item* item);
	void SetActiveItem(int i);

protected:
	Character(sf::Color color,float speed=1.0f,bool isRanged=false);
	Inventory* m_inventory;

private:
	sf::Vector2f m_movement;
	float m_walkingSpeed;

	sf::Color* m_color;
	float m_radius;

	HealthBar* m_healthBar;

	int m_activeWeaponIndex;
	Weapon* m_activeWeapon;

	float m_timeSinceAttack;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif