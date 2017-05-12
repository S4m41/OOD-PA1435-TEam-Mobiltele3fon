#include <SFML\Window\Keyboard.hpp>
#include <SFML\Graphics\CircleShape.hpp>
#include "GamePlayState.hpp"
#include "GamePauseMenuState.hpp"

GamePlayState::GamePlayState(FiniteStateMachine* fsm) : GameState(fsm)
{
	m_moveNorth = m_moveEast = m_moveSouth = m_moveWest = false;
}
GamePlayState::~GamePlayState()
{
}

bool GamePlayState::Initialize()
{
	// Create entities and such
	// ...
	// ...
	// ...
	// ...
	return true;
}

void GamePlayState::Update()
{
	ProcessInput();
	// Movement and such
	// ...
	// ...
	// ...
	// ...


	// Reset movements
	m_moveNorth = m_moveEast = m_moveSouth = m_moveWest = false;
}
void GamePlayState::ProcessInput()
{
	m_moveNorth = m_input->IsKeyDown(sf::Keyboard::W);
	m_moveEast = m_input->IsKeyDown(sf::Keyboard::D);
	m_moveSouth = m_input->IsKeyDown(sf::Keyboard::S);
	m_moveWest = m_input->IsKeyDown(sf::Keyboard::A);

	if (m_input->IsKeyPressed(sf::Keyboard::Escape))
	{
		m_FSM->Push<GamePauseMenuState>();		// Enter pause state
		m_FSM->Peek()->SetInput(m_input);
	}
}

void GamePlayState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::CircleShape circle(100.0f);
	circle.setFillColor(sf::Color::Blue);
	target.draw(circle, states);
}