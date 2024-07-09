#include "hash_tables.h"

/**
 * shash_table_create - create ordered hash table
 * @size: size of array
 *
 * Return: pointer to new table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new_table = NULL;

	/* allocate new table struct */
	new_table = malloc(sizeof(shash_table_t));
	if (!new_table) /* if malloc fails */
		return (NULL);
	new_table->size = size;

	/* allocare array of pointers */
	new_table->array = malloc(sizeof(void *) * size);
	if (!new_table->array) /* if array alloc fails */
	{
		free(new_table);
		return (NULL);
	}

	/* initialize pointers to sorted list */
	new_table->shead = NULL;
	new_table->stail = NULL;

	return (new_table);
}
/**
 * shash_table_set - set value in ordered hash table
 * @ht: pointer to hash table
 * @key: key of value to add
 * @value: value to add
 *
 * Return: 1 on Success; 0 on Failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int check_set_replace;
	shash_node_t *new = NULL, *temp;

	if (!ht || !key || (strlen(key) == 0) || !value)
		return (0);
	check_set_replace = rep_val(ht, key, value, 0);
	temp = ht->shead;
	if (check_set_replace == 0)
		new = set_value(ht, key, value);
	if (temp == NULL) /* if list is empty */
	{
		ht->shead = ht->stail = new;
		return (1);
	}
	while (temp) /* for beginning/middle additions */
	{
		if (strcmp(key, temp->key) < 0)
		{
			new->snext = temp;
			new->sprev = temp->sprev;
			temp->sprev = new;
			if (new->sprev == NULL) /* if added at beginning */
				ht->shead = new;
			else
				new->sprev->snext = new;
			return (1);
		}
		else if (strcmp(key, temp->key) == 0)
		{
			rep_val(ht, key, value, 1);
			return (1);
		}
		if (temp->snext)
			temp = temp->snext;
		else
			break;
	}
	temp->snext = new; /* if tail reached, add to end */
	new->sprev = temp;
	ht->stail = new; /* set new tail */
	return (1); }
/**
 * shash_table_get - retrieve value from hash table
 * @ht: hash table
 * @key: key of value to retrieve
 *
 * Return: desired value, or NULL if not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index = 0;
	shash_node_t *head = NULL;

	if (!ht || !key)
		return (NULL);

	/* get index of key */
	index = hash_djb2((unsigned char *)key) % ht->size;

	if (ht->array[index]) /* if pointer at index is not NULL */
	{
		head = ht->array[index];
		while (head)
		{
			if (strcmp(head->key, key) == 0)
				break;
			head = head->next;
		}
	}
	else /* key doesn't exist in table */
		return (NULL);

	return (head->value);
}
/**
 * shash_table_print - print hash table
 * @ht: pointer to hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *temp = NULL;

	if (ht) /* if table exists */
	{
		putchar('{');
		temp = ht->shead;
		while (temp)
		{
			printf("'%s': '%s'", temp->key, temp->value);
			if (temp->snext != NULL)
				printf(", ");
			temp = temp->snext;
		}
		printf("}\n");
	}
}
/**
 * shash_table_print_rev - print hash table in reverese
 * @ht: pointer to hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *temp = NULL;

	if (ht) /* if table exists */
	{
		putchar('{');
		temp = ht->stail;
		while (temp)
		{
			printf("'%s': '%s'", temp->key, temp->value);
			if (temp->sprev != NULL)
				printf(", ");
			temp = temp->sprev;
		}
		printf("}\n");
	}
}
/**
 * shash_table_delete - delete ordered hash table
 * @ht: pointer to hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *head = NULL, *temp = NULL;

	while (head)
	{
		temp = head;
		head = head->snext;
		free(temp->value);
		free(temp->key);
		free(temp);
	}
	free(ht->array);
	free(ht);
}

/**
 * rep_val - check if value exist for that key and replace
 * rather than setting
 * @ht: hash table
 * @key: key
 * @value: value to replace to
 * @typ: check if its the original list or the sorted list
 * Return: 1 if value replaced, 0 if value need to be set
*/
int rep_val(shash_table_t *ht, const char *key, const char *value, int typ)
{
	shash_node_t *tmp;
	unsigned long int index;

	index = hash_djb2((const unsigned char *)key) % ht->size;
	if (!ht || !key)
		exit(0);
	tmp = ht->array[index];
	if (typ == 0)
	{
		while (tmp)
		{
			if (strcmp(tmp->key, key) == 0)
			{
				free(tmp->value);
				tmp->value = strdup(value);
				if (tmp->value == NULL)
					exit(0);
				return (1);
			}
			tmp = tmp->next;
		}
	}
	else
	{
		free(tmp->value);
		tmp->value = strdup(value);
		if (tmp->value == NULL)
			exit(0);
		return (1);
	}
	return (0);
}
/**
 * set_value - set value for new table
 * @ht: hash table
 * @key: key
 * @value: value to replace to
 * Return: 1 if value replaced, 0 if value need to be set
*/

shash_node_t *set_value(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new;

	new = malloc(sizeof(shash_node_t));
	if (!new)
		exit(0);
	index = hash_djb2((const unsigned char *)key) % ht->size;
	new->key = strdup(key); /* store key in node */
	new->value = strdup(value); /* dup value to node */
	new->next = ht->array[index]; /* attach new to head of list at index */
	ht->array[index] = new; /* assign index pointer to new node */
	new->snext = new->sprev = NULL;
	return (new);
}
