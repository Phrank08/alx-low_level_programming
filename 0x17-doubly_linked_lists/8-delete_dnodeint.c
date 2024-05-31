#include "lists.h"
/**
 * delete_dnodeint_at_index - delete node at index
 * @head: head of list
 * @index: position of node to delete in list
 *
 * Return: 1 on Success, -1 on Failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp;
	unsigned int i = 0;

	if (!head || !(*head))
		return (-1);

	temp = *head;
	for (; temp; temp = temp->next, i++) /* iterate till end of list */
		if (i == index) /* if indexed node found */
		{
			if (i == 0 && temp->next == NULL)
				*head = NULL;
			else if (i == 0)
			{
				temp->next->prev = NULL;
				*head = temp->next;
			}
			else if (temp->next == NULL)
				temp->prev->next = NULL;
			else
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
			}
			free(temp);
			return (1);
		}
	return (-1);
}
