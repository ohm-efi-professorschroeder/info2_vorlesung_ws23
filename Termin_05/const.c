/*
 * Im folgenden Programm soll eine Eingabe nur bestehend aus Zahlen als String eingelesen werden. Die einzelnen Zahlen sollen extrahiert, konvertiert
 * und deren Summe ausgegeben werden.
 *
 * 1. Ergänzen Sie in den vorhandenen Funktionen zunächst das Schlüsselwort const bei geeigneten Parametern.
 * 2. Implementieren Sie nun die Funktion konvertiereZahlen, die einen String übergeben bekommt, die enthaltenen Zahlen nach int konvertiert und in einem
 *    int-Array speichert. Der String soll nicht verändert werden. Die Funktion soll die Anzahl an extrahierten Zahlen zurückgeben oder 0, falls Wörter enthalten
 *    sind, die keine Zahlen sind. Sehen Sie sich für die genauen Anforderung an die Funktion auch unten deren Verwendung in der main-Funktion an. Vergessen Sie
 *    nicht, Parameter mit dem Schlüsselwort const zu markieren, wenn es Sinn ergibt.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PUFFER_GROESSE 100


char *gibTextEin(const char *ausgabeText, char *puffer, const unsigned int groesse);
void gibSummeAus(const unsigned int zahlen[], const unsigned int anzahl);
int konvertiereZahlen(const char *string, unsigned int zahlen[], const unsigned int groesse);

int main()
{
    char eingabe[PUFFER_GROESSE];
    char ausgabeText[] = "Geben Sie Zahlen ein: ";
    unsigned int zahlen[PUFFER_GROESSE];
    unsigned int vorhandeneZahlen = 0;

    gibTextEin(ausgabeText, eingabe, PUFFER_GROESSE);

    vorhandeneZahlen = konvertiereZahlen(eingabe, zahlen, PUFFER_GROESSE);

    gibSummeAus(zahlen, vorhandeneZahlen);

    return EXIT_SUCCESS;
}

char *gibTextEin(const char* ausgabeText /* INPUT */, char *puffer /*OUTPUT*/, const unsigned int groesse /*INPUT*/)
{
    printf("%s", ausgabeText);
    fgets(puffer, groesse, stdin);

    if(puffer[strlen(puffer)-1] == '\n')
        puffer[strlen(puffer)-1] = '\0';
    else
        while(getchar() != '\n') {}

    return puffer;
}

void gibSummeAus(const unsigned int zahlen[] /*INPUT*/, const unsigned int anzahl /*INPUT*/)
{
    int summe = 0;

    if(anzahl > 0)
    {
        printf("%d", zahlen[0]);
        summe = zahlen[0];
    }

    for(int i = 1; i < anzahl; i++)
    {
        printf(" + %d", zahlen[i]);
        summe += zahlen[i];
    }

    if(anzahl > 0)
        printf(" = %d\n", summe);
    else
        printf("%s", "Keine Werte vorhanden!\n");
}

int wandleZahl(const char *wort)
{
    char vergleichworter[][PUFFER_GROESSE] = {"eins", "zwei", "drei", "vier","fuenf","sechs","sieben","acht","neun","zehn"};

    for(int i = 0; i < 10; i++)
    {
        if(strncmp(vergleichworter[i], wort, PUFFER_GROESSE) == 0)
        {
            return i+1;
        }
    }

    return 0;
}

int konvertiereZahlen(const char *string, unsigned int zahlen[], const unsigned int groesse)
{
    const char* teiler = " ";

    char* token = strtok((char*)string, teiler);
    if(token == NULL)
        return 0;

    int i = 0;
    do
    {
        if(wandleZahl(token))
        {
            zahlen[i] = wandleZahl(token);
            i++;
        }
        else
        {
            return 0;
        }
    }  while((token = strtok(NULL, teiler)) != NULL);
    return i;
}