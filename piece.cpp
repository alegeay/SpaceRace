#include "piece.h"

using namespace std;
using namespace sf;

piece::piece()
{
    randpos = rand()%640; //Apparition random sur l'axe des x (de 0 à 640)
    pieceFond.loadFromFile("images/piece.png");
    music.openFromFile("images/gain.ogg");
    star.setTexture(pieceFond); //Set de la texture ob1.png

    star.setOrigin(sf::Vector2f(star.getTexture()->getSize().x/2,star.getTexture()->getSize().y/2 ));
    star.setPosition(sf::Vector2f(randpos, 0));
}

void piece::dessiner(sf::RenderWindow *renderWindow)
{
    renderWindow->draw(star);// dessin de l'asteroide
}

void piece::chute()
{
    star.move(0,0.1);   //baisse de la hauteur
}

float piece::getx()
{
    return star.getPosition().x;
}

float piece::gety()
{
    return star.getPosition().y;
}

float piece::getlargeur()
{
    return star.getPosition().x;
}

float piece::gettaille()
{
    return star.getPosition().y;
}

FloatRect piece::getGlobalBounds()
{
    return star.getGlobalBounds();
}


void piece::checkColli(fusee *r1, sf::RenderWindow *renderWindow, score *scoreboard)
{
    if(r1->getGlobalBounds().intersects(this->getGlobalBounds()) && this->collision != true)
    {
        this->collision = true;
        scoreboard->setcompteur();
        music.play();
    }

    else if(this->collision == false)
    {
        this->chute();
        this->dessiner(renderWindow);
    }

}



