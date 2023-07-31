#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include "binary_trees.h"

#define max(a, b) ((a) > (b) ? (a) : (b))

/**
 * binary_tree_height - Calculate the height of a node in a tree
 *
 * @tree: Pointer to the node of the tree or subtree
 *
 * Return: Height of the node
 */
int binary_tree_height(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (max(left_height, right_height) + 1);
}

/**
 * is_bst_tree - Validate if a binary tree is a binary search tree
 *
 * @tree: Const pointer to the tree
 * @min: Min value to compare
 * @max: Max value to compare
 *
 * Return: true if is a binary search tree, false otherwise
 */
bool is_bst_tree(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (true);

	if (tree->n <= min || tree->n >= max)
		return (false);

	return (
	    is_bst_tree(tree->left, min, tree->n) &&
	    is_bst_tree(tree->right, tree->n, max));
}

/**
 * is_correct_balance - Validate if the balance factor is valid for a AVL tree
 *
 * @tree: Const pointer to a binary tree
 *
 * Return: True if is correct balanced false otherwise
 */
bool is_correct_balance(const binary_tree_t *tree)
{
	int bf = 0;

	if (tree == NULL)
		return (true);

	bf = binary_tree_height(tree->left) - binary_tree_height(tree->right);

	if (abs(bf) > 1)
		return (false);

	return (is_correct_balance(tree->left) && is_correct_balance(tree->right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 *
 * @tree: Const pointer to a binary tree
 *
 * Return: 1 if is a AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (false);

	return (is_correct_balance(tree) && is_bst_tree(tree, INT_MIN, INT_MAX));
}
