#include"binary_trees.h"
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

}


/**
*binary_tree_is_complete - checks if binary tree is complete
*@tree:  a pointer to the root node of tree to measure size
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
    return(is_complete_tree(tree, index, tree_size));


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