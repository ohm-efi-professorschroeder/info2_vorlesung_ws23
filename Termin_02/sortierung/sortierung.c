#include "sortierung.h"

static void tausche(int *zahl1, int *zahl2)
{
    int tmp = *zahl1;
    *zahl1 = *zahl2;
    *zahl2 = tmp;
}

void selectionSort(int array[], int anzahl)
{
    for(int i = 0; i < anzahl - 1; i++)
    {
        int minIdx = i;
        for(int j = i + 1; j < anzahl; j++)
        {
            if(array[j] < array[minIdx])
                minIdx = j;
        }
        tausche(&array[i], &array[minIdx]);
    }
}

void merge(int *start, int* mid, int* end)
{
    int anzahlLinks = mid - start + 1;
    int anzahlRechts = end - mid;
    int anzahl = end - start + 1;
    int sortiert[anzahl];

    int linksIdx = 0, rechtsIdx = 0, sortiertIdx = 0;

    while(linksIdx < anzahlLinks && rechtsIdx < anzahlRechts)
    {
        if(start[linksIdx] <= (mid+1)[rechtsIdx])
        {
            sortiert[sortiertIdx] = start[linksIdx];
            linksIdx++;
        }
        else
        {
            sortiert[sortiertIdx] = (mid+1)[rechtsIdx];
            rechtsIdx++;
        }
        sortiertIdx++;
    }

    while(linksIdx < anzahlLinks)
    {
        sortiert[sortiertIdx] = start[linksIdx];
        linksIdx++;
        sortiertIdx++;
    }

    while(rechtsIdx < anzahlRechts)
    {
        sortiert[sortiertIdx] = (mid+1)[rechtsIdx];
        rechtsIdx++;
        sortiertIdx++;
    }

    for(int i = 0; i < anzahl; i++)
    {
        start[i] = sortiert[i];
    }
}

void mergeSort_(int *start, int *end)
{
    if(start >= end)
        return;

    int* mid = start + (end - start) / 2;

    mergeSort_(start, mid);
    mergeSort_(mid+1, end);

    merge(start, mid, end);
}

void mergeSort(int array[], int anzahl)
{
    mergeSort_(array, array + anzahl - 1);
}