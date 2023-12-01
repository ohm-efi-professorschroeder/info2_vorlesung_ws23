#ifndef INFO2_LECTURE_STRINGLIST_H
#define INFO2_LECTURE_STRINGLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct StringListNode
{
    char *string;
    struct StringListNode *next;
} StringListNode_t;

// Erstelle einen neuen StringListNode mit dem übergebenen Wert.
StringListNode_t* createNode(const char* string);
// Füge einen neuen StringListNode mit dem übergebenen Wert am Ende der Liste ein.
int pushBack(StringListNode_t** head, const char* string);
// Findet den ersten StringListNode mit dem übergebenen Wert. Der übergebene Zeiger previous wird auf den Vorgänger des gefundenen Elements gesetzt.
StringListNode_t* findString(StringListNode_t* head, StringListNode_t** previous, const char *string);
// Entfernt den ersten Eintrag der Liste (modifiziert head).
void removeFirst(StringListNode_t** head);
// Entfernt den Eintrag nach dem übergebenen Element. node darf nicht der erste Eintrag der Liste sein.
void removeAfter(StringListNode_t *node);
// Gibt die Liste zeilenweise aus.
void printList(StringListNode_t const* head);
// Gibt den Speicher des übergebenen Elements frei.
void freeNode(StringListNode_t** node);
// Gibt den Speicher der gesamten Liste frei. 
void freeList(StringListNode_t** head);

#endif //INFO2_LECTURE_STRINGLIST_H
