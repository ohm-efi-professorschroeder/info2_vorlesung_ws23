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

static int removeEntryAt(unsigned int idx)
{
    if(idx >= numberOfNames)
        return 0;

    memmove(archive+idx, archive+idx+1, sizeof(archive[0]) * (numberOfNames - idx - 1));

    numberOfNames--;

    return 1;
}

int removePerson(const Person person)
{
    for(int i = 0; i < numberOfNames; i++)
    {
        if((strcmp(archive[i].name, person.name) == 0) && (archive[i].age == person.age))
            return removeEntryAt(i);
    }

    return 0;
}

void printPersons()
{
    for(int i = 0; i < numberOfNames; i++)
    {
        printf("%s ist %d Jahre alt.\n", archive[i].name, archive[i].age);
    }
}

static int compareByName(const void *arg1, const void *arg2)
{
    const Person *person1 = (const Person *)arg1;
    const Person *person2 = (const Person *)arg2;

    int nameDiff = strcmp(person1->name, person2->name);

    if(nameDiff == 0)
        return person1->age - person2->age;
    else
        return nameDiff;
}

static int compareByAge(const void *arg1, const void *arg2)
{
    const Person *person1 = (const Person *)arg1;
    const Person *person2 = (const Person *)arg2;

    int ageDiff = person1->age - person2->age;

    if(ageDiff == 0)
        return strcmp(person1->name, person2->name);
    else
        return ageDiff;
}

void sortPersons(SortType type)
{
    int (*compareFunc)(const void *, const void *) = NULL;

    if(type == SORT_BY_NAME)
        compareFunc = compareByName;
    else if(type == SORT_BY_AGE)
        compareFunc = compareByAge;

    if(compareFunc != NULL)
        qsort(archive, numberOfNames, sizeof(archive[0]), compareFunc);
}