#include "namesarchive.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int numberOfNames = 0;
static Person archive[MAX_PERSONS];

int addPerson(const Person newPerson)
{
    if(numberOfNames >= MAX_PERSONS)
        return 0;

    archive[numberOfNames] = newPerson;
    numberOfNames++;

    return 1;
}

int removePerson(const Person person)
{
    // TODO

    return 0;
}

void printPersons()
{
    for(int i = 0; i < numberOfNames; i++)
    {
        printf("%s ist %d Jahre alt.\n", archive[i].name, archive[i].age);
    }
}

void sortPersons(SortType type)
{
    // TODO
}
