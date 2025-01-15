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

	void DrawDecore(sf::RenderWindow& window, int x, int y);
		
private:
	
	vector <ObjectDecor> objectDecors;
	Texture addTexture;
};