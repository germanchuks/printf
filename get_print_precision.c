#include "main.h"

/**
 * get_print_precision - Calculates printing precision
 * @format: Formatted string to print arguments
 * @index: Pointer to current index in format string.
 * @list: List of arguments.
 *
 * Return: Precision for argument printing.
 */

int get_print_precision(const char *format, int *index, va_list list)
{
        int currentIndex = *index + 1;
        int precision = -1;

        if (format[currentIndex] != '.')
                return (precision);

        precision = 0;

        for (currentIndex += 1; format[currentIndex] != '\0'; currentIndex++)
        {
                if (is_digit(format[currentIndex]))
                {
                        precision *= 10;
                        precision += format[currentIndex] - '0';
                }
                else if (format[currentIndex] == '*')
                {
                        currentIndex++;
                        precision = va_arg(list, int);
                        break;
                }
                else
                        break;
        }

        *index = currentIndex - 1;

        return (precision);
}

