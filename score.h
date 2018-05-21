#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <math.h>
#include <string>
#include "vie.h"
#include "fusee.h"
#include <math.h>

using std::string;

class score
{
public:

    score(sf::RenderWindow *renderWindow);
    void scoredraw(sf::RenderWindow *renderWindow);
    int get_hauteur();
    int faiblesse(int *impacte);
    int get_vie();
    int getImpact();
    float acceleration();
    void piecesdraw(sf::RenderWindow * renderWindow);
    void retire_vie();
    void setImpact();
    void RetImpact();
    string get_score();
    string convertTo(float sec);
    ~score();
    void setcompteur();
    void addvie();
    int getcompteur();
    int getvie();
    void depensecompteur(int prix);
private:

    string str;
    string view;
    string pcs;
    string cash;
    sf::Text pieces;
    int compteur = 150;
    int ptvie=5;
    float vitesse = 0.1;
    int hauteur;
    int impact = 0;
    sf::Texture ScoreFond;
    sf::Texture Cash;
    sf::Sprite SpriteScore;
    sf::Sprite SpriteCash;
    sf::Clock clock;
    sf::Time chrono;
    sf::Clock clock2;
    sf::Time time2;
    sf::Font font;
    sf::Text text1;

    std::vector<vie*> life;

};

