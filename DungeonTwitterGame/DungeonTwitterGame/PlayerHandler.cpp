#include "PlayerHandler.hpp"
#include "Player.hpp"
#include "Input.hpp"
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>

PlayerHandler::PlayerHandler()
{
	m_player = nullptr;
}
PlayerHandler::~PlayerHandler()
{
	if (m_player)
	{
		delete m_player;
		m_player = nullptr;
	}
}

void PlayerHandler::SetInput(Input* input)
{
	m_input = input;
}

void PlayerHandler::CreatePlayer()
{
	if (m_player)
		return;
	m_player = new Player(true);
}

void PlayerHandler::Update()
{
	if (m_player)
	{
		if (m_input->IsKeyDown(sf::Keyboard::Key::W))
			m_player->SetMoveUp();
		if (m_input->IsKeyDown(sf::Keyboard::Key::S))
			m_player->SetMoveDown();
		if (m_input->IsKeyDown(sf::Keyboard::Key::D))
			m_player->SetMoveRight();
		if (m_input->IsKeyDown(sf::Keyboard::Key::A))
			m_player->SetMoveLeft();

		m_player->Update();
	}
}

sf::Vector2f PlayerHandler::GetPlayerPosition() const
{
	return m_player ? m_player->GetPosition() : sf::Vector2f(0, 0);
}

void PlayerHandler::SetPlayerPosition(sf::Vector2f position) const
{
	m_player->SetPosition(position);
}


Player* PlayerHandler::GetPlayer() const
{
	return m_player;
}

void PlayerHandler::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (m_player)
	{
		target.draw(*m_player, states);
	}
}