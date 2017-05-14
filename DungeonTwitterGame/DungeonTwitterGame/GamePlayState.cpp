#include "GamePlayState.hpp"
#include "GamePauseMenuState.hpp"
#include "CharacterHandler.hpp"
#include "Input.hpp"
#include "FiniteStateMachine.hpp"
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Graphics\CircleShape.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>

GamePlayState::GamePlayState(FiniteStateMachine* fsm) : GameState(fsm)
{
	m_characterHandler = new CharacterHandler;
	m_characterHandler->AddPlayer();
}
GamePlayState::~GamePlayState()
{
	if (m_characterHandler)
	{
		delete m_characterHandler;
		m_characterHandler = nullptr;
	}
}

void GamePlayState::SetInput(Input* input)
{
	GameState::SetInput(input);
	m_characterHandler->SetInput(input);
}

//bool GamePlayState::Initialize()
//{
//	// Create entities and such
//	// ...
//	// ...
//	// ...
//	// ...
//	return true;
//}

void GamePlayState::Update()
{
	ProcessInput();

	m_characterHandler->Update();
}
void GamePlayState::ProcessInput()
{
	/*m_moveNorth = m_input->IsKeyDown(sf::Keyboard::W);
	m_moveEast = m_input->IsKeyDown(sf::Keyboard::D);
	m_moveSouth = m_input->IsKeyDown(sf::Keyboard::S);
	m_moveWest = m_input->IsKeyDown(sf::Keyboard::A);*/

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

	target.draw(*m_characterHandler, states);
}