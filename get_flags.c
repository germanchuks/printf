#include "main.h"

/**
 * get_format_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @index: Pointer to current index in format string.
 *
 * Return: Active flags for argument printing
 */

int get_format_flags(const char *format, int *index)
{
        int j, currentIndex;
        int format_flags = 0;
        const char FLAGS_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
        const int FLAGS_VALUES[] = {FLAG_MINUS, FLAG_PLUS, FLAG_ZERO,
                FLAG_HASH, FLAG_SPACE, 0};

        for (currentIndex = *index + 1; format[currentIndex] != '\0'; currentIndex++)
        {
                for (j = 0; FLAGS_CHAR[j] != '\0'; j++)
                        if (format[currentIndex] == FLAGS_CHAR[j])
                        {
                                format_flags |= FLAGS_VALUES[j];
                                break;
                        }

                if (FLAGS_CHAR[j] == '\0')
                        break;
        }

        *index = currentIndex - 1;

        return (format_flags);
}

