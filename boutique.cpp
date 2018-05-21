#include "boutique.h"

boutique::boutique()
{
    TextBoutique.loadFromFile("images/boutique.png");
    SpriteBoutique.setTexture(TextBoutique);
    SpriteBoutique.setPosition(340,410);
    depense.openFromFile("images/depense.ogg");
    for(i=0; i < 2; i++)
    {

        panneau.push_back(new sf::Texture);
    }
    panneau[0]->loadFromFile("images/boutique.png");
    panneau[1]->loadFromFile("images/boutique1.0.png");
    i = 0;
}

void boutique::traitement(sf::RenderWindow *renderWindow,score *scoreboard,fusee *rocket)
{

    position_mouse = sf::Mouse::getPosition(*renderWindow);
    sf::RectangleShape slot1(sf::Vector2f(50, 70));
    slot1.setPosition(340,410);
    sf::RectangleShape slot2(sf::Vector2f(50, 70));
    slot2.setPosition(390,410);
    sf::RectangleShape slot3(sf::Vector2f(50, 70));
    slot3.setPosition(440,410);
    renderWindow->draw(SpriteBoutique);
    sf::Time chrono = clock.getElapsedTime();


    if ((slot1.getGlobalBounds().contains(position_mouse.x,position_mouse.y)) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (scoreboard->getcompteur() >= 20) && (scoreboard->getvie() < 5) && chrono.asMilliseconds() > 1000 )  // Verifie si la position de la souris et si le click est ok
    {
        clock.restart();

        scoreboard->depensecompteur(20); // On retire l'argent
        scoreboard->addvie(); // Ajout de la vie
        depense.play();// Bruit de dépense
    }



    if ((slot2.getGlobalBounds().contains(position_mouse.x,position_mouse.y)) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (scoreboard->getcompteur() >= 40) && chrono.asMilliseconds() > 1000 ) // Verifie si la position de la souris et si le click est ok
    {

        clock.restart();
        scoreboard->depensecompteur(40);
        setflag(); // Ajout du declencheur de gel des asteroide
        depense.play();
    }


    if ((slot3.getGlobalBounds().contains(position_mouse.x,position_mouse.y)) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (scoreboard->getcompteur() >= 50) && chrono.asMilliseconds() > 1000 && i < 2 ) // Verifie si la position de la souris et si le click est ok
    {
        clock.restart();
        scoreboard->depensecompteur(50);
        if (i == 0)   // Si I = 0 est alors on declenche le détachement des boosters
        {
            rocket->detachement();
            i++;
        }
        else if (i == 1)
        {
            rocket->detachement_core(); // Detachement de lanceur principal

        }

        depense.play();
    }

}




void boutique::setflag()
{
    flag = true;
    clock2.restart(); // on restart le chrono de gel des asteroide
    SpriteBoutique.setTexture(*panneau[1]); // On change la texture de notre boutique
}

bool boutique::veriflag()
{
    sf::Time chrono2 = clock2.getElapsedTime(); // On mesure le temps

    if (flag == true && chrono2.asSeconds() > 5 )   // Si le gel est activé et que le chrono est supérieur a 5 secondes
    {

        flag = false;
        SpriteBoutique.setTexture(*panneau[0]); // On rechange la texture

    }
    return flag; // On return l'etat du gel
}


boutique::~boutique() {}
