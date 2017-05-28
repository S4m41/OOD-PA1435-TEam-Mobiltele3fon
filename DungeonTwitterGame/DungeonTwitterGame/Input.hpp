#ifndef INPUT_HPP
#define INPUT_HPP
#include "ObserverPattern.hpp"

#define NR_OF_KEYS 101

class Input final : public Subject
{
public:
	Input();
	~Input();

	void Update();

	bool IsKeyDown(int key) const;
	bool IsKeyPressed(int key) const;

private:

	bool m_keys[NR_OF_KEYS];
	bool m_keysPrevious[NR_OF_KEYS];
};

#endif