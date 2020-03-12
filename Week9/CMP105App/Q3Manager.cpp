#include "Q3Manager.h"

//Create another Manager class. This class should handle 40 sprites. These sprites should spawn just outside 
//the top of the window with a random x - axis position(between the left and rightedges of the window).
//The sprites should move downwards and be killed when they pass the bottom of the window.The sprites should spawn on key press, 
//similar to the example. Have output text on thescreen that shows the current number of alive entities being rendered.

Q3Manager::Q3Manager()
{
	texture.loadFromFile("gfx/Beach_Ball.png");
	for (int i = 0; i < 40; i++)
	{
		balls.push_back(Ball());
		balls[i].setAlive(false);
		balls[i].setTexture(&texture);
		balls[i].setSize(sf::Vector2f(100, 100));
	}
}

Q3Manager::~Q3Manager()
{
}

void Q3Manager::spawn()
{
	int countAlive = 0;

	for (int i = 0; i < balls.size(); i++)
	{
		if (!balls[i].isAlive())
		{
			balls[i].setAlive(true);
			balls[i].setVelocity(0, 100);
			balls[i].setPosition(rand() % 1000, -100);
			std::cout << balls.size() << std::endl;
			return;
		}
		else
		{
			countAlive++;
		}

		if (countAlive == balls.size())
		{
			balls.resize(balls.size());

			balls.push_back(Ball());
			balls[balls.size() - 1].setAlive(false);
			balls[balls.size() - 1].setTexture(&texture);
			balls[balls.size() - 1].setSize(sf::Vector2f(100, 100));
		}
	}
}

void Q3Manager::update(float dt)
{
	// call update on all ALIVE balls
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			balls[i].update(dt);
		}
	}
	deathCheck();
}

void Q3Manager::deathCheck()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			if (balls[i].getPosition().y > 600)
			{
				balls[i].setAlive(false);
			}
		}
	}
}

void Q3Manager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			window->draw(balls[i]);
		}
	}
}
