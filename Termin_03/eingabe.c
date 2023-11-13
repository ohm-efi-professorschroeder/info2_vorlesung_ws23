// TODO Anfang
#include <stdio.h>
#include <string.h>

int gibTextEin(char* prompt, char eingabeText[], int laenge)
{
    printf("%s", prompt);
    if (fgets(eingabeText, laenge, stdin) != NULL)
    {
        if(eingabeText[strlen(eingabeText)-1] == '\n')
        {
            eingabeText[strlen(eingabeText)-1] = '\0';
        }
        else
        {
            while(getchar() != '\n'){}
        }
        return 1;
    }
    return 0;
}

// TODO Ende