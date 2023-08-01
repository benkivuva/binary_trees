#include "binary_trees.h"

size_t _max(size_t a, size_t b);

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

	return (1 + _max(left_height, right_height));
}

/**
 * binary_tree_balance - Measure the balance factor of a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: The balance factor of the tree.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	binary_tree_t *right_subtree = NULL;
	binary_tree_t *left_subtree = (binary_tree_t *)tree;
	int left_height = 0, right_height = 0;

	right_subtree = left_subtree->right;
	left_subtree->right = NULL;
	left_height = (int)binary_tree_height(left_subtree);
	left_subtree->right = right_subtree;

	right_subtree = left_subtree->left;
	left_subtree->left = NULL;
	right_height = (int)binary_tree_height(left_subtree);
	left_subtree->left = right_subtree;

	return (left_height - right_height);
}

/**
 * binary_tree_is_perfect - Check if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int is_perfect = 1;

	if (!tree || binary_tree_balance(tree) != 0)
		return (0);

	if (tree->left)
		is_perfect &= binary_tree_is_perfect(tree->left);

	if (tree->right)
		is_perfect &= binary_tree_is_perfect(tree->right);

	return (is_perfect);
}
