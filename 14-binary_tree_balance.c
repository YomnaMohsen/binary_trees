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
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
	}
	return (0);
}
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
		/*modify from org fn so put 1 not 0 in else*/
		/*because we call height on right and left not org tree*/
		height_left = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		height_right = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return (height_left > height_right ? height_left : height_right);
	}
	return (0);
}
