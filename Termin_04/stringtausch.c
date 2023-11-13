/*
 * Im folgenden Programm hat sich ein Fehler eingeschlichen. Eigentlich sollen die Zeichenketten vertauscht
 * ausgegeben werden. Allerdings klappt etwas nicht.
 *
 * 1. Lassen Sie zunächst das Programm laufen und finden Sie heraus, warum die Zeichenketten string1 und string2 nicht vertauscht werden.
 * 2. Sorgen Sie nun dafür, dass die Zeichenketten vertauscht werden. Ändern Sie dafür nur den Funktionsinhalt von tauscheStrings(...)
 * 3. Schreiben Sie nun eine neue Tauschfunktion, die die ursprünglich angedachte Funktionalität umsetzt. Es sollen also nur die Zeiger vertauscht
 *    werden. Der Array-Inhalt soll unverändert bleiben.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LEN 8

void tauscheStrings(char *zgr1, char *zgr2);
void tauscheStringsCpy(char *zgr1, char *zgr2);
void tauscheStringsZeiger(char **zgr1, char **zgr2);

// TODO

int main()
{
    char strings[][MAX_STRING_LEN] = {"String1", "String2"};
    char *string1 = strings[0];
    char *string2 = strings[1];

    printf("Vor Tausch:\n");
    printf("Inhalt von string1:    %s\n", string1);
    printf("Inhalt von string2:    %s\n", string2);
    printf("Inhalt von strings[0]: %s\n", strings[0]);
    printf("Inhalt von strings[1]: %s\n", strings[1]);

    //tauscheStringsCpy(string1, string2);
    tauscheStringsZeiger(&string1, &string2);

    printf("\nNach Tausch:\n");
    printf("Inhalt von string1: %s\n", string1);
    printf("Inhalt von string2: %s\n", string2);
    printf("Inhalt von strings[0]: %s\n", strings[0]);
    printf("Inhalt von strings[1]: %s\n", strings[1]);

    return EXIT_SUCCESS;
}

void tauscheStrings(char *zgr1, char *zgr2)
{
    char *tmp = zgr1;
    zgr1 = zgr2;
    zgr2 = tmp;
}

// TODO Anfang
void tauscheStringsCpy(char *zgr1, char *zgr2)
{
    char tmp[MAX_STRING_LEN];
    strncpy(tmp, zgr1, MAX_STRING_LEN);
    strncpy(zgr1, zgr2, MAX_STRING_LEN);
    strncpy(zgr2, tmp, MAX_STRING_LEN);
}

void tauscheStringsZeiger(char **zgr1, char **zgr2)
{
    char *tmp = *zgr1;
    *zgr1 = *zgr2;
    *zgr2 = tmp;
}
// TODO Ende