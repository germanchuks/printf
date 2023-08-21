#include "main.h"

void print_buffer(char output_buffer[], int *index);

/**
 * _printf - Printf function
 * @format: The format string
 *
 * Return: Number of printed characters.
 */

int _printf(const char *format, ...)
{
        int i, printed = 0, printed_chars = 0;
        int format_flags, min_width, precision, size_spec, index = 0;
        va_list list;
        char output_buffer[BUFF_SIZE];

        if (format == NULL)
                return (-1);

        va_start(list, format);

        for (i = 0; format && format[i] != '\0'; i++)
        {
                if (format[i] != '%')
                {
                        output_buffer[index++] = format[i];
                        if (index == BUFF_SIZE)
                                print_buffer(output_buffer, &index);
                        printed_chars++;
                }
                else
                {
                        print_buffer(output_buffer, &index);
                        format_flags = get_format_flags(format, &i);
                        min_width = get_print_width(format, &i, list);
                        precision = get_print_precision(format, &i, list);
                        size_spec = get_size_specifier(format, &i);
                        ++i;
                        printed = handle_print(format, &i, list, output_buffer,
                                                                   format_flags, min_width, precision, size_spec);
                        if (printed == -1)
                                return (-1);
                        printed_chars += printed;
                }
        }

        print_buffer(output_buffer, &index);

        va_end(list);

        return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist.
 * @output_buffer: The array of characters.
 * @index: The index at which to add next character, represents the length.
 */

void print_buffer(char output_buffer[], int *index)
{
        if (*index > 0)
                write(1, &output_buffer[0], *index);

        *index = 0;
}

