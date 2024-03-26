#include"binary_trees.h"
#include<stdlib.h>
/**
*binary_tree_delete - deletes entire tree
*@tree:  pointer to root node of tree to delete
*Return: Nothing
*Description: if tree is null do nothing
*/
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
