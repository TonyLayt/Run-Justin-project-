#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Player {

public:
    bool onGround = false;
    float verticalVelocity = 0.0f;


    sf::Sprite plySprite;
    //sf::FloatRect playerRect;

	Player(int setPosX, int setPosY);
	void characterAnimationInactivit(bool directionsMove);
	void runAnimation(bool directionsMove);
	void jumpAnimation();
	int playerDraw(sf::RenderWindow& window);

private:
	std::vector<sf::Texture> inactivitFrames;
	std::vector<sf::Texture> runFrames;
	std::vector<sf::Texture> jumpFrames;
	float currentFrame = 0;
	float speedFrame = 0.2;

	const float gravity = 0.4f;
};
