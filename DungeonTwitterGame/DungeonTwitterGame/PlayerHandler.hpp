#ifndef PLAYER_HANDLER_HPP
#define PLAYER_HANDLER_HPP
#include <SFML\Graphics\Drawable.hpp>

class Input;
class Player;

class PlayerHandler final : public sf::Drawable
{
public:
	PlayerHandler();
	~PlayerHandler();

	void SetInput(Input* input);

	void CreatePlayer();

	void Update();

	sf::Vector2f GetPlayerPosition() const;
	Player* GetPlayer() const;

private:
	Player* m_player;
	Input* m_input;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif