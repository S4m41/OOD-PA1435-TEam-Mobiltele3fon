#ifndef SYSTEM_HPP
#define SYSTEM_HPP
#include <memory>
#include <SFML\Graphics.hpp>
#include "Input.hpp"
#include "GameState.hpp"

class System final
{
public:
	System();
	~System();

	bool Initialize();
	void Run();

private:
	std::unique_ptr<sf::RenderWindow> m_window;
	std::unique_ptr<Input> m_input;
	std::unique_ptr<State> m_currentState;

	void UpdateCurrentState();
};

#endif