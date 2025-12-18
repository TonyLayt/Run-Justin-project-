#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class backGround
{
    public:
        backGround ();

        void DrawBG (sf::RenderWindow& window);
        void speedBG(int speed);


    protected:

    private:
        int speed = 0;
        bool checkMovement = true;
        RectangleShape forTestSprite;
        Texture texture[7];
        vector <Sprite> segments;
};


