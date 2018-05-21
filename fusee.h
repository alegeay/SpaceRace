#pragma once
#include <iostream>
#define DEF_FUSEE
#include "background.h"
#include "obstacle.h"
#include "fusee.h"
#include <SFML/Graphics.hpp>
#include <vector>

class background;

class fusee
{
public:

    float angle;

    fusee();

    void init();
    void dessiner(sf::RenderWindow *renderWindow);
    void commandes();
    void decollage(background *fond,bool *etatdecollage);
    void deplacement(score *scoreboard);
    void set_vie();
    void reset();
    void fantome(int *impacte);
    void fantome();
    void neutre();
    float getx();
    float gety();
    float getlargeur();
    float gettaille();
    int get_vie();
    sf::FloatRect getGlobalBounds();
    void detachement();
    void detachement_core();
    ~fusee();

private:
    sf::Vector2f position;
    bool limite = false;
    bool limite2 = false;
    bool declenchement = false;
    bool declenchement2 = false;
    bool  deco = false;
    int i = 0;
    int life = 5;
    float hauteur = 360;
    sf::Sprite sprite;
    sf::Sprite Spritefairing;
    sf::Sprite Booster;
    sf::Sprite flamme;
    sf::Texture rocket;
    sf::Texture mainrocket;
    sf::Sprite  SpriteMainRocket;
    sf::Texture fairing;
    sf::Texture textflame;
    sf::Texture  textcore;
    sf::Texture  textboost;
    sf::Music separation;
    std::vector<sf::Texture*> textureliste;
    std::vector<sf::Sprite*> fire;
    std::vector<sf::Sprite*> falcon;
    int maxi = 8;
    int mini = 0;
    sf::Clock clock;
    sf::Time time1;
    sf::Clock clock2;
    sf::Time time2;
    int id = 0;
};
