#include "namesarchive.h"
#include "../../Termin_10/stringbst.h"

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

int loadArchive(const char *path)
{
    FILE *f = fopen(path, "r");

    if(f == NULL)
        return 0;

    char buffer[MAX_NAME_LEN];
    while(fgets(buffer, MAX_NAME_LEN, f) != NULL)
    {
        if(buffer[strlen(buffer)-1] == '\n')
            buffer[strlen(buffer)-1] = '\0';

        if(addName(buffer) == 0)
        {
            fclose(f);
            return 0;
        }
    }

    return 1;
}

static void writeNode(StringBSTNode_t *root, FILE *f)
{
    if(root && f)
    {
        fprintf(f, "%s\n", root->string);
        writeNode(root->left, f);
        writeNode(root->right, f);
    }
}

int saveArchive(const char *path)
{
    FILE *f = fopen(path, "w+");
    if(f == NULL)
        return 0;

    writeNode(root, f);

    fclose(f);

    return 1;
}

// TODO Ende