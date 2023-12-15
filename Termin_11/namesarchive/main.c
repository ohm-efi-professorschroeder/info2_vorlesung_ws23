/*
 * Verwenden Sie Ihre Lösung für das Namensarchiv mittels eines binären Suchbaums. Ergänzen Sie das Modul um zwei Funktionen,
 * mit denen das bestehende Archiv um Namen erweitert wird, die in einer vorhandenen Textdatei stehen, bzw. den Inhalt des Archivs 
 * in eine bestimmte Textdatei sortiert speichern. Details entnehmen Sie wieder der namesarchive.h.
 * 
 * Welcher Nachteil ergibt sich für einen binären Suchbaum, wenn beliebige Namen zunächst aus einer Datei eingelesen werden, 
 * sortiert wieder in Datei geschrieben werden und anschließend wieder neu aus der Datei geladen werden? 
 * (Also im Prinzip bei der zweiten Ausführung des untenstehenden Programms)
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
    const char *filePath = "names.txt";

    if(!loadArchive(filePath))
    {
        printf("Die Textdatei %s konnte nicht geladen werden.\n", filePath);
    }

    printf("\nNach Laden:\n");
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
    printf("\n");

    if(saveArchive(filePath))
    {
        printf("Archiv erfolgreich unter %s gespeichert.\n", filePath);
    }
    else
    {
        printf("Fehler beim Speichern des Archivs unter %s.\n", filePath);
    }

    printf("\nGebe Speicher frei ...\n");
    clearArchive();

    printf("Beende Programm ...\n");

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