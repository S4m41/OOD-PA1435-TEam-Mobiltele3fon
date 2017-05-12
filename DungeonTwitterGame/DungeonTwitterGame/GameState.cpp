#include "GameState.hpp"

GameState::GameState(FiniteStateMachine* fsm)
{
	m_FSM = fsm;
}
GameState::~GameState()
{

}

void GameState::SetInput(std::shared_ptr<Input> input)
{
	m_input = input;
}

//void GameState::SetNextState(GameState::State nextState)
//{
//	m_nextState = nextState;
//}
//
//GameState::State GameState::GetNextState() const
//{
//	return m_nextState;
//}