#include "namesarchive.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// TODO Anfang
static char names[MAX_NAMES][MAX_NAME_LEN];
static int nameCount = 0;

int addName(const char *name)
{
    if(nameCount >= MAX_NAMES)
        return 0;

    strncpy(names[nameCount], name, MAX_NAME_LEN);
    names[nameCount][MAX_NAME_LEN-1] = '\0';
    nameCount++;

    return 1;
}

int compareStr(const void* a, const void* b)
{
    return strcmp((const char*)a, (const char*)b);
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
    // ACHTUNG: Ineffizient
    int ret = addName(name);
    sortNames();
    return ret;
    // TODO: Einsortieren
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

    for(int i = stelle; i < nameCount; i++)
    {
        if(i < nameCount-1)
        {
            strncpy(names[i], names[i+1], MAX_NAME_LEN);
        }
    }
    nameCount--;
    return 1;
}

// TODO Ende