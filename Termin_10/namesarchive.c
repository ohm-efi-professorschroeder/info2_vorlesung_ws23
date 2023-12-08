#include "namesarchive.h"
#include "stringbst.h"

#include <string.h>

static StringBSTNode_t *root = NULL;

int addName(const char *name)
{
    root = insert(root, name);
    if(root)
        return 1;
    return 0;
}

int removeName(const char *name)
{
    if(findString(root, name))
    {
        root = delete(root, name);
        return 1;
    }

    return 0;
}

void printNames()
{
    if (root == NULL)
        return;

    inorderTraversal(root);
}

void clearArchive()
{
    freeBST(&root);
}

// TODO Ende