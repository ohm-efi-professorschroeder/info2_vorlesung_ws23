#include "bst.h"

#include <stdlib.h>
#include <string.h>

// TODO---->

BSTNode_t *createNode(const void *data, int numBytes, comp_func_t comp, print_func_t print)
{
    BSTNode_t *node = (BSTNode_t *) calloc(1, sizeof(BSTNode_t));
    if (node != NULL)
    {
        node->data = calloc(numBytes, 1);
        if (node->data != NULL)
        {
            memcpy(node->data, data, numBytes);
            node->comp = comp;
            node->print = print;
        } else
        {
            free(node);
            node = NULL;
        }
    }

    return node;
}

BSTNode_t* insert(BSTNode_t* root, const void* data, int numBytes, comp_func_t comp, print_func_t print)
{
    if(root == NULL)
        return createNode(data, numBytes, comp, print);

    if(root->comp(data, root->data) < 0)
        root->left = insert(root->left, data, numBytes, comp, print);
    else if (root->comp(data, root->data) > 0)
        root->right = insert(root->right, data, numBytes, comp, print);

    return root;
}

void inorderTraversal(const BSTNode_t *root)
{
    if(root != NULL)
    {
        inorderTraversal(root->left);
        root->print(root->data);
        inorderTraversal(root->right);
    }

}

void freeNode(BSTNode_t** node)
{
    if(*node)
    {
        free((*node)->data);
        free(*node);
        *node = NULL;
    }
}

void freeBST(BSTNode_t** root)
{
    if(*root)
    {
        freeBST(&(*root)->left);
        freeBST(&(*root)->right);
        freeNode(root);
    }
}


// <----TODO
