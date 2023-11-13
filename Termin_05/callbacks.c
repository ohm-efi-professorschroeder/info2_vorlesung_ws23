#include <stdlib.h>
#include <stdio.h>
#include <signal.h>


void behandleInterrupt(int signalNr);
void behandleRechenfehler(int signalNr);
void behandleAbbruch(int signalNr);
void behandleUnerlaubteOp(int signalNr);

int main()
{
    signal(SIGINT, behandleInterrupt);
    signal(SIGFPE, behandleRechenfehler);
    signal(SIGABRT, behandleAbbruch);
    signal(SIGILL, behandleUnerlaubteOp);

    while(1)
    {
        unsigned int dummyZahl = 1;

        printf("Endlossschleife! CTRL + C loest Interrupt aus und bricht das Programm ab ...\n");
        printf("Weiter mit ENTER ...");
        while(getchar() != '\n') {}
        
        for(int i = 10000; i >= 0; i--)
        {
            printf("%d / %d = %d\n", dummyZahl, i, dummyZahl / i);
        }
    }

    return EXIT_SUCCESS;
}

void behandleInterrupt(int signalNr)
{
    printf("\nInterrupt wurde empfangen. Das Programm wird nun beendet.\n");
    exit(0);
}

void behandleRechenfehler(int signalNr)
{
    printf("\n!!! ACHTUNG: Rechenfehler !!!\n");
}

void behandleAbbruch(int signalNr)
{
    printf("\nProgrammabbruch!\n");
}

void behandleUnerlaubteOp(int signalNr)
{
    printf("\nUnerlaubte Operation!\n");
}