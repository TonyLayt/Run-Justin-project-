#include <iostream>
#include "Player.h"


Player::Player(float setPosX, float setPosY, std::vector<Object>& objs) : objs(objs) {
	view.reset(sf::FloatRect(0, 0, 960, 640));

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

	playerRect = sf::FloatRect (setPosX, setPosY, 50, 110);

	plySprite.setScale(0.3f, 0.3f);
	plySprite.setTexture(inactivitFrames[0]);
	plySprite.setOrigin(plySprite.getLocalBounds().width / 2, plySprite.getLocalBounds().height / 2);
};

void Player::update()
{
	onGround = false;

	playerRect.left += goX;
	collision(false); // �������� �� X

	// ���������� ����� �� Y
	if (!onGround) goY += 0.4f;

	playerRect.top += goY;
	collision(true); // �������� �� ������

	// �������� � ������� ��������� (���� �� �������)
	if (inactivitAnimation)
	{
		if (currentFrame >= inactivitFrames.size())
		{
			currentFrame = 0;
		}
		plySprite.setTexture(inactivitFrames[currentFrame]);
		currentFrame += speedFrame;
		//std::cout << currentFrame << std::endl;
	}

	// �������� ��� ��������
	if (runAnimation)
	{
		inactivitAnimation = false;
		if (currentFrame >= runFrames.size())
		{
			currentFrame = 0;
		}
		plySprite.setTexture(runFrames[currentFrame]);
		plySprite.setTextureRect(sf::IntRect(5, 5, 400, 486));
		if (goX > 0)
		{
			plySprite.setTextureRect(sf::IntRect(5, 5, 400, 486));
		}
		if (goX < 0)
		{
			plySprite.setTextureRect(sf::IntRect(400, 5, -400, 486));
		}
		currentFrame += speedFrame;
	}else { inactivitAnimation = true; }

	if (jumpAnimation)
	{
		if (currentFrame >= jumpFrames.size())
		{
			currentFrame = 0;
		}
		plySprite.setTexture(jumpFrames[currentFrame]); // �������� ������
		currentFrame += speedFrame;
	} else { inactivitAnimation = true; }
	goX = 0;
}

void Player::collision(bool dir)
{
	bool touchGround = false;

	for (int countObject = 0; countObject < objs.size(); countObject++)
	{
		if (playerRect.intersects(sf::FloatRect(objs[countObject].rect)))
		{
			if (objs[countObject].name == "TerraCol")
			{
				if (goX == 0 && dir == false)
				{
					playerRect.left = objs[countObject].rect.left - playerRect.width;
				}

				if (goX < 0 && dir == false)
				{
					playerRect.left = objs[countObject].rect.left + objs[countObject].rect.width;
				}

				if (goY > 0 && dir == true)
				{
					playerRect.top = objs[countObject].rect.top - playerRect.height;
					goY = 0;
					onGround = true;
				}

				if (goY < 0 && dir == true) // �� ������ ���� ������ ��������
				{
					goY = 0;
				}
			}

		}

	}
}

int Player::playerDraw(sf::RenderWindow& window) {

	plySprite.setPosition(playerRect.left + 12, playerRect.top + 39);
	playecCordFORView(playerRect.left, playerRect.top);//������

	rectShape.setPosition(playerRect.left, playerRect.top);
	rectShape.setSize(sf::Vector2f(playerRect.width, playerRect.height));
	rectShape.setFillColor(sf::Color::Transparent); // ���������� ���
	rectShape.setOutlineThickness(2); // ������� �������
	rectShape.setOutlineColor(sf::Color::Red); // ���� �������

	//window.draw(rectShape);
	window.draw(plySprite);
	window.setView(view);

	return 0;
}

