#include "namesarchive.h"
#include "stringlist.h"

#include <string.h>

static StringListNode_t *head = NULL;

int addName(const char *name)
{
    return pushBack(&head, name);
}

int removeName(const char *name)
{
    StringListNode_t *previous = NULL;
    StringListNode_t *foundNode = findString(head, &previous, name);

    if (foundNode != NULL)
    {
        if(previous == NULL)
            removeFirst(&head);
        else
            removeAfter(previous);
        return 1;
    }

    return 0;
}

void printNames()
{
    if (head == NULL)
        return;

    printList(head);
}

void clearArchive()
{
    freeList(&head);
}

// TODO Ende