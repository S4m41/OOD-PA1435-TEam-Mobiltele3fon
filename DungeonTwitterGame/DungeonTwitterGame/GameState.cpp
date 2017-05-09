#include "GameState.hpp"
#include <SFML\Window.hpp>

GameState::GameState() : State()
{
}

GameState::~GameState()
{
}

bool GameState::Initialize()
{
	return true;
}

void GameState::ProcessKeyDown(int i)
{

}

void GameState::ProcessKeyPressed(int i)
{
}

void GameState::UpdateObserver(int keyIndex)
{
	switch (keyIndex)
	{
	case sf::Keyboard::W:
		// Move forward
		break;
	case sf::Keyboard::S:
		// Move back
		break;
	case sf::Keyboard::D:
		// Move right
		break;
	case sf::Keyboard::A:
		// Move left
		break;
	}
}