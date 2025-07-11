#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

struct ObjectDecor
{
public:

	ObjectDecor(Texture& textureFile);

	Sprite sprite;

private:

};


class ProcessingSpawnObject {

public:
	ProcessingSpawnObject();

	void respDecore (int x, int y);

	void DrawDecore(sf::RenderWindow& window);

private:
    int randPointBrush = 60;
    int randPointTree = 160;
    int randSpawnFirst = 0;
    int randSpawnSecond = 0;

	vector <ObjectDecor> objectDecors;
    Texture addTexture[4];
    vector <Texture> texture;
};
