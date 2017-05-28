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

		if (m_keys[i])
		{
			KeyDownEvent kde(sf::Keyboard::Key(i), IsKeyPressed(i));
			NotifyObservers(&kde);
		}
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