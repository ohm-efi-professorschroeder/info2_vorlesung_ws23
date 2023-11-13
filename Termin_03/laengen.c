/*
 * Was gibt folgendes Programm aus? Überlegen Sie sich erst Ihre Antworten.
 * Kompilieren und führen Sie erst danach das Programm aus.
 * Wie erklären Sie sich die Ausgaben?
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void gibLaengenAus(char string[]);

int main()
{
    char *string1    = "12345";
    char string2[]   = "12345";
    char string3[10] = "12345";

    printf("strlen(string1) = %2d\n", (int)strlen(string1));  // 5
    printf("strlen(string2) = %2d\n", (int)strlen(string2));  // 5
    printf("strlen(string3) = %2d\n", (int)strlen(string3));  // 5
    printf("\n");
    printf("sizeof(string1) = %2d\n", (int)sizeof(string1));    // 8
    printf("sizeof(string2) = %2d\n", (int)sizeof(string2));    // 6
    printf("sizeof(string3) = %2d\n", (int)sizeof(string3));    // 10
    printf("\n");
    printf("gibLaengenAus(string3):\n");

    gibLaengenAus(string3);

    return EXIT_SUCCESS;
}

void gibLaengenAus(char string[])
{
    printf("strlen(string)  = %2d\n", (int)strlen(string));   // 5
    printf("sizeof(string)  = %2d\n", (int)sizeof(string));     // 8
}
