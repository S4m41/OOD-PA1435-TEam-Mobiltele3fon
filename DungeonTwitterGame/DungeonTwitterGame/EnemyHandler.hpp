#ifndef ENEMY_HANDLER_HPP
#define ENEMY_HANDLER_HPP
#include <vector>
#include <SFML\Graphics\Drawable.hpp>

class Enemy;

class EnemyHandler final : public sf::Drawable
{
public:
	EnemyHandler();
	~EnemyHandler();

	void CreateEnemy();

	void Update();

	Enemy* GetEnemy(int i);
	int GetNrOfEnemies() const;

	void RemoveDeadEnemies();

private:
	std::vector<Enemy*> m_enemies;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif