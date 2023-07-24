#include <stdio.h>

/**
 * main - Prints all possible different combinations of three digits.
 *
 * Return: Always 0.
 */
int main(void)
{
	int firstDigit, secondDigit, thirdDigit;

	for (firstDigit = 0; firstDigit < 8; firstDigit++)
	{
		for (secondDigit = firstDigit + 1; secondDigit < 9; secondDigit++)
		{
			for (thirdDigit = secondDigit + 1; thirdDigit <= 9; thirdDigit++)
			{
				putchar(firstDigit + '0');
				putchar(secondDigit + '0');
				putchar(thirdDigit + '0');

				if (firstDigit != 7 || secondDigit != 8 || thirdDigit != 9)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}

	putchar('\n');

	return (0);
}

