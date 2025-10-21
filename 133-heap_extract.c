#include"binary_trees.h"
#include <stdlib.h>
/*
*heap_extract - extracts the root node of a Max Binary Heap
*@root: a double pointer to the root node of heap
*Return: value of extracted node or 0 in failure
*/
int heap_extract(heap_t **root)
{
    heap_t *heap_root;
    int value;

    if(!root || !*root)
    {
        return(0);
    }
    value = *root->n;
    (!*root->left && !*root->right)
    {
        free(*root);
        return(value);
    }


 }