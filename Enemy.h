#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>


class Enemy {

public:
	Enemy();

	void enemySpawn(int x, int y);
	void enemyDraw(sf::RenderWindow& window);
	void kill(bool status);
	void reset(bool status);
    sf::FloatRect enemyRect;

private:
	int enemyX = 0;
	int enemyY = 0;
	int movSpeed = 3;
	bool checkStatusLife = false;
	bool checkIF = true;

	float currentFrame = 0;
	float speedFrame = 0.1;

	sf::Sprite enemySprite;
	std::vector<sf::Texture> texture;

	sf::RectangleShape rectShape;


};
