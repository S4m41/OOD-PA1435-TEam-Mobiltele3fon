#ifndef PLAYER_HANDLER_HPP
#define PLAYER_HANDLER_HPP
#include <SFML\Graphics\Drawable.hpp>

#include "ObserverPattern.hpp"

class Input;
class Player;

class PlayerHandler final : public sf::Drawable, public Observer
{
public:
	PlayerHandler();
	~PlayerHandler();

	//void SetInput(Input* input);

	void CreatePlayer();

	void Update();

	void Notify(Event* keyDownEvent) override;

	sf::Vector2f GetPlayerPosition() const;
	void SetPlayerPosition(sf::Vector2f position) const;
	Player* GetPlayer() const;

private:
	Player* m_player;
	//Input* m_input;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif