#include "GameState.hpp"

GameState::GameState(FiniteStateMachine* fsm)
{
	m_FSM = fsm;
}
GameState::~GameState()
{

}

void GameState::SetInput(Input* input)
{
	m_input = input;
}