#include"binary_trees.h"

/**
*binary_tree_height - measures the height of a node in a binary tree
*@tree:  a pointer to the root node of tree to measure height
*Return: int height
*Description: if tree null return 0
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left, height_right;

	if (tree)
	{
		height_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		height_right = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return (height_left > height_right ? height_left : height_right);
	}
	return (0);
}
