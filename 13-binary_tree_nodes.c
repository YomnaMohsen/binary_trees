#include"binary_trees.h"

/**
*binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
*@tree:  a pointer to the root node of tree to count number of nodes
*Return: count of nodes
*Description: if tree null return 0
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree)
	{
		nodes += (tree->right || tree->left) ? 1 : 0;
		nodes += binary_tree_nodes(tree->right);
		nodes += binary_tree_nodes(tree->left);
		return (nodes);
	}
	return (0);
}
