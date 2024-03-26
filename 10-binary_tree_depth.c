#include"binary_trees.h"

/**
*binary_tree_depth - measures the depth of a node in a binary tree
*@tree:  a pointer to the root node of tree to measure depth
*Return: int depth
*Description: if tree null return 0
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	if (tree)
	{
		depth = tree->parent ? 1 + binary_tree_depth(tree->parent) : 0;
		return (depth);
	}
	return (0);
}
