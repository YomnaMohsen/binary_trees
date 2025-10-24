#include"binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

size_t binary_tree_height(const binary_tree_t *tree);
void pre_order(heap_t *root, heap_t **node, size_t height);
void heapify_down(heap_t *heap_root);
/** 
*heap_extract - extracts the root node of a Max Binary Heap
*@root: a double pointer to the root node of heap
*Return: value of extracted node or 0 in failure
*/
int heap_extract(heap_t **root)
{
    heap_t *heap_root, *node;
    int value;

    if(!root || !*root)
    {
        return(0);
    }
    heap_root = *root;
    value = heap_root->n;
    if(!heap_root->left && !heap_root->right)
    {
        *root = NULL;
        free(heap_root);
        return(value);
    }
    pre_order(heap_root, &node, binary_tree_height(heap_root));
    heap_root->n = node->n;
    if(node->parent->right)
        node->parent->right = NULL;
    else
        node->parent->left = NULL;
    free(node);
    heapify_down(heap_root);
    return (value);

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
		height_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		height_right = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return (height_left > height_right ? height_left : height_right);
	}
	return (0);
}

/**
*binary_tree_preorder - goes through a binary tree using pre-order traversal
*binary_tree_preorder- it is a modified version from preorder to get last level-order node
*@tree:  a pointer to the root node of tree to traverse
*@node: last node to traverse
*@height: height of tree
*Return: Nothing
*/

void pre_order(heap_t *root, heap_t **node, size_t height)
{
    if(!root)
    {
        return;
    }

    if(!height)
    {
        *node = root;
    }
    height--;
    pre_order(root->left, node, height);
    pre_order(root->right, node, height);
}

void heapify_down(heap_t *root)
{
    heap_t *largest;
    int tmp;

    if(!root){
        return;
    }

    while(root-> right || root->left)
    {
        largest = root;

        if(root->right && root->right->n > largest->n)
            largest = root->right;

        if(root->left && root->left->n > largest->n)
            largest = root->left; 

        if(largest == root)
            break;
        
        tmp = root->n;
        root->n = largest->n;
        largest->n = tmp;
        root = largest;    
    }
}