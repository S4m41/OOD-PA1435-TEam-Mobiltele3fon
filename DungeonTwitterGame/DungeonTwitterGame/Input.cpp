#include "Input.hpp"
#include <SFML\Window\Keyboard.hpp>

Input::Input()
{
	for (int i = 0; i < 101; i++)
	{
		m_keys[i] = m_keysPrevious[i] = false;
	}
}
Input::~Input()
{
}

void Input::Update()
{
	for (int i = 0; i < NR_OF_KEYS; i++)
	{
		m_keysPrevious[i] = m_keys[i];
		m_keys[i] = sf::Keyboard::isKeyPressed(sf::Keyboard::Key(i));
	}
}

bool Input::IsKeyDown(int key) const
{
	return m_keys[key];
}
bool Input::IsKeyPressed(int key) const
{
	return (m_keys[key] && !m_keysPrevious[key]);
}