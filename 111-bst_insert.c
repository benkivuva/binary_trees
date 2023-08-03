#include "binary_trees.h"

/**
 * bst_insert - inserts a value into a Binary Search Tree (BST)
 * @tree: double pointer to the root node of the BST
 * @value: value to be inserted
 *
 * Return: pointer to the created node, or NULL on failure or if value already exists
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	bst_t *current = *tree;

	while (current)
	{
		if (value < current->n)
		{
			if (current->left == NULL)
			{
				current->left = binary_tree_node(current, value);
				return (current->left);
			}
			current = current->left;
		}
		else if (value > current->n)
		{
			if (current->right == NULL)
			{
				current->right = binary_tree_node(current, value);
				return (current->right);
			}
			current = current->right;
		}
		else
		{
			/* Value already exists in the tree, return NULL */
			return (NULL);
		}
	}
	return (NULL);
}
