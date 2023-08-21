#include "main.h"

/**
 * print_char - Prints a character
 * @args: The list of arguments
 * @output_buffer: The buffer array to handle print
 * @format_flags:  The active flags
 * @min_width: The width specification
 * @precision: The precision specification
 * @size_spec: The size specifier
 *
 * Return: Number of characters printed
 */

int print_character(va_list args, char output_buffer[],
                           int format_flags, int min_width, int precision, int size_spec)
{
        char c = va_arg(args, int);

        return (handle_write_char(c, output_buffer, format_flags,
                                min_width, precision, size_spec));
}

/**
 * print_string - Prints string
 * @args: The list of arguments
 * @output_buffer: The buffer array to handle print
 * @format_flags:  The active flags
 * @min_width: The width specification
 * @precision: The precision specification
 * @size_spec: The size specifier
 *
 * Return: Number of characters printed.
 */

int print_string(va_list args, char output_buffer[],
                                 int format_flags, int min_width, int precision, int size_spec)
{
        int str_len = 0, i;
        char *str = va_arg(args, char *);

        UNUSED(output_buffer);
        UNUSED(format_flags);
        UNUSED(precision);
        UNUSED(size_spec);
        if (str == NULL)
                str = "(null)";

        while (str[str_len] != '\0')
                str_len++;

        if (precision < str_len && precision >= 0)
                str_len = precision;

        if (min_width > str_len)
        {
                if (format_flags & FLAG_MINUS)
                {
                        write(1, &str[0], str_len);
                        for (i = min_width - str_len; i > 0; i--)
                                write(1, " ", 1);
                        return (min_width);
                }
                else
                {
                        for (i = min_width - str_len; i > 0; i--)
                                write(1, " ", 1);
                        write(1, &str[0], str_len);
                        return (min_width);
                }
        }

        return (write(1, str, str_len));
}

/**
 * print_percent - Prints a percent sign
 * @args: The list of arguments
 * @output_buffer: The buffer array to handle print
 * @format_flags: The active flags
 * @min_width: The width specification.
 * @precision: The precision specification
 * @size_spec: The size specifier
 *
 * Return: Number of characters printed.
 */

int print_percent(va_list args, char output_buffer[],
                                  int format_flags, int min_width, int precision, int size_spec)
{
        UNUSED(args);
        UNUSED(output_buffer);
        UNUSED(format_flags);
        UNUSED(min_width);
        UNUSED(precision);
        UNUSED(size_spec);
        return (write(1, "%%", 1));
}

/**
 * print_integer - Print an integer
 * @args: The list of arguments
 * @output_buffer: The buffer array to handle print
 * @format_flags:  The active flags
 * @min_width: The width specification
 * @precision: The precision specification
 * @size_spec: The size specifier
 *
 * Return: Number of characters printed.
 */

int print_integer(va_list args, char output_buffer[],
                          int format_flags, int min_width, int precision, int size_spec)
{
        int i = BUFF_SIZE - 2;
        int is_negative = 0;
        long int number = va_arg(args, long int);
        unsigned long int abs_num;

        number = size_conv_number(number, size_spec);

        if (number == 0)
                output_buffer[i--] = '0';

        output_buffer[BUFF_SIZE - 1] = '\0';
        abs_num = (unsigned long int)number;

        if (number < 0)
        {
                abs_num = (unsigned long int)((-1) * number);
                is_negative = 1;
        }

        while (abs_num > 0)
        {
                output_buffer[i--] = (abs_num % 10) + '0';
                abs_num /= 10;
        }

        i++;

        return (write_integer(is_negative, i, output_buffer, format_flags,
                                min_width, precision, size_spec));
}

/**
 * print_binary - Prints an unsigned number
 * @args: The list of arguments
 * @output_buffer: The buffer array to handle print
 * @format_flags:  The active flags
 * @min_width: The width specification
 * @precision: The precision specification
 * @size_spec: The size specifier
 *
 * Return: Numbers of characters printed.
 */

int print_binary(va_list args, char output_buffer[],
                                 int format_flags, int min_width, int precision, int size_spec)
{
        unsigned int num, divisor, i, sum;
        unsigned int binary_digits[32];
        int count;

        UNUSED(output_buffer);
        UNUSED(format_flags);
        UNUSED(min_width);
        UNUSED(precision);
        UNUSED(size_spec);

        num = va_arg(args, unsigned int);
        divisor = 2147483648UL;
        binary_digits[0] = num / divisor;
        for (i = 1; i < 32; i++)
        {
                divisor /= 2;
                binary_digits[i] = (num / divisor) % 2;
        }
        for (i = 0, sum = 0, count = 0; i < 32; i++)
        {
                sum += binary_digits[i];
                if (sum || i == 31)
                {
                        char binary_char = '0' + binary_digits[i];

                        write(1, &binary_char, 1);
                        count++;
                }
        }
        return (count);
}
