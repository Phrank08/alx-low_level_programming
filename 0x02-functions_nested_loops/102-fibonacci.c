#include "main.h"
#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints the first 50 Fibonacci numbers
 * starting with 1 and 2, separated by comma and space
 * followed by a new line.
 *
 * Return: Always 0
 */
int main(void)
{
    long int first = 1, second = 2, next, i;

    printf("%ld, %ld", first, second);

    for (i = 2; i < 50; i++)
    {
        next = first + second;
        printf(", %ld", next);
        first = second;
        second = next;
    }
    printf("\n");

    return (0);
}

