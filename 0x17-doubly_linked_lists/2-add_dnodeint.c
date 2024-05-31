#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint - add node to doubly linked list
 * @head: ptr to ptr to head
 * @n: int to store at node
 * Return: address of new element or NULL
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new, *current;

	current = *head;
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->prev = NULL;
	if (!current)
	{
		new->next = NULL;
	}
	else
	{
		new->next = current;
		current->prev = new;
		current = NULL;
	}
	*head = new;
	return (new);
}
