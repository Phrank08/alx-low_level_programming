#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * sum_dlistint - sum data in a linked lists
 * @head: ptr to head
 * Return: sum of data in linked lists
 */
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *current;
	int sum = 0;

	current = head;
	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}
	return (sum);
}
