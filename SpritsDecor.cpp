#include "SpritsDecor.h"


ObjectDecor::ObjectDecor(Texture& textureFile)
{
	sprite.setTexture(textureFile);
	sprite.setScale(0.7f, 0.7f);
}


ProcessingSpawnObject::ProcessingSpawnObject()
{
	addTexture.loadFromFile("img/objectsSpite/Bush_1.png");

	ObjectDecor bush(addTexture);

	objectDecors.push_back(bush);
}

void ProcessingSpawnObject::DrawDecore(sf::RenderWindow& window, int x, int y)
{
	for (int coun = 0; coun < objectDecors.size(); coun++) {

		objectDecors[coun].sprite.setPosition(x + 60, y - 60);
		window.draw(objectDecors[coun].sprite);

	}
	
}
