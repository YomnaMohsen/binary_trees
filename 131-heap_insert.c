#include"binary_trees.h"
#include <stdio.h>
heap_t *heap_node_finder(heap_t *root, size_t number);
heap_t *heap_swap(heap_t *new, heap_t *parent);

/*
*binary_tree_is_heap - inserts a value in Max Binary Heap
*@root: a double pointer to the root node of the Heap to insert the value
*@value:is the value to store in the node to be inserted 
*Return: a pointer to the created node, or NULL on failure
*/
 heap_t *heap_insert(heap_t **root, int value)
 {

    size_t size;
	int swap = 1;
	heap_t *parent, *new;
    if(*root == NULL)
    {
       *root = binary_tree_node(NULL, value);
       return(*root);
    }
    size = binary_tree_size(*root);
	parent = heap_node_finder(*root, (size-1)/2);
	new = binary_tree_node(parent, value);
	if(size % 2 == 1)
	{
		parent->left = new;
	}
	else
	{
		parent->right = new;
	}
	while(swap == 1 && parent != NULL)/*parent is moving until 1st one*/
	{
		if(parent->n >= new->n)
		{
			swap =0;
		}
		else
		{
			new = heap_swap(new, parent);
			parent = new->parent;/*update parent until reach to 1st*/
		}
	}
		return (new);

 }

/**
*binary_tree_size - measures the size of a binary tree
*@tree:  a pointer to the root node of tree to measure size
*Return: int size
*Description: if tree null return 0
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	if(tree == NULL)
		return(0);
	
	return (1+ binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
*heap_node_finder - finds current parent
*@root:  a pointer to the root node of tree to measure size
*@number: initial parent index
*Return: pointer to current parent
*/
heap_t *heap_node_finder(heap_t *root, size_t number)
{
	size_t parent_index, dir;
	if (number == 0)
	{
		return root;
	}
	parent_index = (number - 1) / 2;
	dir = (number - 1) % 2;

	if (dir == 0)
		return(heap_node_finder(root, parent_index)->left);
	return(heap_node_finder(root, parent_index)->right);
}

/**
*heap_swap- swap 2 values in 2 nodes
*@new:  a pointer to the newely created node
*@parent: pointer to parent of new node
*Return: pointer to node that has new value, (parent)
*/
heap_t *heap_swap(heap_t *new, heap_t *parent)
{
	int tmp;
	tmp = parent->n;
	parent->n = new->n;
	new->n = tmp;
	return parent;
}