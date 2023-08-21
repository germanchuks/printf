#include "main.h"

/**
 * get_size_specifier - Calculates the size to cast the argument
 * @format: The formatted string to print arguments.
 * @index: The pointer to current index in format string.
 *
 * Return: Size specifier for argument casting.
 */

int get_size_specifier(const char *format, int *index)
{
	int currentIndex = *index + 1;
	int sizeSpecifier = 0;

	if (format[currentIndex] == 'l')
		sizeSpecifier = SIZE_LONG;
	else if (format[currentIndex] == 'h')
		sizeSpecifier = SIZE_SHORT;

	if (sizeSpecifier == 0)
		*index = currentIndex - 1;
	else
		*index = currentIndex;

	return (sizeSpecifier);
}

