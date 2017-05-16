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
	float GetRange() const;
	bool GetWeaponType()const;
	int GetAmmunition()const;
	void ChangeAmmunition(int change = -1);

private:
	int m_damage;
	float m_attackCooldown;
	float m_range;
	bool m_isRangedWeapon;
	int m_ammunition;
};

#endif