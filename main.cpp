// Compilation 
// rm -f main --> supp main
//clang++ main.cpp -o main --> compile
// ./main --> execute

//rm -f main && clang++ main.cpp -o main && ./main --> tout en même temps

#include <iostream>
#include <string> // Introduces string types, character traits and a set of converting functions https://cplusplus.com/reference/string/
#include <cstring> //String handling and memory manipulation https://cplusplus.com/reference/cstring/
#include <ctime> // Fonctions dates/heures
#include <fstream> //Read and write to a file https://cplusplus.com/reference/fstream/?kw=%3Cfstream%3E
#include <vector>


using namespace std;

//Return 9 random letters from alphabet list
string RandomLetters(int n)
{
    //Alphabet
    char alphabet[26];
    for (int i=0; i<26; ++i) {
        alphabet[i] = 'A' + i;
    }

    //Initialisation empty list while have random letter
    string res = "";
    for (int i =0; i < n; i++) {
        res += alphabet[rand() % 26];
        res+= ' ';
    }
    return res;
}

//Reading file
vector<string> ReadFile()
{
    //Declare filename variable 
    string filename = "Dictionnary.txt";
    ifstream file;

    file.open(filename);

    //Store each line in file
    vector<string> dico;
    string word;

    //Read every line (word in this case)
    while(getline(file, word)) //Read line ATTENTION PAR DE ; APRÈS UNE BOUCLE 
    {
        dico.push_back(word); //Put a word in the vector
    }

    file.close();

    return dico;

}


//Shake if a word can be create or not 
bool CanMakeWord(string word, string letters)
{
for (char letter : word) 
{
    size_t letter_position = letters.find(letter); //size_t est un type d’entier non signé (donc jamais négatif), conçu pour représenter des tailles et des positions
    if (letter_position == string::npos)
    {
        return false;
    }
    letters.erase(letter_position, 1);
}
return true;
}


//Main
int main()
{
    srand(time(nullptr));   // Different seed on each run

    string randomletters = RandomLetters(9);
    cout << randomletters << endl;

    vector<string> dico = ReadFile();



    return 0;


}