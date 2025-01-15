#include <iostream>
#include "Player.h"
#include <SFML/Graphics.hpp>



Player::Player(int setPosX, int setPosY) {

	for (int countFrame = 0; countFrame < 9; ++countFrame) {

		sf::Texture addTextureInactivit;
		if (!addTextureInactivit.loadFromFile("img/playerSprite/Idle__00" + std::to_string(countFrame) + ".png")) {
			std::cout << "Error load texture" << std::endl;
		}
		inactivitFrames.push_back(addTextureInactivit);

		sf::Texture addTextureRun;
		if (!addTextureRun.loadFromFile("img/playerSprite/Run__00" + std::to_string(countFrame) + ".png")) {
			std::cout << "Error load texture" << std::endl;
		}
		runFrames.push_back(addTextureRun);

		sf::Texture addTextureJump;
		if (!addTextureJump.loadFromFile("img/playerSprite/Jump__00" + std::to_string(countFrame) + ".png")) {
			std::cout << "Error load texture" << std::endl;
		}
		jumpFrames.push_back(addTextureJump);
	}

	//playerRect = sf::FloatRect (setPosX, setPosY, 40, 58);

	plySprite.setPosition(setPosX, setPosY);
	plySprite.setScale(0.3f, 0.3f);

};

void Player::characterAnimationInactivit(bool chekAnimatioMuve) {

    if (!onGround) {
        verticalVelocity += gravity;
        plySprite.move(0, verticalVelocity);
    }

    if (plySprite.getPosition().y >= 650) {
        plySprite.setPosition(plySprite.getPosition().x, 650);
        onGround = true;
        verticalVelocity = 0.0f;
    }


    if (!chekAnimatioMuve && onGround){
        if (currentFrame >= inactivitFrames.size()) {
		currentFrame = 0;}

        //plySprite.setTextureRect(sf::IntRect(5, 5, 319, 486));
        plySprite.setTexture(inactivitFrames[currentFrame]);
        plySprite.setOrigin(plySprite.getLocalBounds().width / 2, plySprite.getLocalBounds().height / 2);

        //plySprite.move(10,0);
        currentFrame += speedFrame;
    }

};

void Player::runAnimation(bool directionsMove) {

	if (currentFrame >= runFrames.size()) {
		currentFrame = 0;
	}

	if (directionsMove == true) { plySprite.setScale(0.3f, 0.3f); plySprite.move(10, 0);
	}
	else { plySprite.setScale(-0.3f, 0.3f); plySprite.move(-10, 0);
	}

	plySprite.setTexture(runFrames[currentFrame]);
	plySprite.setTextureRect(sf::IntRect(5, 5, 400, 486));

	currentFrame += speedFrame;
};

void Player::jumpAnimation() {

	if (currentFrame >= jumpFrames.size()) {
		currentFrame = 0;
	}

    if (onGround) {
        verticalVelocity = -15.0f; // Начальная скорость прыжка
        onGround = false;
    }

    // Применяем гравитацию
    verticalVelocity += gravity;

    // Обновляем вертикальную позицию
    plySprite.move(0, verticalVelocity);

    if (plySprite.getPosition().y >= 650) {
        plySprite.setPosition(plySprite.getPosition().x, 650);
        onGround = true;
        verticalVelocity = 0.0f;
    }

	plySprite.setTexture(jumpFrames[currentFrame]);
	//plySprite.setTextureRect(sf::IntRect(5, 5, 400, 486));

	currentFrame += speedFrame;

};


int Player::playerDraw(sf::RenderWindow& window) {

	window.draw(plySprite);

	return 0;
};
