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
		GetSprite()->setOrigin(GetSprite()->getTextureRect().width * 0.5f, GetSprite()->getTextureRect().height);
		GetSprite()->setScale(0.2f, 0.1f);
	}
	else
	{
		m_damage = 10;
		m_attackCooldown = 1.0f;
		m_range = 2.0f;
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