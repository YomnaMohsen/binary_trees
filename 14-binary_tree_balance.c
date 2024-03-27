#include"binary_trees.h"

/**
*binary_tree_balance - measures the balance factor of a binary tree
*@tree:  a pointer to the root node of tree to measure balance factor
*Return: int balance factor
*Description: if tree null return 0
*/
int binary_tree_balance(const binary_tree_t *tree)
{

	if (tree)
	{
		return (binary_tree_height(tree->right) - binary_tree_height(tree->left));
	}
	return (0);
}
