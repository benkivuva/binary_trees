#include "binary_trees.h"
size_t binary_tree_depth(const binary_tree_t *tree);

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: input binary tree
 * Return: depth of tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to first node
 * @second: pointer to second node
 * Return: pointer to lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);

	size_t depth_a = binary_tree_depth(first);
	size_t depth_b = binary_tree_depth(second);

	while (depth_a > depth_b)
	{
		first = first->parent;
		depth_a--;
	}

	while (depth_b > depth_a)
	{
		second = second->parent;
		depth_b--;
	}

	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);

		first = first->parent;
		second = second->parent;
	}

	return (NULL);
}
