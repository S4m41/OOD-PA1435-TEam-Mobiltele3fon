#include "Input.hpp"

Input::Input()
{
	for (int i = 0; i < 101; i++)
	{
		m_keys[i] = false;
		m_keysPrevious[i] = false;
	}
}
Input::~Input()
{
}

void Input::UpdatePreviousKeys()
{
	for (int i = 0; i < 101; i++)
	{
		m_keysPrevious[i] = m_keys[i];
	}
}

void Input::KeyDown(int index)
{
	m_keys[index] = true;
}
void Input::KeyUp(int index)
{
	m_keys[index] = false;
}

bool Input::IsKeyDown(int index) const
{
	return m_keys[index];
}
bool Input::IsKeyPressed(int index) const
{
	return (m_keys[index] && !m_keysPrevious[index]);
}