#include "GameStateManager.hpp"

GameStateManager::GameStateManager()
{
	m_currentStateIndex = nullptr;
}

GameStateManager::~GameStateManager()
{
	while (m_gameStates.begin() != m_gameStates.end())
	{
		delete m_gameStates[m_gameStates.begin()->first];
		m_gameStates[m_gameStates.begin()->first] = nullptr;
		m_gameStates.erase(m_gameStates.begin()->first);
	}

	m_gameStates.clear();

	if (m_currentStateIndex)
	{
		delete m_currentStateIndex;
		m_currentStateIndex = nullptr;
	}
}

void GameStateManager::Update()
{
	// Switch gamestate
	//switch (m_gameStates[*m_currentStateIndex]->GetNextState())
	//{
	//case GameState::State::PlayState:
	//	*m_currentStateIndex = typeid(GamePlayState);
	//	break;
	//case GameState::GameStateType::GameMainMenu:
	//	*m_currentStateIndex = typeid(GamePlayState);
	//	break;
	//case GameState::GameStateType::GamePauseMenu:
	//	*m_currentStateIndex = typeid(GamePlayState);
	//	break;
	//default:
	//	break;
	//}
	//
	//m_gameStates[*m_currentStateIndex]->Update();
}