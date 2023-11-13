/*
 * Das folgende Programm prüft auf einfache Weise, ob die eingegebene Zahl eine Primzahl ist. 
 * Ergänzen Sie eine rekursive Prüffunktion istPrimzahlRek, die innerhalb der istPrimzahl-Funktion 
 * aufgerufen wird und den iterativen vorhandenen Ansatz ersetzt.
 */

#include <stdio.h>

int gibPositiveZahlEin(const char *text)
{
    int zahl;

    printf("%s", text);

    while((scanf("%d", &zahl) != 1) || (zahl <= 0))
    {
        while(getchar() != '\n') {}
        printf("Fehler! %s", text);
    }

    return zahl;
}

int istPrimzahlRek(unsigned int zahl, unsigned int teiler)
{
    if(zahl == 1 || teiler < zahl/2)
    {
        if(zahl % teiler == 0)
        {
            return 0;
        }
        return istPrimzahlRek(zahl, teiler+1);
    }
    return 1;
}

int istPrimzahl(unsigned int zahl)
{
    return istPrimzahlRek(zahl, 2);
}


int main()
{
    unsigned int zahl = 0;

    zahl = gibPositiveZahlEin("Geben Sie eine ganze, positive Zahl ein: ");

    printf("Die Zahl %d ist ", zahl);

    if(!istPrimzahl(zahl))
        printf("k");
    
    printf("eine Primzahl.\n");

    return 0;
}