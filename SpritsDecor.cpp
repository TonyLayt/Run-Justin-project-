#include "SpritsDecor.h"


ObjectDecor::ObjectDecor(Texture& textureFile)
{
	sprite.setTexture(textureFile);
	sprite.setScale(0.7f, 0.7f);
}


ProcessingSpawnObject::ProcessingSpawnObject()
{
    srand(time(0));

	addTexture[0].loadFromFile("img/objectsSpite/Bush_1.png");
	addTexture[1].loadFromFile("img/objectsSpite/Bush_2.png");
	addTexture[2].loadFromFile("img/objectsSpite/Bush_3.png");

	addTexture[3].loadFromFile("img/objectsSpite/Tree.png");

	for (int coun = 0; coun < 4; coun++){
        texture.push_back(addTexture[coun]);
	}

	ObjectDecor brush_1(texture[0]);
	brush_1.sprite.setPosition(-200, 0);
	objectDecors.push_back(brush_1);
	ObjectDecor brush_2(texture[1]);
	brush_2.sprite.setPosition(-200, 0);
	brush_2.sprite.scale(2.0f, 2.0f);
	objectDecors.push_back(brush_2);
	ObjectDecor brush_3(texture[2]);
	brush_3.sprite.setPosition(-200, 0);
	brush_3.sprite.scale(2.0f, 2.0f);
	objectDecors.push_back(brush_3);

	ObjectDecor tree(texture[3]);
	tree.sprite.setPosition(-250, 0);
	objectDecors.push_back(tree);

}

void ProcessingSpawnObject::respDecore (int x, int y)
{
    if (x + 760 < 0)
    {
        randPointBrush = rand() %  (560 - 60 + 1) + 60;
        randPointTree = rand() %  (560 - 60 + 1) + 60;
        randSpawnFirst = rand() % 5;
        randSpawnSecond = rand() % 5;
    }

    std::cout << "randSpawnFirst: " << randSpawnFirst << " " << "randSpawnSecond: " << randSpawnSecond << std::endl;
    if (randSpawnFirst==1)
    {
        objectDecors[0].sprite.setPosition(x + randPointBrush, y - 60); //brush
    }
    if (randSpawnSecond==2)
    {
        objectDecors[1].sprite.setPosition(x + randPointBrush, y - 70); //brush
    }
    if (randSpawnFirst==3)
    {
        objectDecors[2].sprite.setPosition(x + randPointBrush, y - 80); //brush
    }
    if (randSpawnSecond==4)
    {
        objectDecors[3].sprite.setPosition(x + randPointTree, y - 160); // tree
    }

}


void ProcessingSpawnObject::DrawDecore(sf::RenderWindow& window)
{
	for (int coun = 0; coun < objectDecors.size(); coun++) {

		window.draw(objectDecors[coun].sprite);

	}

}
