#include"binary_trees.h"
#include<stdlib.h>
/**
*binary_tree_is_root -  checks if a given node is a root
*@node:  a pointer to the node to check
*Return: 1 if node leaf otherwise 0
*Description: if node null return 0
*/
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node->parent || !node)
	{
		return (0);
	}
	return (1);
}
