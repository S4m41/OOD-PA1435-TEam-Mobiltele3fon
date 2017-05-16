#ifndef CHARACTER_HANDLER_HPP
#define CHARACTER_HANDLER_HPP
#include <SFML\Graphics\Drawable.hpp>

class Input;
class PlayerHandler;
class EnemyHandler;
class FightHandler;
class Player;

class CharacterHandler final : public sf::Drawable
{
public:
	CharacterHandler();
	~CharacterHandler();

	void SetInput(Input* input);

	void Update();

	void draw(sf::RenderTarget& target, sf::RenderStates) const override;

	Player* GetPlayer();
private:
	PlayerHandler* m_playerHandler;
	EnemyHandler* m_enemyHandler;
	FightHandler* m_fightHandler;
};

#endif