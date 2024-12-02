#ifndef INFO2_LECTURE_STRINGLIST_H
#define INFO2_LECTURE_STRINGLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct StringListNode
{
    char *string;
    struct StringListNode *next;
    struct StringListNode *prev;
} StringListNode_t;

// Erstelle einen neuen StringListNode mit dem übergebenen Wert.
StringListNode_t* createNode(const char* string);
// Füge einen neuen StringListNode mit dem übergebenen Wert am Ende der Liste ein (modifiziert ggf. head).
int pushBack(StringListNode_t** head, const char* string);
// Findet den ersten StringListNode mit dem übergebenen Wert. Gibt NULL zurück, falls der Wert nicht gefunden wurde.
StringListNode_t* findString(StringListNode_t* head, const char *string);
// Entfernt einen Eintrag der Liste (modifiziert ggf. head).
void removeNode(StringListNode_t** head, StringListNode_t* node);
// Gibt die Liste zeilenweise aus.
void printList(StringListNode_t const* head);
// Gibt den Speicher des übergebenen Elements frei.
void freeNode(StringListNode_t** node);
// Gibt den Speicher der gesamten Liste frei. 
void freeList(StringListNode_t** head);

#endif //INFO2_LECTURE_STRINGLIST_H
