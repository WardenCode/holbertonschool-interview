#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * create_node - create a node
 *
 * @value: Const pointer to the node value (string)
 *
 * Return: Pointer to the new node or NULL if fails
 */
List *create_node(const char *value)
{
	List *new_node = NULL;

	if (!value)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->next = NULL;
	new_node->prev = NULL;

	new_node->str = strdup(value);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}

	return (new_node);
}

/**
 * add_node - Add a node to the circular doubly linked list between head
 * and tail
 *
 * @list: Double pointer to the list
 * @new_node: Pointer to the new node
 *
 * Return: Void
 */
void add_node(List **list, List *new_node)
{
	List *head = *list;
	List *tail = NULL;

	if (!(*list))
	{
		*list = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
		return;
	}

	tail = head->prev;

	new_node->next = head;
	new_node->prev = tail;
	head->prev = new_node;
	tail->next = new_node;
}

/**
 * add_node_begin - Add a node to the head of the circular doubly linked list
 *
 * @list: Double pointer to the list
 * @str: Pointer to value of the node (string)
 *
 * Return: Pointer to the new node or NULL if fails
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node = create_node(str);

	if (!new_node)
		return (NULL);

	add_node(list, new_node);
	*list = new_node;

	return (new_node);
}

/**
 * add_node_end - Add a node to the tail of the circular doubly linked list
 *
 * @list: Double pointer to the list
 * @str: Pointer to value of the node (string)
 *
 * Return: Pointer to the new node or NULL if fails
 */
List *add_node_end(List **list, char *str)
{
	List *new_node = create_node(str);

	if (!new_node)
		return (NULL);

	add_node(list, new_node);
	return (new_node);
}
