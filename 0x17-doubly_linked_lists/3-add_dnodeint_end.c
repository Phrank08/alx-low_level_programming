#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint_end - add node to the end of a doubly linked list
 * @head: ptr to ptr to head
 * @n: int to store at node
 * Return: address of new element or NULL
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *current;

	current = *head;
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new;
	new->next = NULL;
	new->prev = current;
	return (new);
}
