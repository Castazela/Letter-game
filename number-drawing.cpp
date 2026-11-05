#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>

#include "jeu.hpp"

using namespace std;

void NumberDrawing(int drawing_numbers[])
{

    int numbers[14] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 25, 50, 75, 100};

    // Generate random index
    for (int i = 0; i < 6; i++)
    {
        int index = rand() % 6;
        drawing_numbers[i] = numbers[index];
    }
}
