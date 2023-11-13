/*
 * Erweitern Sie das folgende Programm, sodass es die Funktion qsort der Standard-Bibliothek verwendet, 
 * um das enthaltene String-Array sortiert auszugeben. Es sollen zuerst die Strings ohne Zahlen ausgegeben werden 
 * und am Ende die mit Zahlen. Die Strings ohne Zahlen sollen aufsteigend sortiert werden, die mit Zahlen absteigend.
 * Sie können davon ausgehen, dass die im Array enthaltenen Strings immer nur aus Buchstaben oder nur aus Zahlen bestehen.
 * Es ist also ausreichend, das erste Zeichen mittels isdigit(...) zu prüfen.
 * 
 */

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void gibStringsAus(const char *strings[], unsigned int anzahl);
// TODO

int compare(const void* a, const void* b);

int main()
{
    const char *strings[] = {"789", "Zorro", "Adam", "Werner", "123", "Bernd", "Hubert", "456"};
    unsigned int anzahlStrings = sizeof(strings)/sizeof(strings[0]);

    printf("Vor Sortierung:\n");
    gibStringsAus(strings, anzahlStrings);

    qsort(strings, anzahlStrings, sizeof(strings[0]), compare);

    printf("\nNach Sortierung:\n");
    gibStringsAus(strings, anzahlStrings);

    return EXIT_SUCCESS;
}

void gibStringsAus(const char *strings[], unsigned int anzahl)
{
    for(int i = 0; i < anzahl; i++)
    {
        printf("%s\n", strings[i]);
    }
}

int compare(const void* a, const void* b)
{
    const char* stringA = *(const char**)a;
    const char* stringB = *(const char**)b;

    if(isdigit(stringA[0]) && isdigit(stringB[0]))
    {
        return strtol(stringB, NULL, 10) - strtol(stringA, NULL, 10);
    }
    else if(isdigit(stringA[0]) && !isdigit(stringB[0]))
    {
        return 1;
    }
    else if(!isdigit(stringA[0]) && isdigit(stringB[0]))
    {
        return -1;
    }
    else
    {
        return strcmp(stringA, stringB);
    }

    return 0;
}
