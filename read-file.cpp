#include <string>
#include <fstream> //Read and write to a file https://cplusplus.com/reference/fstream/?kw=%3Cfstream%3E
#include <vector>
#include <cctype>

#include "jeu.hpp"

using namespace std;

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
