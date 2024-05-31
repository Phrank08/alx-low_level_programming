#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * free_dlistint - free doubly linked list
 * @head: ptr to ptr to head
 * Return: void
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	if (head != NULL)
	{
		while (head != NULL)
		{
			temp = head;
			head = (head)->next;
			free(temp);
		}
	}
}
