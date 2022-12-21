#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 *
 * @tree: Pointer to a binary tree.
 *
 * Return: The size of the binary tree.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h_left = 0, height_right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		h_left = 1 + binary_tree_height(tree->left);

	if (tree->right)
		height_right = 1 + binary_tree_height(tree->right);

	return (h_left > height_right ? h_left : height_right);
}

/**
 * binary_tree_sibling - Function that checks if a binary tree is perfect
 *
 * @node: Pointer to a node of a binary tree.
 *
 * Return: Pointer to sibling or NULL.
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !(node->parent))
		return (NULL);

	if (node == node->parent->left)
		return (node->parent->right);
	return (node->parent->left);
}

/**
 * get_parent_to_insert - Get the parent to insert a node in order
 * (left to right) until complete the level.
 *
 * @node: Pointer to a node of a binary tree.
 * @level: Current level on the Binary Heap Tree.
 * @chosen_parent: Pointer to the struct that contains
 * the chosen parent and a flag.
 *
 * Return: Pointert o the struct that contains the chosen parent and a flag.
 */

chosen_parent_s *get_parent_to_insert(heap_t *node, int level,
chosen_parent_s *chosen_parent)
{
	if (!node || *(chosen_parent->is_selected) == 1)
		return (chosen_parent);

	if (!chosen_parent->parent && !node->left)
		chosen_parent->parent = node;

	if (level == 0 && !binary_tree_sibling(node))
	{
		if (node->parent)
			chosen_parent->parent = node->parent;
		else
			chosen_parent->parent = node;

		*(chosen_parent->is_selected) = 1;
	}

	if (level == 1 && !binary_tree_sibling(node) && node->parent)
	{
		chosen_parent->parent = node;
		*(chosen_parent->is_selected) = 1;
	}

	if (level == 1 && binary_tree_sibling(node) && !node->left)
	{
		chosen_parent->parent = node;
		*(chosen_parent->is_selected) = 1;
	}

	chosen_parent = get_parent_to_insert(node->left, level - 1, chosen_parent);
	chosen_parent = get_parent_to_insert(node->right, level - 1, chosen_parent);

	return (chosen_parent);
}

/**
 * heapify - Do the "heapify" to an binary heap.
 *
 * @node: Pointer to one node of the binary heap, usually root node.
 *
 * Return: Void.
 */
void heapify(heap_t *node)
{
	int tmp;
	heap_t *left_child = NULL, *right_child = NULL;

	if (!node)
		return;

	left_child = node->left;
	right_child = node->right;

	if (left_child && (left_child->left || left_child->right))
		heapify(left_child);

	if (right_child && (right_child->left || right_child->right))
		heapify(right_child);

	if (left_child && (left_child->n > node->n))
	{
		tmp = node->n;
		node->n = left_child->n;
		left_child->n = tmp;
	}

	if (right_child && (right_child->n > node->n))
	{
		tmp = node->n;
		node->n = right_child->n;
		right_child->n = tmp;
	}
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 *
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Return a pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL, *parent = NULL;
	int flag = 0, height = 0;
	chosen_parent_s tmp;

	tmp.is_selected = &flag;
	tmp.parent = parent;

	if (!root)
		return (new_node);

	if (!*root)
	{
		new_node = binary_tree_node(NULL, value);
		*root = new_node;
		return (new_node);
	}

	height = binary_tree_height(*root);
	get_parent_to_insert(*root, height, &tmp);
	new_node = binary_tree_node(tmp.parent, value);

	if (tmp.parent->left)
		tmp.parent->right = new_node;
	else
		tmp.parent->left = new_node;

	heapify(*root);

	return (new_node);
}
