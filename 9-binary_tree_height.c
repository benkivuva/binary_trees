#include "binary_trees.h"

/**
 * binary_tree_height - Calculate the height of a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: Height of the tree or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	return (1 + (_max(left_height, right_height)));
}

/**
 * _max - Find the maximum of two numbers.
 * @a: First number.
 * @b: Second number.
 *
 * Return: The greater of the two numbers.
 */
size_t _max(size_t a, size_t b)
{
	return (a > b ? a : b);
}
