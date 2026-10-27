#include <string>

#include "jeu.hpp"

using namespace std;

// Shake if a word can be create or not
bool CanMakeWord(string word, string letters)
{
    for (char letter : word)
    {
        size_t letter_position = letters.find(letter); // size_t est un type d’entier non signé (donc jamais négatif), conçu pour représenter des tailles et des positions
        if (letter_position == string::npos)
        {
            return false;
        }
        letters.erase(letter_position, 1);
    }
    return true;
}
