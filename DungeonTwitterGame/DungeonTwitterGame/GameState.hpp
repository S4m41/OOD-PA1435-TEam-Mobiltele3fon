#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP
#include "Input.hpp"
#include "FiniteStateMachine.hpp"
#include <memory>
#include <SFML\Graphics\Drawable.hpp>

class GameState : public sf::Drawable
{
public:
	GameState(FiniteStateMachine* fsm);
	virtual ~GameState();

	virtual bool Initialize() = 0;
	virtual void Update() = 0;
	void SetInput(std::shared_ptr<Input> input);

protected:
	std::shared_ptr<Input> m_input;
	FiniteStateMachine* m_FSM;

	virtual void ProcessInput() = 0;
};

#endif