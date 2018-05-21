#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class score;
#include "score.h"
#include <stdlib.h>

class background
{
public:

    background();
    void dessiner(sf::RenderWindow *renderWindow);
    void changement(score *scoreboard,sf::RenderWindow *renderWindow);
    void defilement();
    ~background();

private:
    sf::Sprite SpriteBack;
    sf::Sprite SpriteSpace;
    sf::Sprite SpriteTesla;
    sf::Texture Tesla;
    sf::Texture Textfond;
    sf::Texture Textfond2;
    sf::Texture Textfond3;
    float opacite = 255;
    sf::Clock clock;
    sf::Time time1;
    bool valid = false;



};

