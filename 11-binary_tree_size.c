#include"binary_trees.h"

/**
*binary_tree_size - measures the size of a binary tree
*@tree:  a pointer to the root node of tree to measure size
*Return: int size
*Description: if tree null return 0
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree)
	{
		size++;
		size += binary_tree_size(tree->right);
		size += binary_tree_size(tree->left);
		return (size);
	}
	return (0);
}
