#pragma once

#include <iostream>
#include "TestLoadTitleMap.h"

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

		void processingMap();
		void showObject(sf::RenderWindow& window); // берем готовый обект
		std::vector<Properti>& getSpriteForObject();

		int randPointSpavn;
		int numbPlatform;

	private:
	    //int coun = 1;
		Properti PropertiMapTitle;
		sf::Texture texture;
		//std::vector <sf::Texture> packTexturex;
		std::vector<Properti> prop;
		std::vector<Object>& conteinerObjct;
};
