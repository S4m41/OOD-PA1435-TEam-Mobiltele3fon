#ifndef INPUT_HPP
#define INPUT_HPP
#include <SFML\Window.hpp>
#include "ObserverPattern.hpp"

class Input final : public Subject
{
public:
	Input();
	~Input();

	void UpdatePreviousKeys();

	void KeyDown(int index);
	void KeyUp(int index);

	bool IsKeyDown(int index) const;
	bool IsKeyPressed(int index) const;

private:
	bool m_keys[101];			// Highest index is KeyCount at 101 (Lowest is Unknown at -1, but ignored for now)
	bool m_keysPrevious[101];

	void UpdateObserversSpecific();
};

#endif