
#include "vie.h"

vie::vie(int i)
{

    vietext.loadFromFile("images/vie.png");
    viegris.loadFromFile("images/vie_gris.png");
    Spritevie.setTexture(vietext);

    Spritevie.setPosition(50*i,430);
    i++;

}

void vie::dessiner(sf::RenderWindow *renderWindow)
{
    renderWindow->draw(Spritevie);
}

void vie::change()
{
    this->Spritevie.setTexture(viegris);
}

void vie::changeup()
{
    this->Spritevie.setTexture(vietext);
}
