#include "gameover.h"
using namespace std;
using namespace sf;

gameover::gameover()
{
    gameovertext.loadFromFile("images/gameover.png");
    fondgameover.setTexture(gameovertext);

    bouton.loadFromFile("images/StartIcon.png");
    SpriteBouton.setTexture(bouton);
    SpriteBouton.setPosition(260,290);

    font.loadFromFile("arial.ttf");
    text1.setFont(font);
    text1.setCharacterSize(24);
    text1.setStyle(sf::Text::Regular);
    text1.setPosition(50,80);

    text2.setFont(font);
    text2.setCharacterSize(24);
    text2.setStyle(sf::Text::Regular);
    text2.setPosition(50,110);
}

bool gameover::lancement(sf::RenderWindow *renderWindow,string scorefinal,int hauteur)
{

    scorefinal = "Votre score : " + scorefinal;
    text1.setString(scorefinal);

    renderWindow->draw(fondgameover);
    renderWindow->draw(SpriteBouton);
    renderWindow->draw(text1);
    writescore(hauteur);
    renderWindow->draw(text2);

    position_mouse = sf::Mouse::getPosition(*renderWindow);

    if ((SpriteBouton.getGlobalBounds().contains(position_mouse.x,position_mouse.y)) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
    {
        return true;
    }
}

void gameover::writescore(int hauteur)
{

    ifstream out_scoring("images/scores.txt");

    if(out_scoring)
    {
        string contenu;
        getline(out_scoring, contenu);
        text2.setString(meilleurscore);
        out_scoring.close();
        stringstream ss;
        int f;
        ss.str(contenu);
        ss >> f;
        stringstream convert;
        convert << hauteur;


        if (f < hauteur)
        {
            ofstream in_scoring("images/scores.txt");
            in_scoring << hauteur;
            in_scoring.close();
            meilleurscore = "Nouveau meilleur score ! : " +  convert.str() + "km";
            text2.setColor(sf::Color::Yellow);
        }
        else if (f > hauteur)
        {
            text2.setColor(sf::Color::White);
            meilleurscore = "Meilleur score : " + contenu + "km";
        }
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
}

gameover::~gameover() {}
