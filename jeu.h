#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "fusee.h"
#include "background.h"
#include "obstacle.h"
#include "score.h"
#include "piece.h"
#include "start.h"
#include "gameover.h"
#include "vie.h"
#include "boutique.h"
#include <time.h>
#include <math.h>
class jeux
{
public:

    jeux(sf::RenderWindow *renderWindow);
    bool decollage(sf::RenderWindow *renderWindow);
    bool controle(sf::RenderWindow *renderWindow);
    bool over(sf::RenderWindow *renderWindow);
    void reset();
    ~jeux();

private:

    bool etatdecollage = false;
    bool game_over = false;
    int i = 0;
    int j = 0;
    float difficulte = 5;
    float velocity = 0;
    float hauteur = 0.3;
    float randpop = 0;
    float randpop2 = 0;
    std::vector<obstacle*> tab;
    std::vector<vie*> life;
    std::vector<piece*> pieces;
    fusee* rocket;
    piece* gain;
    score* scoreboard;
    boutique* shop;
    gameover* fin;
    background* fond;
    sf::Clock clock;
    sf::Time chrono;
    sf::Clock clock2;
    sf::Time chrono2;
    sf::Clock clock3;
    sf::Time chrono3;

};
