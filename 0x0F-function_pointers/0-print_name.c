#include <stdio.h>

/**
 * main - entry point of the program
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
