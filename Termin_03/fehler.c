/*
 * Untersuchen Sie das folgende Programm zunächst ohne es zu kompilieren oder auszuführen.
 * Welche Funktionen sind fehlerfrei?
 * Handelt es sich im Falle eines Fehlers um einen Laufzeitfehler oder um einen Compiler-Fehler?
 *
 * Hinweise:
 * Compiler-Fehler treten beim Kompilieren des Programms auf. Das Programm lässt sich also
 * gar nicht erst übersetzen.
 * Bei Laufzeitfehlern lässt sich das Programm (u.U. mit Warnungen) übersetzen. Der Fehler tritt
 * erst zur Laufzeit auf. Auch wenn der Fehler nicht immer auftritt bzw. das Programm zum Absturz
 * bringt, handelt es sich dennoch um einen Laufzeitfehler. Beliebte Laufzeitfehler sind z.B. Pufferüberläufe.
 */

#include <stdio.h>
#include <stdlib.h>

void kopiereString1()
{
    char string1[] = "123456\n";
    char string2[] = "789\n";
    char *stringZgr1 = string1;
    char *stringZgr2 = string2;

    while((*stringZgr2++ = *stringZgr1++) != '\0');

    printf("%s", string1);
    printf("%s", string2);
}

void kopiereString2()
{
    char string1[] = "123456\n";
    char string2[] = "789\n";
    char *stringZgr1 = string1;
    char *stringZgr2 = string2;

    while((*stringZgr1++ = *stringZgr2++) != '\0');

    printf("%s", string1);
    printf("%s", string2);
}

void kopiereString3()
{
    char string1[] = "123456\n";
    char string2[] = "789\n";

    while((*string1++ = *string2++) != '\0');

    printf("%s", string1);
    printf("%s", string2);
}

void kopiereString4()
{
    char *string1 = "123456\n";
    char *string2 = "789\n";

    while((*string1++ = *string2++) != '\0');

    printf("%s", string1);
    printf("%s", string2);
}

int main()
{
    printf("kopiereString1:\n");
    kopiereString1();

//    printf("kopiereString2:\n");
//    kopiereString2();
//
//    printf("kopiereString3:\n");
//    kopiereString3();
//
//    printf("kopiereString4:\n");
//    kopiereString4();
}