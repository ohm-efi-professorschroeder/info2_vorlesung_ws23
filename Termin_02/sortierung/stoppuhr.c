#include <time.h>
#include "stoppuhr.h"

static clock_t zeitStempel = 0;

void starteUhr()
{
    zeitStempel = clock();
}

double messeZeitInSek()
{
    return (double)(clock() - zeitStempel) / CLOCKS_PER_SEC;
}