/*
 * 1. Ergänzen Sie das untenstehende Programm, indem Sie wieder ein Namensarchiv-Modul in der namesarchive.h und der namesarchive.c
 *    implementieren. Die Funktionalität orientiert sich wieder an der letzten Übung und kann im Detail in der namesarchive.h
 *    eingesehen werden. Diesmal soll allerdings eine rein dynamische Speicherverwaltung implementiert werden.
 * 2. Bauen Sie außerdem das Programm aus der vorherigen Übung ohne Änderungen neu (also mit statischen Arrays). Tauschen Sie nun
 *    nur die Shared-Library mit der in dieser Übung erstellten Version aus. Die gebaute ausführbare Datei bleibt also unverändert.
 *    Sie können sehen, dass das alte Programm nach wie vor läuft, ohne neu erstellt werden zu müssen. Wenn Sie allerdings einen
 *    längeren Namen eingeben, wird dieser nicht mehr abgeschnitten. Es wird also die neue Bibliothek genutzt.
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

    printf("\nGebe Speicher frei ...\n");
    clearArchive();

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