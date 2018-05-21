#include "obstacle.h"
using namespace std;
using namespace sf;

obstacle::obstacle()
{

    randpos = rand()%640; //Apparition random sur l'axe des x (de 0 à 640)
    TextObs.loadFromFile("images/ob1.png");

    SpriteObs.setTexture(TextObs); //Set de la texture ob1.png

    SpriteObs.setOrigin(sf::Vector2f(SpriteObs.getTexture()->getSize().x/2,SpriteObs.getTexture()->getSize().y/2 ));
    SpriteObs.setPosition(sf::Vector2f(randpos, 0));
    music.openFromFile("images/impact.ogg");
}

void obstacle::dessiner(sf::RenderWindow *renderWindow)
{
    renderWindow->draw(SpriteObs);// dessin de l'asteroide
}


void obstacle::chute()
{

    SpriteObs.move(0,hauteur); //baisse de la hauteur
}

float obstacle::getx()
{
    return SpriteObs.getPosition().x;
}

float obstacle::gety()
{

    return SpriteObs.getPosition().y;
}


float obstacle::getlargeur()
{

    return SpriteObs.getPosition().x;

}

float obstacle::gettaille()
{

    return SpriteObs.getPosition().y;

}


FloatRect obstacle::getGlobalBounds()
{

    return SpriteObs.getGlobalBounds();

}

void obstacle::checkColli(fusee *r1, sf::RenderWindow *renderWindow,score *life)
{


    if(r1->getGlobalBounds().intersects(this->getGlobalBounds()) && this->collision != true && life->getImpact() == 0)
    {
        this->collision = true;
        std::cout << "COLLISION" << endl;


        clock3.restart();
        life->setImpact();
        life->retire_vie();
        music.play();

    }

    else if(this->collision == false)
    {


        this->chute();

        this->dessiner(renderWindow);

    }
}



