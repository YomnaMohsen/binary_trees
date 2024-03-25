#include"binary_trees.h"
#include<stdlib.h>
/**
*binary_tree_insert_right - inserts a node as the left-child of another node
*@parent:  pointer to the node to insert the right-child in
*@value: int value in created node
*Return: pointer to created node in b_tree
*Desription: If parent already has a right-child,
*            the new node must take its place,
*            and the old right-child must be set
*            as the right-child of the new node
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (!parent)
	{
		return (NULL);
	}
	node = binary_tree_node(parent, value);
	if (!node)
	{
		return (NULL);
	}
	if (parent->right)
	{
		node->right = parent->right;
		parent->right->parent = node;
	}
	parent->right = node;
	return (node);
}
