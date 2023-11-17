#include "namesarchive.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// TODO Anfang
static char** names = NULL;
static int nameCount = 0;

int allocateMemory(const int strLen, char** str)
{
    if((names = (char**) realloc(names, sizeof(char*) * (nameCount+1))) == NULL)
        return 0;

    if((*str = (char*) malloc(sizeof(char) * strLen)) == NULL)
        return 0;

    return 1;
}

int addName(const char *name)
{
    char *nameCpy = 0;
    if(!allocateMemory(strlen(name)+1, &nameCpy))
        return 0;

    strcpy(nameCpy, name);
    names[nameCount] = nameCpy;
    nameCount++;

    return 1;
}

int compareStr(const void* a, const void* b)
{
    return strcmp(*(const char**)a, *(const char**)b);
}

void sortNames()
{
    qsort(names, nameCount, sizeof(names[0]), compareStr);
}

void printNames()
{
    for(int i = 0; i < nameCount; i++)
    {
        printf("%s\n", names[i]);
    }
}

int addNameSorted(const char *name)
{
    char *nameCpy = 0;
    if(!allocateMemory(strlen(name)+1, &nameCpy))
        return 0;

    int position = 0;
    while(position < nameCount && strcmp(names[position], name) < 0)
        position++;

    for(int i = nameCount; i > position; i--)
        names[i] = names[i-1];

    strcpy(nameCpy, name);
    names[position] = nameCpy;
    nameCount++;

    return 1;
}

int removeName(const char *name)
{
    int stelle = -1;

    for(int i = 0; i < nameCount; i++)
    {
        if(strcmp(names[i], name) == 0)
            stelle = i;
    }

    if(stelle == -1)
        return 0; // Name nicht voranden

    free(names[stelle]);

    for(int i = stelle; i < nameCount; i++)
    {
        if(i < nameCount-1)
        {
            names[i] = names[i+1];
        }
    }
    nameCount--;
    return realloc(names, sizeof(char*) * nameCount) != NULL;
}

void clearArchive()
{
    for(int i = 0; i < nameCount; i++)
        free(names[i]);
    free(names);
}

// TODO Ende