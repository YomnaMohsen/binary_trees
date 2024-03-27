#include"binary_trees.h"

/**
*binary_tree_leaves - count leaves of a binary tree
*@tree:  a pointer to the root node of tree to count leaves
*Return: int leaves
*Description: if tree null return 0
*/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree)
	{
		leaves += (!tree->right && !tree->left) ? 1 : 0;
		leaves += binary_tree_leaves(tree->right);
		leaves += binary_tree_leaves(tree->left);
		return (leaves);
	}
	return (0);
}
