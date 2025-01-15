#include "camera.h"

sf::View view;

sf::View playecCordFORView(float x, float y)
{
	float tempY = y;
	float tempX = x;

	if (y > 320) tempY = 320;
	if (y < 320) tempY = 320;
	//if (x < 380) tempX = 380;
	//if (x > 1150) tempX = 1150;

	view.setCenter(tempX+350, tempY);

	return sf::View();
}


