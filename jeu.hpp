#pragma once

#include <string>
#include <vector>

// Letter-drawing.cpp
int CountVowels(std::string letters);
std::string RandomLetters(int n);

// Reading dictionnary
std::vector<std::string> ReadFile();

// Check wich word can be make with drawing
bool CanMakeWord(std::string word, std::string letters);