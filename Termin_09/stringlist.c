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
    StringListNode_t * tempNode = *head;
    while(tempNode->next != NULL)
        tempNode = tempNode->next;
    tempNode->next = newNode;

    return 1;
}

void removeFirst(StringListNode_t** head)
{
    if(*head != NULL)
    {
        StringListNode_t *temp = (*head)->next;
        free(*head);
        *head = temp;
    }
}

void removeAfter(StringListNode_t *node)
{
    if(node != NULL && node->next != NULL)
    {
        StringListNode_t *temp = node->next->next;
        free(node->next);
        node->next = temp;
    }
}

void printList(StringListNode_t const* head)
{
    while(head != NULL)
    {
        printf("...%s\n", head->string);
        head = head->next;
    }
}

StringListNode_t* findString(StringListNode_t* head, StringListNode_t** previous, const char *string)
{
    return NULL;
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
