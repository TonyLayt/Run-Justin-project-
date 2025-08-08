#include "Enemy.h"

Enemy::Enemy()
{

	for (int countFrame = 0; countFrame < 6; ++countFrame) {

		sf::Texture addTexture;
		if (!addTexture.loadFromFile("img/zombieSprite/Zombie1/animation/Walk" + std::to_string(countFrame+1) + ".png")) {
			std::cout << "Error load texture" << std::endl;
		}
		texture.push_back(addTexture);
	}

	//enemySprite.setTexture(texture[0]);
	enemySprite.setScale(0.3f, 0.3f);

}

void Enemy::enemySpawn(int platformX, int platformY) // утановить точку для обекта зомби
{
    enemyX = platformX;
	enemyY = platformY;

	std::cout << "ForX " << platformX << std::endl;

	std::cout << "ForEnemyX " << enemyX << std::endl;

	enemyX -= movSpeed;

	// animation
	if (currentFrame >= texture.size())
	{
		currentFrame = 0;
	}

	enemySprite.setTexture(texture[currentFrame]);
	currentFrame += speedFrame;
	// ________

	if (enemyX + 300 > platformX && checkIF)
	{
		movSpeed++;
		enemySprite.setTextureRect(sf::IntRect(280, 5, -280, 370));
	}
	else { checkIF = false;}

	if (!checkIF && enemyX + 400 < platformX + 500)
	{
		enemySprite.setTextureRect(sf::IntRect(5, 5, 280, 370));
		movSpeed--;
	}
	else { checkIF = true; }

	enemyRect = sf::FloatRect(enemyX + 420, enemyY + 20, 50, 75);
}


void Enemy::enemyDraw(sf::RenderWindow& window)
{
    enemySprite.setPosition(enemyX + 400, enemyY);
    window.draw(enemySprite);
    //std::cout << "XUUUUU" << std::endl;


    rectShape.setPosition(enemyRect.left, enemyRect.top);
	rectShape.setSize(sf::Vector2f(enemyRect.width, enemyRect.height));
	rectShape.setFillColor(sf::Color::Transparent); // Прозрачный фон
	rectShape.setOutlineThickness(2); // Толщина границы
	rectShape.setOutlineColor(sf::Color::Blue); // Цвет границы

	window.draw(rectShape);
}
