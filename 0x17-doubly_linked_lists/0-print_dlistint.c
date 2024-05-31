#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_dlistint - print doubly linked list
 * @h: ppinter to head
 * Return: number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t len = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		len++;
	}
	return (len);
}
