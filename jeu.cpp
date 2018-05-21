#pragma once
#include "jeu.h"
#include <vector>

jeux::jeux(sf::RenderWindow *renderWindow)
{
    shop = new boutique; // Creation de la boutique
    rocket = new fusee; // Création de la fusée
    fond = new background; // Création Background
    scoreboard = new score(renderWindow); // Creation du scoreboard
    gain = new piece; // Creation de piece
    fin = new gameover; // Creation du Game Over

    tab.push_back(new obstacle);
    pieces.push_back(new piece);
    for (i=0; i < 5; i++)
    {
        life.push_back(new vie(i)); // Tableau de vie avec incrémentation pour les espacer
    }
    chrono3.Zero; // Set du chrono fantome a Zero
}

bool jeux::decollage(sf::RenderWindow *renderWindow) // Animation de départ
{

    fond->dessiner(renderWindow);
    rocket->deplacement(scoreboard);

    rocket->dessiner(renderWindow);
    rocket->decollage(fond,&etatdecollage);

    if(etatdecollage == true)
    {
        return true; // Fin de la fonction quand le declencheur est vrai
    }
}


bool jeux::controle(sf::RenderWindow *renderWindow)
{


    chrono = clock.getElapsedTime(); //
    chrono2 = clock2.getElapsedTime(); //
    fond->defilement(); // Defilement du fond avec fondu

    fond->dessiner(renderWindow);

    rocket->deplacement(scoreboard);// Gestion controle de la fusée

    if (scoreboard->getImpact() == 1) // Si le score renvoit un impact alors on met la fusée en mode fantome et on chronometre
    {
        chrono3 = clock3.getElapsedTime();
        rocket->fantome();


    }
    if (chrono3.asMilliseconds() > 3000) // Si le chrono dépasse les 5000ms alors on remet la fusée en mode neutre et on reset l'impact à 0 puis on reset la clock
    {
        rocket->neutre();
        scoreboard->RetImpact();
        clock3.restart();
    }
    if (scoreboard->getImpact() == 0)
    {
        clock3.restart();
    }

    rocket->dessiner(renderWindow);

    fond->changement(scoreboard,renderWindow);


//######## OBSTACLES #################
    if (chrono.asMilliseconds() > (randpop) && shop->veriflag() == false)  // Si le chrono dépasse le temps de generation random de l'asteroide alors on créer un nouvel asteroide puis on regenere un nouveau temps random en fonction de la difficulté
    {

        tab.push_back(new obstacle);

        if (difficulte > 0.2) // On gere la difficulté
        {
            difficulte = difficulte - 0.01;
        }
        clock.restart();
        randpop = rand()%1000 + 200;


    }
//########################


//#### PIECES #######
    if (chrono2.asMilliseconds() > randpop2) // Temps random pour la generation des pieces
    {

        pieces.push_back(new piece);
        pieces[j]->dessiner(renderWindow);
        clock2.restart();
        randpop2 = rand()%2000;

    }
//###################


//### CHECK COLLI ########
    i = 0;
    j =0;
    while (i < tab.size())
    {

        tab[i]->checkColli(rocket,renderWindow,scoreboard);
        if (tab[i]->gety() > 500)
        {
            delete tab[i];
            tab.erase(tab.begin() + i); // On delete les asteroides qui sortent du cadre
        }
        else
        {
            i++;
        }
    }

    while (j < pieces.size())
    {
        pieces[j]->checkColli(rocket,renderWindow, scoreboard);
        if (pieces[j]->gety() > 500)
        {
            delete pieces[j];
            pieces.erase(pieces.begin() + j); // On delete les pieces qui sortent du cadre
        }
        else
        {
            j++;
        }
    }

//######################
    scoreboard->piecesdraw(renderWindow);

    if (scoreboard->get_vie() == 0)
    {
        return true;  // ON QUITTE LE JEU QUAND ELON MEURT
    }
    shop->traitement(renderWindow,scoreboard,rocket); // traitement de la boutique + affichage
    scoreboard->scoredraw(renderWindow); // Affichage du score
}

bool jeux::over(sf::RenderWindow *renderWindow)
{

    if(fin->lancement(renderWindow,scoreboard->get_score(),scoreboard->get_hauteur()) == true)
    {
        reset(); // Lancement de la supression des objets
        return true;
    };


}

void jeux::reset()
{
    delete shop;
    delete rocket;
    delete scoreboard;
    delete fond;
    delete fin;
}


jeux::~jeux() {}

