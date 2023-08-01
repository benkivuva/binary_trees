#include "binary_trees.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

/**
 * binary_tree_is_perfect - Check if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree || binary_tree_balance(tree) != 0)
		return (0);

	if (tree->left && !binary_tree_is_perfect(tree->left))
		return (0);

	if (tree->right && !binary_tree_is_perfect(tree->right))
		return (0);

	return (1);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Return: Balance factor of the binary tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	int lh = (int)binary_tree_height(tree->left);
	int rh = (int)binary_tree_height(tree->right);

	return (lh - rh);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the binary tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree && (tree->left || tree->right))
		return (1 + MAX(binary_tree_height(tree->left),
					binary_tree_height(tree->right)));
	return (0);
}
