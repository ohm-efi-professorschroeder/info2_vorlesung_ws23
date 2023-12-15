#include "stringbst.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO Beginn

StringBSTNode_t* createNode(const char* string)
{
    StringBSTNode_t *node = (StringBSTNode_t*)calloc(1, sizeof(StringBSTNode_t));
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

StringBSTNode_t* insert(StringBSTNode_t* root, const char* string)
{
    if(root == NULL)
        return createNode(string);

    if(strcmp(string, root->string) < 0)
        root->left = insert(root->left, string);
    else if (strcmp(string, root->string) > 0)
        root->right = insert(root->right, string);

    return root;
}

void inorderTraversal(const StringBSTNode_t *root)
{
    if(root != NULL)
    {
        inorderTraversal(root->left);
        printf("...%s\n", root->string);
        inorderTraversal(root->right);
    }

}

StringBSTNode_t* findString(StringBSTNode_t *root, const char *string)
{
    if(root != NULL)
    {
        if(strcmp(string, root->string) < 0)
            return findString(root->left, string);
        else if(strcmp(string, root->string) > 0)
            return findString(root->right, string);
        else
            return root;
    }
    return NULL;
}

StringBSTNode_t* findMin(StringBSTNode_t* root)
{
   if(root && root->left)
       return findMin(root->left);
   return root;
}

StringBSTNode_t* delete(StringBSTNode_t *root, const char* string)
{
    if(root == NULL)
        return NULL;

    if(strcmp(string, root->string) < 0)
    {
        root->left = delete(root->left, string);
    }
    else if(strcmp(string, root->string) > 0)
    {
        root->right = delete(root->right, string);
    }
    else
    {
        // Knoten hat ein oder kein Kind
        if(root->left == NULL)
        {
            // rechts löschen
            StringBSTNode_t *tmp = root->right;
            freeNode(&root);
            return tmp;
        }
        else if(root->right == NULL)
        {
            // links löschen
            StringBSTNode_t *tmp = root->left;
            freeNode(&root);
            return tmp;
        }
        else
        {
            // Nachfolgerwert kopieren und im rechten Teilbaum löschen
            StringBSTNode_t *tmp = findMin(root->right);
            char *tmpString = root->string;
            root->string = tmp->string;
            tmp->string = tmpString;
            root->right = delete(root->right, tmp->string);
        }
    }
    return root;
}

void freeNode(StringBSTNode_t** node)
{
    if(*node)
    {
        free((*node)->string);
        free(*node);
        *node = NULL;
    }
}

void freeBST(StringBSTNode_t** root)
{
    if(*root)
    {
        freeBST(&(*root)->left);
        freeBST(&(*root)->right);
        freeNode(root);
    }
}

// TODO Ende
