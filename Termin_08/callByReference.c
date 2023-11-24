/*
 * Was gibt folgendes Programm aus? Erst überlegen, dann ausführen.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_TEXT_LEN 100

typedef struct
{
    char text1[MAX_TEXT_LEN];
    char *text2;
    int number;
} MyStruct;

void modify1(MyStruct arg);
void modify2(MyStruct *arg);

int main()
{
    char text[MAX_TEXT_LEN] = "Text 2";
    MyStruct someStruct = {"Text 1", text, 15};
    
    printf("someStruct.text1  = %s\n", someStruct.text1);  // Text 1
    printf("someStruct.text2  = %s\n", someStruct.text2);  // Text 2
    printf("someStruct.number = %d\n", someStruct.number); // 15
    modify1(someStruct);

    printf("\nNach modify1:\n"); // selbes wie 1, weil call-by-value
    printf("someStruct.text1  = %s\n", someStruct.text1);
    printf("someStruct.text2  = %s\n", someStruct.text2);
    printf("someStruct.number = %d\n", someStruct.number);
    modify2(&someStruct);

    printf("\nNach modify2:\n");
    printf("someStruct.text1  = %s\n", someStruct.text1);
    printf("someStruct.text2  = %s\n", someStruct.text2);
    printf("someStruct.number = %d\n", someStruct.number);

    return EXIT_SUCCESS;
}

void modify1(MyStruct arg)
{
    strcpy(arg.text1, "Neuer Text 1");
    strcpy(arg.text2, "Neuer Text 2");
    arg.number = 100;
}

void modify2(MyStruct *arg)
{
    strcpy(arg->text1, "Wieder neuer Text 1");
    strcpy(arg->text2, "Wieder neuer Text 2");
    arg->number = 200;
}