#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "TestLoadTitleMap.h"
#include "SpritsDecor.h"

bool firstEnemy = true;
bool secondEnemy = false;

void permissionToRespawnOneEnemy(int checkNumbPlatform, int nambPlatform, int randPointSpavn) // разрешение на респ зомби 
{
    if (checkNumbPlatform == nambPlatform)
    {
        firstEnemy = false;
    }
    if (checkNumbPlatform == nambPlatform && randPointSpavn == nambPlatform)
    {
        firstEnemy = true;
    }
}
void permissionToRespawnSecondEnemy(int checkNumbPlatform, int nambPlatform, int randPointSpavn) // разрешение на респ зомби 
{
    if (checkNumbPlatform == nambPlatform)
    {
        secondEnemy = false;
    }
    if (checkNumbPlatform == nambPlatform && randPointSpavn == nambPlatform)
    {
        secondEnemy = true;
    }
}

int main()
{

    sf::RenderWindow window(sf::VideoMode(960, 640), "Noname Game");
    window.setFramerateLimit(60);

    Level level;
    level.LoadFromFile("MyMapp.tmx");
    std::vector<Object>& objectForMap = level.GetAllObjects();

    mapObject texturOnObject(objectForMap); // object for texture

    ProcessingSpawnObject createDecoreObjects;

    Player player(90, 450, objectForMap);

    Enemy zombie;
    std::vector<Enemy> entity;
    for(int enemyNamb = 0; enemyNamb < 2; enemyNamb++)
    {
        entity.push_back(zombie);
    }

    bool chekAnimatioMuve = false;

    while (window.isOpen())
    {

        
        texturOnObject.processingMap();
        std::cout << "RANDOMAZER: " << texturOnObject.randPointSpavn << std::endl;
       
        permissionToRespawnOneEnemy(texturOnObject.numbPlatform, 1, texturOnObject.randPointSpavn);
        permissionToRespawnSecondEnemy(texturOnObject.numbPlatform, 2, texturOnObject.randPointSpavn);

        if (firstEnemy)
        {
            entity[0].enemySpawn(objectForMap[1].rect.left, objectForMap[1].rect.top - objectForMap[1].rect.height - 30); // попробуй флагами определить направления
        }
        if (secondEnemy)
        {
            entity[1].enemySpawn(objectForMap[2].rect.left, objectForMap[2].rect.top - objectForMap[2].rect.height - 30); // попробуй флагами определить направления
        }
            
        
        player.update();
        sf::Event event;
        player.runAnimation = true;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            //player.runAnimation = true;
            player.goX += 10;
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            //player.runAnimation = true;
            player.goX -= 10;

        }else {player.runAnimation = true; chekAnimatioMuve = true;} // false, false


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            if (player.onGround)
            {
                player.jumpAnimation = true;
                player.goY -= 10;
            }
        } else { player.jumpAnimation = false; }

        window.clear();
        createDecoreObjects.DrawDecore(window, objectForMap[1].rect.left, objectForMap[1].rect.top); // set point
        level.Draw(window);
        texturOnObject.showObject(window);
        player.playerDraw(window);

        if (!entity.empty())
        {
            for (int item = 0; item < entity.size(); item++)
            {
                entity[item].enemyDraw(window);
            }            
        }
        else {std::cout << "!Empty!" << std::endl;}

        window.display();
    }

    return 0;
}
