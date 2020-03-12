#pragma once
#include "BeachBallManager.h"

class Q3Manager : public BeachBallManager
{
public:
	Q3Manager();
	~Q3Manager();
	void spawn();
	void update(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);

private:
	std::vector<Ball> balls;
	sf::Vector2f spawnPoint;
	sf::Texture texture;
};