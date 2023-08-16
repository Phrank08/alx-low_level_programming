#include <stdio.h>

/**
 * print_name - function that prints an name
 *
 * @name: name of the person
 * @f: variable that stores an address
 *
 * description - A function that prints a name
 *
 * Return: Always 0 (Success)
 */

	void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}
