#include "backGround .h"

backGround ::backGround ()
{
    texture.loadFromFile("img/backGroundSprite/BG.png");

    sprite.setTexture(texture);
    sprite.scale(0.5f, 0.5f);
    sprite.setPosition(-50, 0);

}

void backGround ::DrawBG (sf::RenderWindow& window){

    window.draw(sprite);

}
