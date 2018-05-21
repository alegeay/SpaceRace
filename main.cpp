#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "fusee.h"
#include "background.h"
#include "obstacle.h"
#include "score.h"
#include "piece.h"
#include "start.h"
#include "gameover.h"
#include <sys/time.h>


int main()
{



    start menu;
    //Mise en place du timer

    struct timeval time;
    gettimeofday(&time, NULL);
    srand((time.tv_sec * 1000) + (time.tv_usec / 1000)); //Timer en millisecondes et non en secondes

    //Affichage de la fenetre 640*480
    sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Space RACE",sf::Style::Close);

    //Lancement de la musique <3


    sf::Music music;
    sf::Music over;
    sf::Event event;
    over.openFromFile("images/over.ogg");
    music.openFromFile("images/mars.ogg");
    music.setLoop(true);


//jeux game(&renderWindow);



    while (menu.lancement(&renderWindow) != true)
    {
        renderWindow.display();
        renderWindow.pollEvent(event);
        if (event.type == sf::Event::Closed)
        {
            renderWindow.close();
            return 0;
        }
    }
    while (1 > 0)
    {
        jeux *game = new jeux(&renderWindow);

        while (game->decollage(&renderWindow) != true)
        {
            renderWindow.display();
            renderWindow.pollEvent(event);
            if (event.type == sf::Event::Closed)
            {
                renderWindow.close();
                return 0;
            }
        }

        music.play();

        while (game->controle(&renderWindow) != true )
        {
            renderWindow.display();
            renderWindow.pollEvent(event);
            if (event.type == sf::Event::Closed)
            {
                renderWindow.close();
                return 0;
            }
        }
        music.stop();
        over.play();

        while (game->over(&renderWindow) != true)
        {
            renderWindow.display();
            renderWindow.pollEvent(event);
            if (event.type == sf::Event::Closed)
            {
                renderWindow.close();
                return 0;
            }
        }
        over.stop();
        delete game;
    }
};














