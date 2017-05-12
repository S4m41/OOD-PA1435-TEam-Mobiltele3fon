#ifndef SYSTEM_HPP
#define SYSTEM_HPP
#include <memory>
#include <SFML\Graphics\RenderWindow.hpp>
#include "Input.hpp"
#include "GamePlayState.hpp"


class System final
{
public:
	System();
	~System();

	bool Initialize();
	void Run();

private:
	sf::RenderWindow* m_window;
	std::shared_ptr<Input> m_input;
	FiniteStateMachine m_FSM;
};

#endif