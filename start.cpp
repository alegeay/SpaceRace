#include "start.h"


start::start() // Constructeur
{
    TextStart.loadFromFile("images/StartFond.png");
    bouton.loadFromFile("images/StartIcon.png");
    SpriteFond.setTexture(TextStart);
    SpriteBouton.setTexture(bouton);
    SpriteBouton.setPosition(260,190);

}



bool start::lancement(sf::RenderWindow *renderWindow) // Affichage de la page de start
{

    renderWindow->draw(SpriteFond);
    renderWindow->draw(SpriteBouton);


    position_mouse = sf::Mouse::getPosition(*renderWindow);


    if ((SpriteBouton.getGlobalBounds().contains(position_mouse.x,position_mouse.y)) && (sf::Mouse::isButtonPressed(sf::Mouse::Left))) // Verifie si la position de la souris et si le click est ok
    {
        return true;
    }






}
