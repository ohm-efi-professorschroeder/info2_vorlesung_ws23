#include "stringlist.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO Beginn

StringListNode_t* createNode(const char* string)
{
    StringListNode_t *node = (StringListNode_t*)calloc(1, sizeof(StringListNode_t));
    if(node != NULL)
    {
        node->string = (char *) calloc(strlen(string) + 1, sizeof(char));
        if (node->string != NULL)
        {
            strcpy(node->string, string);
        }
        else
        {
            free(node);
            node = NULL;
        }
    }

    return node;
}

int pushBack(StringListNode_t** head, const char* string)
{
    StringListNode_t * newNode = createNode(string);
    if(newNode == NULL)
        return 0; // Fehlerfall

    // Liste bisher leer...
    if(*head == NULL)
    {
        *head = newNode;
        return 1;
    }

    // Liste nicht leer
    StringListNode_t* tempNode = *head;
    while(tempNode->next != NULL)
        tempNode = tempNode->next;
    tempNode->next = newNode;
    newNode->prev = tempNode;

    return 1;
}

void removeNode(StringListNode_t** head, StringListNode_t* node)
{
    if(node == NULL)
        return;

    StringListNode_t *next = node->next;
    StringListNode_t *prev = node->prev;

    if (next)
        next->prev = prev;
    if (prev)
        prev->next = next;
    if (*head == node)
        *head = next;

    freeNode(&node);
}

void printList(StringListNode_t const* head)
{
    while(head != NULL)
    {
        printf("...%s\n", head->string);
        head = head->next;
    }
}

StringListNode_t* findString(StringListNode_t* head, const char *string)
{
    while(head != NULL && strcmp(head->string, string) != 0)
    {
        head = head->next;
    }

    return head;
}

void freeNode(StringListNode_t** node)
{
    free((*node)->string);
    free(*node);
    *node = NULL;
}

void freeList(StringListNode_t** head)
{
    while(*head != NULL)
    {
        StringListNode_t *next = (*head)->next;
        freeNode(&next);
        *head = next;
    }
}

// TODO Ende
