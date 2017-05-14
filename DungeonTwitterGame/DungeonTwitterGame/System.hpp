#ifndef SYSTEM_HPP
#define SYSTEM_HPP

class Input;
class FiniteStateMachine;
namespace sf
{
	class RenderWindow;
}

class System final
{
public:
	System();
	~System();

	bool Initialize();
	void Run();

private:
	sf::RenderWindow* m_window;
	Input* m_input;
	FiniteStateMachine* m_FSM;
};

#endif