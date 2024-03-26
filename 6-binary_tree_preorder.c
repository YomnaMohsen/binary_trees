#include"binary_trees.h"

/**
*binary_tree_preorder -  checks if a given node is a root
*@tree:  a pointer to the root node to traverse
*@func: a pointer to a function to call for each node.
*       The value in the node must be passed as a parameter
*       to this function
*Return: nothing
*Description: if tree or func null do nothing
*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
