#include"binary_trees.h"

/**
*binary_tree_is_root -  checks if a given node is a root
*@node:  a pointer to the node to check
*Return: 1 if node root otherwise 0
*Description: if node null return 0
*/
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
	{
		return (0);
	}
	if (!node->parent)
	{
		return (1);
	}
	return (0);
}

