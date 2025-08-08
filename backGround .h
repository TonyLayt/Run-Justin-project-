#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class backGround
{
    public:
        backGround ();

        void DrawBG (sf::RenderWindow& window);


    protected:

    private:
        Sprite sprite;
        Texture texture;
};


