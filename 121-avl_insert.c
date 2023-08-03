#include "binary_trees.h"

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to root of AVL tree
 * @value: input value
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = new_node;
		return (new_node);
	}

	*tree = avl_insert_recursive(*tree, value);
	if (*tree == NULL)
	{
		free(new_node);
		return (NULL);
	}

	return (new_node);
}

/**
 * avl_insert_recursive - recursively inserts a value in an AVL Tree
 * @root: pointer to root of AVL tree
 * @value: input value
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *avl_insert_recursive(avl_t *root, int value)
{
	if (root == NULL)
		return (binary_tree_node(NULL, value));

	if (value < root->n)
		root->left = avl_insert_recursive(root->left, value);
	else if (value > root->n)
		root->right = avl_insert_recursive(root->right, value);
	else
		return (NULL);

	return (avl_balance(root));
}

/**
 * avl_balance - Balance the AVL tree after insertion
 * @node: Pointer to the root of the subtree to be balanced
 * Return: Pointer to the new root of the balanced subtree
 */
avl_t *avl_balance(avl_t *node)
{
        int balance_factor = binary_tree_balance(node);

        if (balance_factor > 1) // Left heavy
        {
                if (binary_tree_balance(node->left) < 0) // Left-Right case
                        node->left = binary_tree_rotate_left(node->left);
                node = binary_tree_rotate_right(node); // Left-Left case
        }
        else if (balance_factor < -1) // Right heavy
        {
                if (binary_tree_balance(node->right) > 0) // Right-Left case
                        node->right = binary_tree_rotate_right(node->right);
                node = binary_tree_rotate_left(node); // Right-Right case
        }

        return (node);
}
