#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "TestLoadTitleMap.h"
#include "camera.h"

//#include "mapObject.h"
#include "Enemy.h"

class Player {

public:
    bool onGround;
    float verticalVelocity = 0.0f;
	bool fif = false;
	float goX;
	float goY;
	float BoxPosX;
	float BoxPosY;
	

	bool inactivitAnimation = true;
	bool runAnimation;
	bool jumpAnimation;

    sf::Sprite plySprite;
    sf::FloatRect playerRect;

	sf::RectangleShape rectShape;
	sf::RectangleShape rectShapeEnemy;

	Player(float setPosX, float setPosY, std::vector<Object>& objs, std::vector<Enemy>& enemy);
	void SetAnimationSpeed(float newSpeed);
	void update();
	void collision(bool dir);
	bool getCheckGemeOverEvents();
	int playerDraw(sf::RenderWindow& window);

private:
	std::vector<sf::Texture> inactivitFrames;
	std::vector<sf::Texture> runFrames;
	std::vector<sf::Texture> jumpFrames;
	//std::vector<Properti> templMap;
	std::vector<Object>& objs;
	std::vector<Enemy>& enemy;
	bool GemeOverEvents = true;
	float currentFrame = 0;
	float speedFrame = 0.1f;
	const float gravity = 0;
};
