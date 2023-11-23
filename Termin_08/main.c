/*
 * Unser Namensarchiv soll nun Personen verwalten. Eine Person soll aus einem Namen und einem Alter bestehen.
 * Implementieren Sie wieder das entsprechende Modul in der namesarchive.h imd namesarchive.c. Eine sortierte 
 * Eingabe entfällt diesmal der Einfachheit halber.
 * 
 * Wieso ist eine Implementierung mit Strukturen notwendig, wenn das Archiv sortiert werden soll? 
 * (Alternative wäre getrennte Datenhaltung von Namen und Altersangaben.)
 * 
 * Weitere Details zur Implementierung finden Sie wieder in der namesarchive.h.
 * 
 * Warum kann nun die neue Shared-Library nicht einfach eine alte Version aus einer vorherigen Übung ersetzen?
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "namesarchive.h"

Person getPerson(const char *name, int age);
void testAdd(const char *name, int age);
void testRemove(const char *name, int age);

int main()
{
    testAdd("Zorro",  35);
    testAdd("Werner", 15);
    testAdd("Susi",   55);
    testAdd("Adam",   45);
    testAdd("Berta",  65);
    testAdd("Aaron",  20);

    printf("\nNach Hinzufuegen:\n");
    printPersons();

    printf("\nNach Sortierung nach Alter:\n");
    sortPersons(SORT_BY_AGE);
    printPersons();
    printf("\n");

    printf("\nNach Sortierung nach Name:\n");
    sortPersons(SORT_BY_NAME);
    printPersons();
    printf("\n");

    testRemove("Zorro", 35);
    testRemove("Aaron", 20);
    testRemove("Gerd",  75);

    printf("\nNach Entfernen:\n");
    printPersons();

    return EXIT_SUCCESS;
}

void testAdd(const char *name, int age)
{
    Person person = getPerson(name, age);
    
    printf("Versuche %s (%d Jahre alt) hinzuzufuegen.\n", name, age);
    
    if(addPerson(person))
        printf("Erfolgreich hinzugefuegt!\n");
    else
        printf("Fehler beim Hinzufuegen!\n");
}

void testRemove(const char *name, int age)
{
    Person person = getPerson(name, age);

    printf("Versuche %s (%d Jahre alt) zu entfernen.\n", name, age);

    if(removePerson(person))
        printf("Erfolgreich entfernt!\n");
    else
        printf("Fehler beim Entfernen!\n");

}

Person getPerson(const char *name, int age)
{
    Person person;
    strncpy(person.name, name, MAX_NAME_LEN);
    person.name[MAX_NAME_LEN-1] = '\0';
    person.age = age;
    return person;
}