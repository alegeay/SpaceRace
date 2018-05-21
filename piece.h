#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include "fusee.h"
#include "score.h"
class piece
{
public:


    piece();
    float getx();
    float gety();
    float getlargeur();
    float gettaille();
    void chute();
    void dessiner(sf::RenderWindow *renderWindow);
    void checkColli(fusee *r1, sf::RenderWindow *renderWindow, score *scoreboard);
    sf::FloatRect getGlobalBounds();

private:

    bool collision = false;
    int hauteur = 0;
    int randpos;
    int banque = 0;
    float angle;
    sf::Music music;
    sf::Sprite star;
    sf::Texture pieceFond;

};

