/*
 * Ergänzen Sie im untenstehenden Programm die fehlenden Funktionen. addiereText bekommt dabei eine Folge von
 * Zahlenwörtern kleiner zehn übergeben und ermittelt daraus die Summe. Groß- und Kleinschreibung soll keine Rolle spielen.
 * Zudem liefert die Funktion 0, wenn ein Zahlenwort nicht aufgelöst werden konnte, ansonsten 1.
 *
 * 1. Beispielhafter Programmablauf:
 * >> Addiere: Fuenf achT SIEBEN
 * Das Ergebnis lautet 20.
 *
 * 2. Beispielhafter Programmablauf:
 * >> Addiere: fuenf achtzehn sieben
 * Falsche Eingabe.
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "eingabe.h"

#define MAX_EINGABE_LEN 100

char *wandleKlein(char *text);                  // Gruppe 1
int wandleZahl(const char *wort);               // Gruppe 2
int addiereText(const char *text, int *erg);    // Gruppe 3

int main()
{
    char eingabeText[MAX_EINGABE_LEN];
    int erg;

    gibTextEin("Addiere: ", eingabeText, MAX_EINGABE_LEN);

    if(addiereText(eingabeText, &erg))
        printf("Das Ergebnis lautet %d.\n", erg);
    else
        printf("Falsche Eingabe.\n");

    return EXIT_SUCCESS;
}

// TODO Anfang
char *wandleKlein(char *text)
{
    for(int i = 0; i < MAX_EINGABE_LEN; i++)
    {
        if(text[i] >= 'A' && text[i] <= 'Z')
            text[i] += 32;
    }
    return text;
}

int wandleZahl(const char *wort)
{
    char vergleichworter[][MAX_EINGABE_LEN] = {"eins", "zwei", "drei", "vier","fuenf","sechs","sieben","acht","neun","zehn"};

    for(int i = 0; i < 10; i++)
    {
        if(strncmp(vergleichworter[i], wort, MAX_EINGABE_LEN) == 0)
        {
            return i+1;
        }
    }

    return 0;
}

int addiereText(const char *text, int *erg)
{
    wandleKlein((char*) text);

    *erg = 0;

    const char* teiler = " ";

    char* token = strtok((char*)text, teiler);
    if(token == NULL)
        return 0;

    do
    {
        if(wandleZahl(token))
        {
            *erg += wandleZahl(token);
        }
        else
        {
            return 0;
        }
    }  while((token = strtok(NULL, teiler)) != NULL);

    return 1;
}

// TODO Ende