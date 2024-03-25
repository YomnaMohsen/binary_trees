#include"binary_trees.h"
#include<stdlib.h>
#include<stdio.h>
/**
 *binary_tree_insert_left - inserts a node as the left-child of another node
 *@parent:  pointer to the node to insert the left-child in
 *@value: int value in created node
 *Return: pointer to node in b_tree
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
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
	if (parent->left)
	{
		node->left = parent->left;
		parent->left->parent = node;
	}
	parent->left = node;
	return (node);
}
