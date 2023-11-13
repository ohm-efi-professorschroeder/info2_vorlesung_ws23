/*
 * Ergänzen Sie in der Datei eingabe.h bzw. eingabe.c die Funktion gibTextEin, die eine Zeichenkette übergeben bekommt, 
 * die vor der Eingabe angezeigt wird, einen Puffer, in dem die eingelesene Zeichenkette gespeichert wird, 
 * und die Größe des Puffers, die die Anzahl an einzulesenden Zeichen darstellt (inklusive Zeilenumbruch und abschließendem 
 * Null-Zeichen). Die Funktion soll genau eine Zeile Text einlesen. Zudem soll die Funktion prüfen, ob noch Zeichen im 
 * Eingabepuffer liegen und diesem Fall den Eingabepuffer leeren. Im Fehlerfall gibt die Funktion 0 zurück, ansonsten 1. Die 
 * eingelesene Zeichenkette soll den Zeilenumbruch zur Bestätigung der Eingabe nicht enthalten. Nutzen Sie zum Einlesen bitte fgets.
 */

#include <stdio.h>
#include <stdlib.h>
#include "eingabe.h"

#define MAX_EINGABE_LEN 10

int main()
{
    char testChar;
    char eingabeText[MAX_EINGABE_LEN];

    printf("Zum Testen bitte bei einem Programmdurchlauf weniger und beim naechsten mehr als %d Zeichen eingeben und jeweils mit ENTER bestaetigen.\n", MAX_EINGABE_LEN-1);

    if(gibTextEin("Eingabe: ", eingabeText, MAX_EINGABE_LEN))
    {
        printf("Die Eingabe lautet \"%s\". Es sollte kein Zeilenumbruch auftreten.\n", eingabeText);
        printf("Wenn alles korrekt implementiert ist, sollte das Programm jetzt nur auf ein ENTER warten und die Ausgabe dann unten leer sein.\n");
        printf("Rest im Eingabepuffer: ");
        while((testChar = getchar()) != '\n')
        {
            printf("%c", testChar);
        }
        printf("\n");
    }
    else
    {
        printf("Beim Einlesen ist ein Fehler aufgetreten.\n");

        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}