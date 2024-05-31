#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * insert_dnodeint_at_index - insert node at an index
 * @h: ptr to ptr to head
 * @idx: index to insert node
 * @n: int to insert at node
 * Return: adress of new node
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *current;
	dlistint_t *new;
	unsigned int i;

	current = *h;
	if (!current)
	{
		if (idx == 0)
			return (add_dnodeint(h, n));
		else
			return (NULL);
	}
	if (idx == 0)
		return (add_dnodeint(h, n));
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (current != NULL)
	{
		if (i == idx - 1  && current->next != NULL)
		{
			new->n = n;
			new->prev = current;
			current->next->prev = new;
			new->next = current->next;
			current->next = new;
			return (new);
		}
		current = current->next;
		i++;
	}
	if (i == idx)
		return (add_dnodeint_end(h, n));
	return (NULL);
}
