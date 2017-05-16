#include "Character.hpp"
#include "HealthBar.hpp"
#include "Weapon.hpp"
#include <SFML\Graphics\Color.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>
#include <SFML\Graphics\CircleShape.hpp>
#include <string>

Character::Character(sf::Color color,float speed,bool isRanged) : Entity()
{
	m_movement = sf::Vector2f(0.0f, 0.0f);
	m_color = new sf::Color(color);

	if (color == sf::Color::Cyan)
	{
		m_radius = 20.0f;
		m_walkingSpeed = 5.0f;
	}
	else
	{
		m_radius = 15.0f;
		m_walkingSpeed = speed;
	}

	m_healthBar = new HealthBar(m_radius * 2);
	if (isRanged) {
		m_activeWeapon = new Weapon("Bow.png");
	}
	else {
		m_activeWeapon = new Weapon("Axe.png");
	}
	m_timeSinceAttack = 0;
}
Character::~Character()
{
	if (m_color)
	{
		delete m_color;
		m_color = nullptr;
	}
	if (m_healthBar)
	{
		delete m_healthBar;
		m_healthBar = nullptr;
	}
	if (m_activeWeapon)
	{
		delete m_activeWeapon;
		m_activeWeapon = nullptr;
	}
}

void Character::Update()
{
	m_position += m_movement * m_walkingSpeed;

	m_healthBar->SetPosition(m_position);

	m_activeWeapon->GetSprite()->setPosition(m_position);
	m_timeSinceAttack += 0.1f;
	// Reset movement
	m_movement = sf::Vector2f(0.0f, 0.0f);
}

void Character::SetMovement(sf::Vector2f movement)
{
	m_movement = movement;
	float length = std::sqrtf(movement.x * movement.x + movement.y * movement.y);
	m_movement *= length > 0 ? 1 / length : 0;			// Normalize movement
}
void Character::SetWalkingSpeed(float speed)
{
	m_walkingSpeed = std::fmaxf(0.5f, speed);
}
void Character::ChangeHealth(int health)
{
	m_healthBar->ChangeHealth(health);
}

sf::Vector2f Character::GetMovement() const
{
	return m_movement;
}
float Character::GetWalkingSpeed() const
{
	return m_walkingSpeed;
}
int Character::GetHealth() const
{
	return m_healthBar->GetHealth();
}
float Character::GetRadius() const
{
	return m_radius;
}
Weapon* Character::GetActiveWeapon()const {
	return m_activeWeapon;
}
bool Character::Attack() {
	bool attackAllowed = false;
	if(((m_activeWeapon->GetWeaponType()&&m_activeWeapon->GetAmmunition()>0)||!m_activeWeapon->GetWeaponType())
		&& m_activeWeapon->GetCooldown() < m_timeSinceAttack) {
		m_timeSinceAttack --;
		attackAllowed = true;
		if (m_activeWeapon->GetWeaponType()) {
			m_activeWeapon->ChangeAmmunition();
		}
	}
	return attackAllowed;
}
void Character::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::CircleShape circle(m_radius);
	circle.setFillColor(*m_color);
	circle.setOrigin(m_radius, m_radius);
	circle.setPosition(m_position);
	target.draw(circle, states);

	if (m_activeWeapon)
		target.draw(*m_activeWeapon, states);

	target.draw(*m_healthBar, states);
}