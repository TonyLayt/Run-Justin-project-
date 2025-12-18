#include "TitleScreen.h"



TitleScreen::TitleScreen()
{
    textureForTitle.loadFromFile("img/TitleMain/titleMain.png");
    imageTitle.setTexture(textureForTitle);
    imageTitle.scale(0.66f, 0.66f);
    imageTitle.setPosition(-50, 0);

    textureButton.loadFromFile("img/TitleMain/StartButton.png");
    startButton.setTexture(textureButton);
    startButton.scale(0.2f, 0.2f);
    startButton.setPosition(50, 50);
}


void TitleScreen::DrawTitle (sf::RenderWindow& window)
{
    window.draw(imageTitle);
    window.draw(startButton);
}

Sprite TitleScreen::GetStartButton()
{
    return startButton;
}
