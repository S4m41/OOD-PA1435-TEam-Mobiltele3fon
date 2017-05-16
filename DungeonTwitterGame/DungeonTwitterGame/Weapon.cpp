#include "Weapon.hpp"
#include <string>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>
#include <SFML\Graphics\Sprite.hpp>

Weapon::Weapon(char* textureName) : Item(textureName)
{
	if (textureName == "Axe.png")
	{
		m_damage = 10;
		m_attackCooldown = 1.0f;
		m_range = 3.0f;
		m_isRangedWeapon = false;
		GetSprite()->setOrigin(GetSprite()->getTextureRect().width * 0.5f, GetSprite()->getTextureRect().height);
		GetSprite()->setScale(0.2f, 0.1f);
		m_ammunition = 0;
	}
	else
	{
		m_damage = 10;
		m_attackCooldown = 1.0f;
		m_range = 2.0f;
		m_isRangedWeapon = true;
		m_ammunition = 50;
	}
}
Weapon::~Weapon()
{
}

int Weapon::GetDamage() const
{
	return m_damage;
}
float Weapon::GetCooldown() const
{
	return m_attackCooldown;
}
float Weapon::GetRange() const
{
	return m_range;
}
bool Weapon::GetWeaponType() const {
	return m_isRangedWeapon;
}
int Weapon::GetAmmunition()const {
	return m_ammunition;
}
void Weapon::ChangeAmmunition(int change) {
	m_ammunition += change;
}