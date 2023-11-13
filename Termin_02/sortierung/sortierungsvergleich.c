/************************************************************************************************
 * Implementieren Sie die folgenden Sortieralgorithmen und vergleichen Sie deren Laufzeit mit 
 * untenstehendem Programm:
 * 1. Nutzen Sie zunächst die bereitgestellte und aus Informatik 1 bekannte Lösung für SelectionSort.
 * 2. Erweitern Sie nun sortierung.h bzw. sortierung.c um MergeSort.
 * 3. Erweitern Sie nun sortierung.h bzw. sortierung.c um Quicksort.
 * 4. Nutzen Sie abschließend die von der C-Standardbibliothek bereitgestellte qsort-Funktion.
 * 
 * Hinweis: Das Array wird nur ausgegeben, wenn die Anzahl an Elementen noch klein genug für 
 *          eine Darstellung ist. Standardmäßig wird eine sehr große Anzahl an Elementen sortiert, um 
 *          eine spürbare Laufzeit zu erzwingen, und somit das Array nicht ausgegeben. Genaueres ist 
 *          im Quellcode unten ersichtlich.
 * 
 * Welche Laufzeit-Unterschiede ergeben sich?
 *************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sortierung.h"
#include "zufallsarray.h"
#include "stoppuhr.h"

#define ANZAHL_MAX 1000000
#define ANZAHL ANZAHL_MAX
#define ANZEIGE_MAX 100

void gibArrayAus(int array[], int anzahl)
{
    for(int i = 0; i < anzahl; i++)
    {
        printf(" %3d", array[i]);
    }
    printf("\n");
}

// TODO: Begin
int vergleiche(const void *arg1, const void *arg2)
{
    return *(int *)arg1 - *(int *)arg2;
}
// TODO: Ende

int main()
{
    int zufallszahlen[ANZAHL];
    srand(0);

    fuelleArray(zufallszahlen, ANZAHL, -ANZAHL, ANZAHL);

    if(ANZAHL <= ANZEIGE_MAX)
        gibArrayAus(zufallszahlen, ANZAHL);

    starteUhr();
    //selectionSort(zufallszahlen, ANZAHL);
    mergeSort(zufallszahlen, ANZAHL);
    //qsort(zufallszahlen, ANZAHL, sizeof(zufallszahlen[0]), vergleiche);
    //mergesort(zufallszahlen, ANZAHL, sizeof(zufallszahlen[0]), vergleiche);

    printf("Zahlen sortiert nach %lf Sekunden.\n", messeZeitInSek());

    if(ANZAHL <= ANZEIGE_MAX)
        gibArrayAus(zufallszahlen, ANZAHL);

    return 0;
}
