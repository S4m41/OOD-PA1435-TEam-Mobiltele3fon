#include "CharacterHandler.hpp"
#include "Input.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>

CharacterHandler::CharacterHandler()
{
	m_input = nullptr;
}

CharacterHandler::~CharacterHandler()
{
	for (unsigned int i = 0; i < m_characters.size(); i++)
	{
		if (m_characters[i])
		{
			delete m_characters[i];
			m_characters[i] = nullptr;
		}
	}
}

void CharacterHandler::SetInput(Input* input)
{
	m_input = input;
}

void CharacterHandler::AddPlayer()
{
	if (!m_characters.empty())	// If player exists
		return;
	m_characters.push_back(new Player);
}

void CharacterHandler::AddEnemy()
{
	if (m_characters.empty())	// If no player exists
		return;
	m_characters.push_back(new Enemy);
}

void CharacterHandler::Update()
{
	if (m_characters[0])
	{
		Player* player = dynamic_cast<Player*>(m_characters[0]);

		if (m_input->IsKeyDown(sf::Keyboard::Key::W))
			player->SetMoveUp();
		if (m_input->IsKeyDown(sf::Keyboard::Key::S))
			player->SetMoveDown();
		if (m_input->IsKeyDown(sf::Keyboard::Key::D))
			player->SetMoveRight();
		if (m_input->IsKeyDown(sf::Keyboard::Key::A))
			player->SetMoveLeft();

		player->Update();
	}


	for (unsigned int i = 0; i < m_characters.size(); i++)
	{
		// Move towards player
		m_characters[i]->SetMovement(m_characters[0]->GetPosition() - m_characters[i]->GetPosition());
		m_characters[i]->Update();
	}
}

void CharacterHandler::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (unsigned int i = 0; i < m_characters.size(); i++)
	{
		target.draw(*m_characters[i], states);
	}
}