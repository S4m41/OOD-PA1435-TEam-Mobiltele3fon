#ifndef CHARACTER_HANDLER_HPP
#define CHARACTER_HANDLER_HPP
#include <vector>
#include <SFML\Graphics\Drawable.hpp>

class Input;
class Character;

class CharacterHandler final : public sf::Drawable
{
public:
	CharacterHandler();
	~CharacterHandler();

	void SetInput(Input* input);

	void AddPlayer();
	void AddEnemy();

	void Update();

	void draw(sf::RenderTarget& target, sf::RenderStates) const override;

private:
	std::vector<Character*> m_characters;
	Input* m_input;
};

#endif