/*
 * Vervollständigen Sie das untenstehende Programm, indem Sie das Modul namesarchive in der 
 * namesarchive.h bzw. namesarchive.c implementieren.
 * Die öffentlichen Schnittstellen mit genaueren Details entnehmen Sie der namesarchive.h.
 * Das Programm soll das Modul als dynamische Laufzeitbibliothek nutzen.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "namesarchive.h"

#define MAX_BUFFER_LEN 100

char *inputName(const char *promptText, char *buffer, unsigned int bufferSize);

int main()
{
    char buffer[MAX_BUFFER_LEN];

    while((inputName("Namen hinzufuegen: ", buffer, MAX_BUFFER_LEN) != NULL) && (strlen(buffer) > 0))
    {
        if(addName(buffer))
            printf("%s wurde dem Archiv hinzugefuegt.\n", buffer);
        else
            printf("Fehler! %s konnte nicht hinzugefuegt werden.\n", buffer);
    }

    printf("\nNach Eingabe:\n");
    printNames();

    printf("\nNach Sortierung:\n");
    sortNames();
    printNames();
    printf("\n");

    while((inputName("Namen sortiert hinzufuegen: ", buffer, MAX_BUFFER_LEN) != NULL) && (strlen(buffer) > 0))
    {
        if(addNameSorted(buffer))
            printf("%s wurde dem Archiv hinzugefuegt.\n", buffer);
        else
            printf("Fehler! %s konnte nicht hinzugefuegt werden.\n", buffer);
    }

    printf("\nNach sortierter Eingabe:\n");
    printNames();
    printf("\n");

    while((inputName("Namen entfernen: ", buffer, MAX_BUFFER_LEN) != NULL) && (strlen(buffer) > 0))
    {
        if(removeName(buffer))
            printf("%s wurde aus dem Archiv entfernt.\n", buffer);
        else
            printf("Fehler! %s konnte nicht gefunden werden.\n", buffer);
    }

    printf("\nNach Entfernen:\n");
    printNames();

    return EXIT_SUCCESS;
}

char *inputName(const char *promptText, char *buffer, unsigned int bufferSize)
{
    printf("%s", promptText);
    if(fgets(buffer, bufferSize, stdin) != NULL)
    {
        if(buffer[strlen(buffer)-1] == '\n')
            buffer[strlen(buffer)-1] = '\0';
        else
            while(getchar() != '\n') {}

        return buffer;
    }
    else
    {
        return NULL;
    }
}