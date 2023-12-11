#ifndef INFO2_LECTURE_STRINGBST_H
#define INFO2_LECTURE_STRINGBST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct StringBSTNode
{
    char *string;
    struct StringBSTNode *left;
    struct StringBSTNode *right;
} StringBSTNode_t;

// Erstelle einen neuen Baumknoten mit dem übergebenen Wert.
StringBSTNode_t* createNode(const char* string);
// Füge einen neuen Baumknoten mit dem übergebenen Wert in den Baum ein (gibt die Wurzel des neuen Baums zurück).
StringBSTNode_t* insert(StringBSTNode_t* root, const char* string);
// Findet den Baumknoten mit dem übergebenen Wert (gibt NULL zurück, falls der Wert nicht gefunden werden kann).
StringBSTNode_t* findString(StringBSTNode_t* root, const char *string);
// Findet das Minimum-Element im Baum und gibt es zurück.
StringBSTNode_t* findMin(StringBSTNode_t* root);
// Entfernt den Baumknoten mit dem übergebenen Wert (gibt die Wurzel des neuen Baums zurück).
StringBSTNode_t* delete(StringBSTNode_t *root, const char* string);
// Traversiert die Baumknoten in der Reihenfolge ihrer Werte und gibt sie aus.
void inorderTraversal(const StringBSTNode_t *root);
// Gibt den Speicher des übergebenen Elements frei.
void freeNode(StringBSTNode_t** node);
// Gibt den Speicher des gesamten Baums frei.
void freeBST(StringBSTNode_t** head);

#endif //INFO2_LECTURE_STRINGBST_H
