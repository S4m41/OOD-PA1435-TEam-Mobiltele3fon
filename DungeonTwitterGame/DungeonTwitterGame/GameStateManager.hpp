#ifndef GAMESTATEMANAGER_HPP
#define GAMESTATEMANAGER_HPP
#include "GamePlayState.hpp"
//#include "GamePauseMenuState.hpp"
//#include "GameMainMenuState.hpp"
#include <unordered_map>
#include <typeindex>

class GameStateManager final
{
public:
	GameStateManager();
	~GameStateManager();

	template<typename GameStateType> void AddState(std::shared_ptr<Input> input);
	template<typename GameStateType> void RemoveState();

	void Update();

private:
	std::unordered_map<std::type_index, GameState*> m_gameStates;
	std::type_index* m_currentStateIndex;		// No default constructor for type_index exists
};

template<typename GameStateType> void GameStateManager::AddState(std::shared_ptr<Input> input)
{
	// If no such game state exist, add and initialize it
	if (m_gameStates.find(typeid(GameStateType)) == m_gameStates.end())
	{
		m_gameStates[typeid(GameStateType)] = new GameStateType(input);
		m_gameStates[typeid(GameStateType)]->Initialize();

		// If it's the only state, set it as the current state
		if (m_gameStates.size() == 1)
		{
			m_currentStateIndex = new std::type_index(typeid(GameStateType));
		}
	}
}
template<typename GameStateType> void GameStateManager::RemoveState()
{
	m_gameStates.erase(typeid(GameStateType));
}

#endif