#include "fusee.h"

using namespace std;
using namespace sf;


fusee::fusee()
{
    for(i =0; i <= 17; i++)
    {
        textureliste.push_back(new Texture); // Création du tableau de texture pour les flammes
        fire.push_back(new Sprite); // Tableau des sprites des flammes
    }

    textureliste[0]->loadFromFile("images/flamme.png"); // Chargements des textures.
    textureliste[1]->loadFromFile("images/flamme2.png");
    textureliste[2]->loadFromFile("images/flamme3.png");
    textureliste[3]->loadFromFile("images/flamme4.png");
    textureliste[4]->loadFromFile("images/flamme5.png");
    textureliste[5]->loadFromFile("images/flamme6.png");
    textureliste[6]->loadFromFile("images/flamme7.png");
    textureliste[7]->loadFromFile("images/flamme8.png");
    textureliste[8]->loadFromFile("images/flamme9.png");
    textureliste[9]->loadFromFile("images/flamme21.png");
    textureliste[10]->loadFromFile("images/flamme22.png");
    textureliste[11]->loadFromFile("images/flamme23.png");
    textureliste[12]->loadFromFile("images/flamme24.png");
    textureliste[13]->loadFromFile("images/flamme25.png");
    textureliste[14]->loadFromFile("images/flamme26.png");
    textureliste[15]->loadFromFile("images/flamme27.png");
    textureliste[16]->loadFromFile("images/flamme28.png");
    textureliste[17]->loadFromFile("images/flamme29.png");
    for(i =0; i <= 17; i++)
    {
        fire[i]->setTexture(*textureliste[i]) ; // Ajout des texture sur les sprites des flammes
    }


    i=0;
    textcore.loadFromFile("images/booster.png");
    rocket.loadFromFile("images/rocket.png");
    textboost.loadFromFile("images/booster.png");
    textflame.loadFromFile("images/flamme.png");
    mainrocket.loadFromFile("images/main_stage.png");
    fairing.loadFromFile("images/fairing.png");
    Spritefairing.setTexture(fairing);
    separation.openFromFile("images/separation.ogg");
    SpriteMainRocket.setTexture(mainrocket);
    Booster.setTexture(textboost);
    flamme.setTexture(textflame);

    sprite.setTexture(rocket); //chargement de la texture de la rocket
    Booster.setOrigin(sf::Vector2f(sprite.getTexture()->getSize().x/2,sprite.getTexture()->getSize().y/2));
    SpriteMainRocket.setPosition(0,600);
    SpriteMainRocket.setOrigin(sf::Vector2f(sprite.getTexture()->getSize().x/2,sprite.getTexture()->getSize().y/2 ));
    sprite.setOrigin(sf::Vector2f(sprite.getTexture()->getSize().x/2,sprite.getTexture()->getSize().y/2 ));
    sprite.setPosition(sf::Vector2f(320,360));//on place le centre de la fusee au milieu de l'écran au début du jeu
    falcon.push_back(&sprite); // Ajouts des sprites des différents états de la fusée
    falcon.push_back(&SpriteMainRocket);
    falcon.push_back(&Spritefairing);

}



void fusee::dessiner(sf::RenderWindow *renderWindow)
{

    if (declenchement == true && limite == false)
    {

        renderWindow->draw(Booster);
        Booster.move(0,0.2); // On fait tomber les boosters
        if (Booster.getPosition().y == 500)
        {
            limite = true;
        }
    }



    if (declenchement2 == true && limite2 == false)
    {

        renderWindow->draw(*falcon[1]);
        falcon[1]->move(0,0.2); // On fait tomber l'etage centrale
        if (falcon[1]->getPosition().y == 500)
        {
            limite2 = true;
        }

    }

    renderWindow->draw(*falcon[id]); //on dessine la fusée
    fire[i]->setPosition(falcon[id]->getPosition().x,falcon[id]->getPosition().y);
    fire[i]->setRotation(falcon[id]->getRotation());

    Time time1 = clock.getElapsedTime();

    if (time1.asMilliseconds() > 60)
    {

        i++;

        clock.restart();
        if (i == maxi)
        {
            i= mini;
        }

    }
    fire[i]->setOrigin(sf::Vector2f(falcon[id]->getTexture()->getSize().x/2,falcon[id]->getTexture()->getSize().y/2));
    if (falcon[1]->getPosition().y > 500)
    {
        renderWindow->draw(*fire[i]);
    }

}


