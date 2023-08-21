#include "main.h"

/**
 * get_print_width - Calculates print width.
 * @format: Formatted string to print arguments.
 * @formatIndex: Pointer to current index in format string.
 * @list: List of arguments.
 *
 * Return: Width
 */

int get_print_width(const char *format, int *formatIndex, va_list list)
{
	int current_index;
	int width = 0;

	for (current_index = *formatIndex + 1;
		 format[current_index] != '\0'; current_index++)
	{
		if (is_digit(format[current_index]))
		{
			width *= 10;
			width += format[current_index] - '0';
		}
		else if (format[current_index] == '*')
		{
			current_index++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*formatIndex = current_index - 1;

	return (width);
}
