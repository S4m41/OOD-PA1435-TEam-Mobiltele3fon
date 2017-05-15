#ifndef WEAPON_HPP
#define WEAPON_HPP
#include "Item.hpp"

class Weapon : public Item
{
public:
	Weapon(char* textureName);
	virtual ~Weapon();

	int GetDamage() const;
	float GetCooldown() const;

private:
	int m_damage;
	float m_attackCooldown;
};

#endif