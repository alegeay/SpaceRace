#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class vie
{
public:

    vie(int i);
    void dessiner(sf::RenderWindow *renderWindow);
    void change();
    void changeup();

private:

    int i=1;
    sf::Sprite Spritevie;
    sf::Texture vietext;
    sf::Texture viegris;
};

