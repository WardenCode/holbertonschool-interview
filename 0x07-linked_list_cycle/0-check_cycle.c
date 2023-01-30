#include "lists.h"

/**
 * check_cycle - Validate if a Linked list have a cycle
 *
 * @list: pointer to the linked list
 *
 * Return: 1 if exist a cycle, 0 otherwise
 */
int check_cycle(listint_t *list)
{
	listint_t *fast_node = NULL, *slow_node = NULL;

	if (!list || !list->next)
		return (0);

	slow_node = list, fast_node = list->next;

	while (fast_node && fast_node->next)
	{
		if (slow_node == fast_node)
			return (1);

		slow_node = slow_node->next;
		fast_node = fast_node->next->next;
	}

	return (0);
}
