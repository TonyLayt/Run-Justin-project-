#include "lvlMap.h"
#include "Player.h"
#include <iostream>
#include <SFML\Graphics.hpp>


lvlMap::lvlMap() {

	for (int countFrame = 1; countFrame < 7; ++countFrame) {

		sf::Texture addTextureInactivit;
				if (!addTextureInactivit.loadFromFile("img/Tiles/Tile (" + std::to_string(countFrame) + ").png")) {
					std::cout << "Error load texture" << std::endl;
				}
				arrTiles.push_back(addTextureInactivit);
	}

};

void lvlMap::fillingAndDrawMap(sf::RenderWindow& window, Player& player) {

    std::cout << "player.rect.left = " << player.plySprite.getPosition().y << std::endl;

    std::cout << "player.rect.height = " << player.plySprite.getGlobalBounds().height << std::endl;
    std::cout << "player.rect.width = " << player.plySprite.getGlobalBounds().width << std::endl;

	for (int countIteration = 0; countIteration < HeightMap; countIteration++) {
		for (int countFillTexture = 0; countFillTexture < WidthMap; countFillTexture++) {

			if (TileMap[countIteration][countFillTexture] == ' ') continue;
			if (TileMap[countIteration][countFillTexture] == '0') continue;
			if (TileMap[countIteration][countFillTexture] == '2') objectTitleSprite.setTexture(arrTiles[1]);
			if (TileMap[countIteration][countFillTexture] == '1') objectTitleSprite.setTexture(arrTiles[0]);
			if (TileMap[countIteration][countFillTexture] == '3') objectTitleSprite.setTexture(arrTiles[2]);
			if (TileMap[countIteration][countFillTexture] == '4') objectTitleSprite.setTexture(arrTiles[3]);
			if (TileMap[countIteration][countFillTexture] == '5') objectTitleSprite.setTexture(arrTiles[4]);
			if (TileMap[countIteration][countFillTexture] == '6') objectTitleSprite.setTexture(arrTiles[5]);

			objectTitleSprite.setPosition(countFillTexture * 32, countIteration * 32);

			if (objectTitleSprite.getGlobalBounds().intersects(player.plySprite.getGlobalBounds())){
                    std::cout << "Trogaet" << std::endl;

                    if (TileMap[countIteration][countFillTexture] == '2') {

                        if (player.plySprite.getPosition().y < 608){
                                std::cout << "Worck!!!!!!!!!!!!!!!!!" << std::endl;
                                player.onGround = true;
                                player.plySprite.setPosition(player.plySprite.getPosition().x, 550);
                        }

                    }

                    else if (TileMap[countIteration][countFillTexture] == '5') {

                        if (player.plySprite.getPosition().y < 416){
                                std::cout << "Worck!!!!!!!!!!!!!!!!!" << std::endl;
                                player.onGround = true;
                                player.plySprite.setPosition(player.plySprite.getPosition().x, 356);
                        }

                        if (player.plySprite.getPosition().y > 416 && !player.onGround){
                                std::cout << "Worck!!!!!!!!!!!!!!!!!" << std::endl;
                                player.verticalVelocity = 0.0f;
                                //player.plySprite.setPosition(player.plySprite.getPosition().x, 416);
                        }

                    } else player.onGround = false;
			}

			window.draw(objectTitleSprite);
		}
	}
};


//void lvlMap::interactiveMap (Player& player){
//
//
//    std::cout << "player.rect.left = " << player.plySprite.getPosition().y << std::endl;
//
//    std::cout << "player.rect.height = " << player.plySprite.getGlobalBounds().height << std::endl;
//    std::cout << "player.rect.width = " << player.plySprite.getGlobalBounds().width << std::endl;
//
//    for (int titleIteration = player.plySprite.getPosition().y/32; titleIteration < (player.plySprite.getPosition().y + player.plySprite.getGlobalBounds().height - 75)/32; titleIteration++) {
//        for (int titleIterationTwo = player.plySprite.getPosition().x/32; titleIterationTwo < (player.plySprite.getPosition().x + player.plySprite.getGlobalBounds().width)/32; titleIterationTwo++) {
//
//                if (titleIteration >= 0 && titleIteration < HeightMap && titleIterationTwo >= 0 && titleIterationTwo < WidthMap){
//
//                    if (TileMap[titleIteration][titleIterationTwo] == '2'){
//                            std::cout << "touch me : )" << objectTitleSprite.getPosition().y << std::endl;
//
//                            player.onGround = true;
//                            if (player.onGround) {player.plySprite.setPosition(player.plySprite.getPosition().x, objectTitleSprite.getPosition().y - 58);}
////                            player.plySprite.setPosition(player.plySprite.getPosition().x, 550);
//                    }
//
//                    else if (TileMap[titleIteration][titleIterationTwo] == '5'){
//
//
//                            if (358 <= player.plySprite.getPosition().y) {
//
//                                std::cout << "Worck!!!!!!!!!!!!!!!!!" << titleIteration << std::endl;
//                                player.verticalVelocity = 15.0f;
//
//                            }
//
//                            player.onGround = true;
//                            if (player.onGround) {player.plySprite.setPosition(player.plySprite.getPosition().x, 416 - 58);}
//
//                    }else player.onGround = false;
//                }
//        }
//    }
//}



