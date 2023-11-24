#ifndef NAMEARCHIVE_H
#define NAMEARCHIVE_H

#define MAX_PERSONS 100
#define MAX_NAME_LEN 100

typedef struct 
{
    char name[MAX_NAME_LEN];
    unsigned short age;
} Person;

typedef enum {SORT_BY_NAME, SORT_BY_AGE} SortType;

// Fügt eine Person hinzu.
int addPerson(const Person newPerson);
// Entfernt eine Person aus dem Archiv, nur wenn Name und Alter in einem Eintrag übereinstimmen.
int removePerson(const Person person);
// Gibt die enthaltenen Personen zeilenweise in der Form "<Name> ist <Alter> Jahre alt." aus.
void printPersons();
// Sortiert das Archiv je nach Sortierungsart entweder nach Name und bei Übereinstimmung nach Alter oder umgekehrt.
void sortPersons(SortType type);

#endif