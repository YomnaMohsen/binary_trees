#include"binary_trees.h"

/**
*binary_tree_sibling - finds the sibling of a node
*@node:  a pointer to  node of tree to finds the sibling
*Return: pointer to sibling node
*Description: If node is NULL or the parent is NULL, return NULL
*             If node has no sibling, return NULL
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
	{
		return (NULL);
	}
	if (node->parent->left == node)
	{
		return (node->parent->right);
	}
	return (node->parent->left);
}
