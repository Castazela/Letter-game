#include <string>
#include <cstdlib>

#include "jeu.hpp"

using namespace std;

// Counting Vowels to have min 2
int CountVowels(string letters)
{
    string vowels = "AEIOUY";
    int count = 0;
    for (char c : letters)
    {
        if (vowels.find(c) != string::npos)
        {
            count++;
        }
    }
    return count;
}

// Return 9 random letters from alphabet list
string RandomLetters(int n)
{
    // Alphabet
    char alphabet[26];
    for (int i = 0; i < 26; ++i)
    {
        alphabet[i] = 'A' + i;
    }

    // Initialisation empty list while have random letter
    string letters_drawing;
    do
    {
        letters_drawing = "";
        for (int i = 0; i < n; i++)
        {
            letters_drawing += alphabet[rand() % 26];
            letters_drawing += ' ';
        }
    } while (CountVowels(letters_drawing) < 2);
    return letters_drawing;
}