#include"binary_trees.h"
/**
 * check_is_full - recuersive helper fn
 *@tree:  a pointer to the root node of tree to measure balance factor
* Return: 1 if balanced or 0
*/
int check_is_full(const binary_tree_t *tree)
{
	if (tree)
	{
		if ((!tree->right && tree->left) ||
		   (tree->right && !tree->left) ||
		   check_is_full(tree->left) == 0 ||
		   check_is_full(tree->right) == 0)
			return (0);
	}
	return (1);
}
/**
*binary_tree_is_full - checks if a binary tree is full
*@tree:  a pointer to the root node of tree to check
*Return: 1 if balanced or 0
*Description: if tree null return 0
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}
	return (check_is_full(tree));
}
