#include "lists.h"

/**
 * insert_node - Inserts a number into a sorted singly linked list.
 *
 * @head: Double pointer to the head of the singly linked list.
 *
 * @number: Value of the node to be inserted
 *
 * Return: The address of the new node, or NULL if it failed.
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *tmp = NULL, *prev = NULL, *new_node = NULL;

	if (!head)
		return (new_node);

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (new_node);
	new_node->n = number;
	new_node->next = NULL;

	if (!(*head))
	{
		*head = new_node;
		return (new_node);
	}

	for (tmp = *head; tmp; tmp = tmp->next)
	{
		if (tmp->n > number)
		{
			if (!prev)
				*head = new_node;
			else
				prev->next = new_node;
			new_node->next = tmp;
			break;
		}
		prev = tmp;
	}

	if (!tmp)
		prev->next = new_node;

	return (new_node);
}
