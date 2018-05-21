#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include "jeu.h"

class start
{
public:

    start();
    bool lancement(sf::RenderWindow *renderWindow);


private:
    sf::Texture TextStart;
    sf::Texture bouton;
    sf::Sprite SpriteFond;
    sf::Sprite SpriteBouton;
    sf::Vector2i position_mouse;

};

