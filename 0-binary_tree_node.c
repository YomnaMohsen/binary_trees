#include"binary_trees.h"
#include<stdlib.h>
/**
 *binary_tree_node - creates node in tree
 *@parent: pointer to parent node
 *@value: int value in node
 *Return: pointer to node in b_tree
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	if (!node)
	{
		return (NULL);
	}
	node->parent = parent;
	node->n = value;
	node->left = NULL;
	node->right = NULL;

	return (node);

}
