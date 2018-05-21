#pragma once
#define DEF_OBSTACLE
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
class fusee;
class score;
#include "score.h"

class obstacle
{
public:

    obstacle();
    void dessiner(sf::RenderWindow *renderWindow);
    float getx();
    float gety();
    float getlargeur();
    float gettaille();
    sf::FloatRect getGlobalBounds();
    void chute();
    void checkColli(fusee *r1, sf::RenderWindow *renderWindow,score *life);


private:

    bool collision = false;
    int randpos;
    int impacte = 0;
    float hauteur = 0.15;
    float velocity =0;

    sf::Clock clock3;
    sf::Time chrono3;
    sf::Sprite SpriteObs;
    sf::Texture TextObs;
    sf::Music music;

};
