#include"binary_trees.h"
#include <stdio.h>

/**
*binary_tree_size - measures the size of a binary tree
*@tree:  a pointer to the root node of tree to measure size
*Return: int size
*Description: if tree null return 0
*/
size_t binary_tree_size_h(const binary_tree_t *tree)
{
	size_t size_l = 0;
    size_t size_r = 0;

	if (!tree)
        return (0);
	
        if(tree->right)
            size_r = 1 + binary_tree_size(tree->right);
        if(tree->left)
            size_l=1 + binary_tree_size(tree->left);
		return (size_r+ size_l);
	}
	
}
/** 
*heap__to_sorted_array - converts a Binary Max Heap to a sorted array of integers
*@heap: a pointer to the root node of heap
*@size: an address to store the size of the array.
*Return: pointer to sorted array
*/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int *arr, i;
 
    if(!heap || !size)
    {
        return (NULL);
    }
    *size = binary_tree_size_h(heap) + 1;

    arr = malloc(sizeof(int) *(*size));
    if(!arr)
    {
        return (NULL);
    }

    for(i=0; heap ; i++)
    {
        arr[i] = heap_extract(&heap);
    }

    return (arr);
}