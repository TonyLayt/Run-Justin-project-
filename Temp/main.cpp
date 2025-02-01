#include <SFML/Graphics.hpp>
#include "Player.h"
#include "lvlMap.h"



int main()
{

    sf::RenderWindow window(sf::VideoMode(950, 650), "Noname Game");
    window.setFramerateLimit(60);

    lvlMap map;
    Player player(90, 550);

    bool chekAnimatioMuve = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            chekAnimatioMuve = true;
            player.runAnimation(true);
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            chekAnimatioMuve = true;
            player.runAnimation(false);

        }else {chekAnimatioMuve = false;}

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            //std::cout << "Jump" << std::endl;
            chekAnimatioMuve = true;
            player.jumpAnimation();

        }

        player.characterAnimationInactivit(chekAnimatioMuve);
        //map.interactiveMap(player);


        window.clear();
        map.fillingAndDrawMap(window, player);
        player.playerDraw(window);
        window.display();
    }

    return 0;
}
