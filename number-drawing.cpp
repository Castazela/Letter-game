#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>

using namespace std;

int NumberDrawing(const char)
{
    srand(time(NULL)); // initialize the random seed

    const char numbers[14] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 25, 50, 75, 100};
    int number_drawing = rand() % 6;
    return numbers[number_drawing];
}

int main()
{
    cout << "Nombres tirés :" << NumberDrawing() << endl;
}
