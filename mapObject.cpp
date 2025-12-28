#include "mapObject.h"

mapObject::mapObject(std::vector<Object> &conteinerObjct) : conteinerObjct(conteinerObjct)
{

    texture.loadFromFile("img/Tiles/spriteGround.png");

    for (int ch = 0; ch < conteinerObjct.size(); ch++)
    {
        PropertiMapTitle.textureX = conteinerObjct[ch].rect.left;
        PropertiMapTitle.textureY = conteinerObjct[ch].rect.top;
        PropertiMapTitle.spritObject.setPosition(PropertiMapTitle.textureX, PropertiMapTitle.textureY);
        PropertiMapTitle.spritObject.setTexture(texture);

        prop.push_back(PropertiMapTitle);
    }

    for (int countPl = 1; countPl < 3; countPl++)
    {
        conteinerObjct.push_back(conteinerObjct[0]);
        conteinerObjct[countPl].rect.left = 950 * countPl;

        prop.push_back(prop[0]);
        prop[countPl].spritObject.setPosition(conteinerObjct[countPl].rect.left, conteinerObjct[countPl].rect.top);
    }
};

void mapObject::processingMap(Player &upAnimationSpeed, float &vailSpeedBG)
{
    if (checkOpenProcessingMap)
    {
        gameClock.restart();
        checkOpenProcessingMap = false;
    }

    sf::Time elapsed = gameClock.getElapsedTime(); // сколько прошло с момента запуска
    float seconds = elapsed.asSeconds();           // в секундах (float)
    std::cout << "TIME_" << seconds << std::endl;

    if (seconds > timeLimit)
    {
        speed += 1;
        vailSpeedBG += 0.80f;
        timeLimit += 20;
        upAnimationSpeed.SetAnimationSpeed(0.01f);
        std::cout << "XYYSYSYSYSYS_ " << seconds << std::endl;
    }

    for (int itemCount = 0; itemCount < conteinerObjct.size(); itemCount++)
    {
        if (upAnimationSpeed.getCheckGemeOverEvents())
        {
            conteinerObjct[itemCount].rect.left -= speed;
            prop[itemCount].spritObject.setPosition(conteinerObjct[itemCount].rect.left, conteinerObjct[itemCount].rect.top);

            if (conteinerObjct[itemCount].rect.left + conteinerObjct[itemCount].rect.width + 300 < 0)
            {
                randPointSpavn = rand() % (3 - 1 + 1) + 1;
                numbPlatform = itemCount;
                conteinerObjct[itemCount].rect.left = 1800; // 1500
            }
        }
    }
}

void mapObject::showObject(sf::RenderWindow &window)
{
    for (auto &item : prop)
    {
        window.draw(item.spritObject);
    }
}

std::vector<Properti> &mapObject::getSpriteForObject()
{
    return prop;
}
