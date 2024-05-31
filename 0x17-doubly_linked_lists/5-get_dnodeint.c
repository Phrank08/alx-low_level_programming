#include "lists.h"

/**
 * get_dnodeint_at_index - get node at index
 * @head: ptr to head
 * @index: index of the node
 * Return: node
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current;
	unsigned int i;

	current = head;
	if (current && current->prev == NULL && index == 0)
		return (current);
	if (index == 0 && !current)
		return (NULL);
	for (i = 0; i < index; i++)
	{
		if (current != NULL)
			current = current->next;
		else
			return (NULL);
		if (current != NULL && i == index - 1)
		{
			return (current);
		}
	}
	return (NULL);
}
