#include"binary_trees.h"
#include <stdlib.h>
void print_level_order(const binary_tree_t *tree, size_t level, void (*func)(int));
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


/**
*binary_tree_levelorder - goes through a binary tree using level-order traversal
*@tree:  a pointer to the root node of tree to traverse
*@func: a pointer to a function to call for each node.
*       The value in the node must be passed as a parameter
*       to this function
*Return: nothing
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    size_t height, len = 1;
    if(!tree || !func)
        return;

    height = binary_tree_height(tree) + 1;

    while(len <= height)
    {
        print_level_order(tree, len, func);
        len++;
    }

}

/**
*print_level_order - helper fn to print nodes through levelorder traverse
*@tree:  a pointer to the root node of tree to traverse
*@height: height of tree
*/
void print_level_order(const binary_tree_t *tree, size_t level, void (*func)(int))
{
    if(!tree)
        return;
    if(level == 1)
        func(tree->n);
    else
    {
        print_level_order(tree->left, level - 1, func);
        print_level_order(tree->right, level - 1, func);
    }
}
    