void fusee::decollage(background *fond,bool *etatdecollage)
{



    if ( falcon[0]->getPosition().y > -90)
    {

        hauteur =- 0.1;

        sprite.move(0,hauteur); //on fait décoller la fusée dès le début

    }

    if ( falcon[0]->getPosition().y < -80)
    {


        falcon[0]->setPosition(sf::Vector2f(320,360));
        *etatdecollage = true;
    }
}

void fusee::deplacement(score *scoreboard)
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && falcon[id]->getPosition().y > 0)
    {

        falcon[id]->move(0,-0.5); // On déplace le sprite sur l'axe des y
        falcon[id]->setRotation(0); // On annule la rotation du sprite si la touche est préssé
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && falcon[id]->getPosition().y < 480)
    {

        falcon[id]->move(0,0.5); // On déplace le sprite sur l'axe des y
        falcon[id]->setRotation(0); // On annule la rotation du sprite si la touche est préssé
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && falcon[id]->getPosition().x > 0)
    {

        falcon[id]->move(-0.5,0); // On déplace le sprite sur l'axe des x
        falcon[id]->setRotation(-20); // On fait une animation de rotation de 10°
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && falcon[id]->getPosition().x < 640 )
    {

        falcon[id]->move(0.5,0); // On déplace le sprite sur l'axe des x aussi
        falcon[id]->setRotation(20); // meme procédé pour éviter l'effet "Handspinner"

    }

    else   // Si aucune touche n'est préssé alors :
    {

        falcon[id]->setRotation(0);
    }

}

float fusee::getx()
{

    return falcon[id]->getPosition().x; // On calque le sprite sur le centre de la fusee

}

float fusee::gety()
{

    return falcon[id]->getPosition().y; // ^ pareil mais sur l'axe des y

}

float fusee::getlargeur()
{

    return falcon[id]->getTexture()->getSize().x; // Taille du sprite sur l'axe des x
}

float fusee::gettaille()
{
    return falcon[id]->getTexture()->getSize().y;// Taille du sprite sur l'axe des y
}

FloatRect fusee::getGlobalBounds()
{

    return falcon[id]->getGlobalBounds(); // Hitbox de la fusée
}


void fusee::fantome() // Mode fantome de la fusée
{

    falcon[id]->setColor(sf::Color(255, 255, 255,30));
    fire[i]->setColor(sf::Color(255, 255, 255,30));
}

void fusee::neutre() // Mode basique de la fusée (opaque)
{

    falcon[id]->setColor(sf::Color(255, 255, 255,255));
    fire[i]->setColor(sf::Color(255, 255, 255,255));
}


void fusee::detachement()
{

    if ( declenchement == false)
    {

        textcore.loadFromFile("images/core.png");
        falcon[0]->setTexture(textcore);
        falcon[0]->setOrigin(sf::Vector2f(sprite.getTexture()->getSize().x/2,sprite.getTexture()->getSize().y/2 ));

        Booster.setPosition(falcon[0]->getPosition().x,falcon[0]->getPosition().y);

        separation.play();
        declenchement = true;
    }

}


void fusee::detachement_core()
{

    if ( declenchement2 == false)
    {
        maxi = 17;
        mini = 10;
        falcon[1]->setPosition(falcon[0]->getPosition().x,falcon[0]->getPosition().y);
        falcon[2]->setOrigin(sf::Vector2f(falcon[2]->getTexture()->getSize().x/2,falcon[2]->getTexture()->getSize().y/2 ));
        falcon[2]->setPosition(falcon[1]->getPosition().x,falcon[1]->getPosition().y-80);



        id = 2;

        separation.play();
        declenchement2 = true;
    }

}





fusee::~fusee() { }
