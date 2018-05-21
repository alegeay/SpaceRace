#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include "score.h"
#include "fusee.h"
class boutique
{

public:

    boutique();
    void traitement(sf::RenderWindow *renderWindow,score *scoreboard,fusee *rocket);
    ~boutique();
    bool stopasteroide();
    void setflag();
    bool veriflag();


private:
    sf::Sprite SpriteBoutique;
    sf::Texture TextBoutique;
    sf::IntRect shop1;
    sf::Clock clock;
    sf::Time chrono;
    sf::Clock clock2;
    sf::Time chrono2;
    sf::Music depense;
    std::vector<sf::Texture*> panneau;
    sf::Vector2i position_mouse;
    bool flag = false;
    int i = 0;



};
