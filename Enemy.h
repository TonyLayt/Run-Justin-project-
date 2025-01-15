#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>


class Enemy {

public:
	Enemy();

	void enemySpawn(int x, int y);
	void enemyDraw(sf::RenderWindow& window);

private:
	int enemyX = enemyX;
	int enemyY = enemyY;
	int movSpeed = 3;

	bool checkIF = true;

	float currentFrame = 0;
	float speedFrame = 0.1;

	sf::FloatRect enemyRect;
	sf::Sprite enemySprite;
	std::vector<sf::Texture> texture;

};
