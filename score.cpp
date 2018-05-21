#include "score.h"



using namespace std;
using namespace sf;

score::score(sf::RenderWindow *renderWindow)
{
    ScoreFond.loadFromFile("images/score.jpg");
    SpriteScore.setTexture(ScoreFond);
    SpriteScore.setPosition(540,460);

    Cash.loadFromFile("images/piece.png");
    SpriteCash.setTexture(Cash);
    SpriteCash.setPosition(560, 445);

    font.loadFromFile("arial.ttf");

    text1.setFont(font);
    text1.setStyle(sf::Text::Regular);
    text1.setPosition(590,463);

    pieces.setFont(font);
    pieces.setStyle(sf::Text::Regular);
    pieces.setPosition(570, 440);

    for(int i=0; i < 5; i++)
    {
        life.push_back(new vie(i));
    }
}

// Convertisseur de float en texte
string score::convertTo(float sec)
{
    sec = floor(sec);
    stringstream stream;
    stream << (sec);

    return stream.str();
}

// Methode qui transforme le score et ajoute "km" pour le score ainsi que la gestion de la vie
void score::scoredraw(sf::RenderWindow *renderWindow)
{

    hauteur = acceleration();
    str = convertTo(hauteur);
    view = str + "km";
    text1.setString(view);
    text1.setCharacterSize(12);
    renderWindow->draw(SpriteScore);
    renderWindow->draw(text1);
    for (int i=0; i < 5; i++)
    {
        life[i]->dessiner(renderWindow);

    }
}






float score::acceleration() // Gestion de l'acceleration
{

    chrono = clock.getElapsedTime();
    hauteur = chrono.asSeconds() * vitesse;
    if (vitesse < 30)
    {
        vitesse = vitesse +0.0001;
    }
    return hauteur;

}



int score::get_hauteur() // Recupere la hauteur
{
    return hauteur;
}

void score::piecesdraw(sf::RenderWindow * renderWindow) // Affichage du score des pieces
{
    pcs = convertTo(compteur);
    cash = pcs + "$";
    pieces.setString(cash);
    pieces.setCharacterSize(12);
    renderWindow->draw(SpriteCash);
    renderWindow->draw(pieces);

}



void score::retire_vie() // Retire la vie si y'a un impact
{
    if (getImpact() == 1)
    {
        ptvie = ptvie-1;
        life[ptvie]->change();
    }
}

int score::getvie()
{
    return ptvie;
}

void score::addvie()
{

    life[ptvie]->changeup();
    ptvie++;
}



int score::getImpact() // Recupere l'etat de la variable impact
{
    return impact;
}
void score::setImpact() // Crée l'impact
{
    impact = 1;
}
void score::RetImpact() // retire l'impact
{
    impact = 0;
}


int score::get_vie() // Recupere l'impact
{
    return ptvie;
}

string score::get_score()
{

    return view;

}

void score::setcompteur()
{

    compteur++;

}


int score::getcompteur()
{
    return compteur;
}

void score::depensecompteur(int prix)
{

    compteur = compteur - prix;

}


score::~score()
{

}

