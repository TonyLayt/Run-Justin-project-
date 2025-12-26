#pragma once

#include <iostream>
#include "TestLoadTitleMap.h"
#include "Player.h"


struct Properti
{
	friend class mapObject;

	sf::Sprite spritObject;
private:
	float textureX;
	float textureY;
};

class mapObject
{
	public:
		mapObject(std::vector <Object>& conteinerObjct); // иннициализация

		void processingMap(Player& upAnimationSpeed, float& vailSpeedBG);
		void showObject(sf::RenderWindow& window); // берем готовый обект
		std::vector<Properti>& getSpriteForObject();

		int randPointSpavn;
		int numbPlatform;

	private:
		sf::Clock gameClock;
		bool checkOpenProcessingMap = true;
		int speed = 5;
		int timeLimit = 20;
	    //int coun = 1;
		Properti PropertiMapTitle;
		sf::Texture texture;
		//std::vector <sf::Texture> packTexturex;
		std::vector<Properti> prop;
		std::vector<Object>& conteinerObjct;
};
