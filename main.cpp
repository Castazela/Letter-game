/*Compilation : */
/*g++ -std=c++17 main.cpp letter-drawing.cpp read-file.cpp make-word.cpp -o main && ./main*/

#include <iostream>
#include <string> // Introduces string types, character traits and a set of converting functions https://cplusplus.com/reference/string/
#include <ctime>  // Fonctions dates/heuletters_drawing
#include <vector>
#include <cctype> //To use tolower() and tooper() functions
#include <cstdlib>

// include files with fonctions
#include "jeu.hpp"

using namespace std;

int main()
{
    // Menu
    int choix;

    cout << "Que souhaitez-vous faire ? \n 1. Des chiffres... \n 2. ...et des lettres \n 3. Quitter" << endl;
    cin >> choix;

    while (choix != 3)
    {
        switch (choix)
        {
        case 1:
            cout << "Patience ça arrive" << endl;
            break;

        case 2:

            srand(time(nullptr)); // Different seed on each run

            // Tirage
            string randomletters = RandomLetters(9);
            cout << "Lettres tirées : " << randomletters << endl;

            // Chargement du dictionnaire
            vector<string> dico = ReadFile();

            // Recherche du/des meilleur(s) mot(s)
            vector<string> best_words;

            for (string word : dico)
            {
                if (CanMakeWord(word, randomletters))
                {
                    if (best_words.empty() || word.size() > best_words[0].size()) // si best_words est vide, ou si le mot est plus long que ceux de best_words
                    {
                        best_words.clear();         // vider best_words
                        best_words.push_back(word); // puis y mettre ce mot
                    }

                    else if (word.size() == best_words[0].size()) // si le mot a la même longueur que ceux de best_words :
                    {
                        best_words.push_back(word); // l'ajouter à best_words
                    }
                }
            }

            // Conversion en minscule
            for (string &word_min : best_words)
            {
                for (char &letter : word_min)
                {
                    letter = tolower(letter);
                }
            }
            // Affichage
            if (best_words.empty())
            {
                cout << "Aucun mot n'a été trouvé" << endl;
            }
            else
            {
                cout << "Mot faisables avec le tirage :" << endl;
                for (string &word_min : best_words)
                {
                    cout << word_min << endl;
                }
            }
            break;
        }
        cout << "Que souhaitez-vous faire ? \n 1. Des chiffres... \n 2. ...et des lettres \n 3. Quitter" << endl;
        cin >> choix;
    }
    return 0;
}