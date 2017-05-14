#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP
#include <SFML\Graphics\Drawable.hpp>

class Input;
class FiniteStateMachine;

class GameState : public sf::Drawable
{
public:
	GameState(FiniteStateMachine* fsm);
	virtual ~GameState();

	virtual void SetInput(Input* input);

	//virtual bool Initialize() = 0;
	virtual void Update() = 0;

protected:
	Input* m_input;
	FiniteStateMachine* m_FSM;

	virtual void ProcessInput() = 0;
};

#endif