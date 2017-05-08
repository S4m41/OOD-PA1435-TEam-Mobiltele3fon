#include "GameState.hpp"
#include <SFML\Window.hpp>

GameState::GameState()
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
	switch (i)
	{
	case sf::Keyboard::W:
		// Move forward
		ProcessKeyPressed(i);
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

void GameState::ProcessKeyPressed(int i)
{
}

void GameState::Update()
{
}
