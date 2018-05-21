#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
class gameover
{
public:
    gameover();
    void dessiner(sf::RenderWindow *renderWindow);
    void writescore(int hauteur);
    bool lancement(sf::RenderWindow *renderWindow,std::string scorefinal,int hauteur);
    ~gameover();

private :
    sf::Vector2i position_mouse;
    sf::Texture bouton;
    sf::Sprite SpriteBouton;
    sf::Music over;
    sf::Text text1;
    sf::Text text2;
    sf::Font font;
    std::string meilleurscore;
    sf::Texture gameovertext;
    sf::Sprite fondgameover;
};
