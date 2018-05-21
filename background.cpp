#include "background.h"

using namespace std;
using namespace sf;

//Chargement des textures du background
background::background()
{
    Textfond.loadFromFile("images/fond1.png");
    Textfond3.loadFromFile("images/fond3.jpg");
    Textfond2.loadFromFile("images/fond2.jpg");
    SpriteBack.setTexture(Textfond);
    SpriteSpace.setTexture(Textfond3);
    Tesla.loadFromFile("images/tesla.png");
    SpriteTesla.setTexture(Tesla);
    SpriteTesla.setPosition(0,500);
}

//Dessin des sprites
void background::dessiner(sf::RenderWindow *renderWindow)
{
    renderWindow->draw(SpriteSpace);
    renderWindow->draw(SpriteBack);
}

//Defilement des background
void background::defilement()
{
    this->SpriteBack.setTexture(Textfond2);
}

//Transition ciel -> espace au fil du temps / opacité
void background::changement(score *scoreboard,sf::RenderWindow *renderWindow)
{

    if (opacite > 0 && scoreboard->acceleration() > 27)
    {
        this->SpriteBack.setColor(sf::Color(255, 255, 255, opacite)); //changement de l'opacité à chaque boucle
        opacite = opacite - 0.02;
    }


    if (scoreboard->get_hauteur() > 1000)
    {

        renderWindow->draw(SpriteTesla);
        SpriteTesla.move(0.1,-0.1);
        SpriteTesla.rotate(0.10);
    }
}

background::~background() {}

