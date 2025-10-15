#include"binary_trees.h"
#include <stdio.h>
/*
*binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
*@tree: is a pointer to the root node of the tree to check 
*Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise.
*Return: If tree is NULL, return 0
*/
int binary_tree_is_heap(const binary_tree_t *tree)
{
    if(!tree ||!binary_tree_is_complete(tree))
    {
        return 0;
    }
    return (is_max_binary_heap(tree));
}
/**
*binary_tree_is_complete - checks if binary tree is complete
*@tree:  a pointer to the root node of tree 
*Return: 1 if true , 0 otherwise
*Description: if tree not complete return 0
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
    size_t tree_size, index;
    if(!tree)
    {
        return 0;
    }
    tree_size = binary_tree_size(tree);
    index = 0;
    return(is_complete_tree(tree, index, tree_size) && is_max_binary_heap(tree));
}

/**
*is_complete_tree - helper fn to checks if binary tree is complete
*@tree:  a pointer to the root node of tree 
*@index: index current node
*@tree_size: tree size
*Return: 1 if true , 0 otherwise
*Description: if tree not complete return 0
*/
int is_complete_tree(const binary_tree_t *root, size_t index, size_t tree_size)
{
    if(root == NULL)
    {
        return 1;
    }

    if(index >= tree_size)
    {
        return 0;
    }

    return(is_complete_tree(root->left, 2*index +1, tree_size)&&
           is_complete_tree(root->right, 2*index +2, tree_size));

}

int is_max_binary_heap(const binary_tree_t* tree)
{
    if(tree == NULL)
    {
        return 1;
    }

    if((tree->left && tree->n < tree->left->n) ||
        (tree->right && tree->n < tree->right->n))
        {
            return 0;

        }
    return (is_max_binary_heap(tree->left) && is_max_binary_heap(tree->right));
}

/**
*binary_tree_size - measures the size of a binary tree
*@tree:  a pointer to the root node of tree to measure size
*Return: int size
*Description: if tree null return 0
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree)
	{
		size++;
		size += binary_tree_size(tree->right);
		size += binary_tree_size(tree->left);
		return (size);
	}
	return (0);
}