#pragma once
#include "Player.h"
#include <SFML\Graphics.hpp>




class lvlMap {

public:

	bool pressRunButn = false;

	lvlMap();

	void fillingAndDrawMap(sf::RenderWindow& window, Player& player);
//	void interactiveMap (Player& player);


private:

	std::vector<sf::Texture> arrTiles;
	sf::Sprite objectTitleSprite;

	static const int HeightMap = 20;
	const int WidthMap = 40;

	sf::String TileMap[HeightMap] = {
	"0000000000000000000000000000000000000000",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0          4  5 5 5 5 5 5 6            0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"1222222222222222222222222222222222222223",
	};


};
