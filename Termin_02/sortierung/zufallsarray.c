#include <stdlib.h>
#include "zufallsarray.h"

void fuelleArray(int array[], int anzahl, int min, int max)
{
    for(int i = 0; i < anzahl; i++)
        array[i] = rand() % (max - min + 1) + min;
}