#include "main.h"

/**
 * handle_print - Prints an argument based on its type
 * @fmt: The formatted string in which to print the arguments.
 * @list: The list of arguments to be printed.
 * @id_ptr: The index pointer.
 * @output_buffer: The buffer to print.
 * @format_flags: The active flags
 * @min_width: The width specification
 * @precision: Precision specification
 * @size_spec: Size specifier
 *
 * Return: Number of characters printed. -1 if otherwise;
 */

int handle_print(const char *fmt, int *id_ptr, va_list list,
                char output_buffer[], int format_flags, int min_width,
                int precision, int size_spec)
{
        int i, printed_chars = 0;
        fmt_t fmt_types[] = {
                {'c', print_character}, {'s', print_string},
                {'%', print_percent}, {'i', print_integer},
                {'d', print_integer}, {'b', print_binary},
                {'u', print_unsigned_int}, {'o', print_octal_number},
                {'x', print_hexadecimal}, {'X', print_uppercase_hex},
                {'p', print_pointer}, {'S', print_non_printable},
                {'r', print_reversed_string}, {'R', print_rot13string},
                {'\0', NULL}
        };
        for (i = 0; fmt_types[i].fmt != '\0'; i++)
                if (fmt[*id_ptr] == fmt_types[i].fmt)
                        return (fmt_types[i].fn(list, output_buffer,
                                                format_flags, min_width,
                                                precision, size_spec));

        if (fmt_types[i].fmt == '\0')
        {
                if (fmt[*id_ptr] == '\0')
                        return (-1);
                printed_chars += write(1, "%%", 1);
                if (fmt[*id_ptr - 1] == ' ')
                        printed_chars += write(1, " ", 1);
                else if (min_width)
                {
                        --(*id_ptr);
                        while (fmt[*id_ptr] != ' ' && fmt[*id_ptr] != '%')
                                --(*id_ptr);
                        if (fmt[*id_ptr] == ' ')
                                --(*id_ptr);
                        return (1);
                }

                printed_chars += write(1, &fmt[*id_ptr], 1);
                return (printed_chars);
        }

        return (printed_chars);
}
