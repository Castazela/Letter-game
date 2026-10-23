// rm -f main && clang++ -std=c++17 main.cpp -o main && ./main

#include <iostream>
#include <string>  // Introduces string types, character traits and a set of converting functions https://cplusplus.com/reference/string/
#include <cstring> //String handling and memory manipulation https://cplusplus.com/reference/cstring/
#include <ctime>   // Fonctions dates/heuletters_drawing
#include <fstream> //Read and write to a file https://cplusplus.com/reference/fstream/?kw=%3Cfstream%3E
#include <vector>
#include <cctype> //To use tolower() and tooper() functions

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

// Reading file
vector<string> ReadFile()
{
    // Declare filename variable
    string filename = "Dictionnary.txt";
    ifstream file;

    file.open(filename);

    // Store each line in file
    vector<string> dico;
    string word;

    // Read every line (word in this case)
    while (getline(file, word)) // Read line ATTENTION PAR DE ; APRÈS UNE BOUCLE
    {
        for (char &letter : word)
        {
            letter = toupper(letter); // Capitalize words in the dictionary
        }
        dico.push_back(word); // Put a word in the vector
    }

    file.close();

    return dico;
}

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

// Main
int main()
{
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

            else if (word.size() == best_words[0].size())
            {
                best_words.push_back(word);
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
    return 0;
}