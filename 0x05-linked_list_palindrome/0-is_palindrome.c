#include "lists.h"

/**
 * validate_palindrome - Validate if a singly linked list is palindrome.
 *
 * @head: Pointer to the head
 *
 * @node: Pointer to the actual node
 *
 * Return: Pointer to the head if is palindrome, NULL otherwise
 */
listint_t *validate_palindrome(listint_t *head, listint_t *node)
{
	if (node->next)
		head = validate_palindrome(head, node->next);

	if (!head || head->n != node->n)
		return (NULL);

	if (head->next)
		head = head->next;

	return (head);
}

/**
 * is_palindrome - Check if a linked list is palindrome
 *
 * @head: Double poionter to a singly linked list.
 *
 * Return: If the list is palindrome return 1 otherwise 0.
 */
int is_palindrome(listint_t **head)
{
	listint_t *node = NULL;

	if (head == NULL || *head == NULL)
		return (1);

	node = *head;

	if (validate_palindrome(*head, node) == NULL)
		return (0);

	return (1);
}
