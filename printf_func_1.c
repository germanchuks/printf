#include "main.h"

/**
 * print_unsigned_int - Prints an unsigned number
 * @args: The List of arguments
 * @output_buffer: The buffer array to handle print
 * @format_flags:  The active flags
 * @min_width: The width specification
 * @precision: The precision specification
 * @size_spec: The size specifier
 *
 * Return: Number of characters printed.
 */

int print_unsigned_int(va_list args, char output_buffer[],
					   int format_flags, int min_width, int precision, int size_spec)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);

	num = size_conv_unsgned(num, size_spec);
	if (num == 0)
		output_buffer[i--] = '0';

	output_buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		output_buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_unsigned_int(0, i, output_buffer, format_flags,
							   min_width, precision, size_spec));
}

/**
 * print_octal_number - Prints unsigned number in octal format.
 * @args: The list of arguments
 * @output_buffer: The buffer array to handle print
 * @format_flags:  The active flags
 * @min_width: The width Specification
 * @precision: The precision specification
 * @size_spec: The size specifier
 *
 * Return: Number of characters printed.
 */

int print_octal_number(va_list args, char output_buffer[],
					   int format_flags, int min_width, int precision, int size_spec)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int originalNum = num;

	UNUSED(min_width);

	num = size_conv_unsgned(num, size_spec);

	if (num == 0)
		output_buffer[i--] = '0';

	output_buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		output_buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (format_flags & FLAG_HASH && originalNum != 0)
		output_buffer[i--] = '0';

	i++;

	return (write_unsigned_int(0, i, output_buffer, format_flags,
							   min_width, precision, size_spec));
}

/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @args: The list of arguments
 * @output_buffer: The buffer array to handle print
 * @format_flags:  The active flags
 * @min_width: The width specification
 * @precision: The precision specification
 * @size_spec: The size specifier
 *
 * Return: Number of characters printed.
 */

int print_hexadecimal(va_list args, char output_buffer[],
					  int format_flags, int min_width, int precision, int size_spec)
{
	return (print_custom_hex(args, "0123456789abcdef", output_buffer,
							 format_flags, 'x', min_width, precision, size_spec));
}

/**
 * print_uppercase_hex - Prints an unsigned num in upper hexadecimal notation
 * @args: The list of arguments
 * @output_buffer: The buffer array to handle print
 * @format_flags: The active flags
 * @min_width: The width specification
 * @precision: The precision specification
 * @size_spec: The size specifier
 *
 * Return: Number of characters printed
 */

int print_uppercase_hex(va_list args, char output_buffer[],
						int format_flags, int min_width, int precision, int size_spec)
{
	return (print_custom_hex(args, "0123456789ABCDEF", output_buffer,
							 format_flags, 'X', min_width, precision, size_spec));
}

/**
 * print_custom_hex - Prints a hexadecimal number in lower or upper case.
 * @args: The list of arguments
 * @map_to: The array of values to map the number to
 * @output_buffer: The buffer array to handle print
 * @format_flags:  The active flags
 * @flag_ch: The flag character for prefix
 * @min_width: The width specification
 * @precision: The precision specification
 * @size_spec: The size specifier
 *
 * Return: Number of characters printed.
 */

int print_custom_hex(va_list args, char map_to[], char output_buffer[],
					 int format_flags, char flag_ch, int min_width,
					 int precision, int size_spec)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int originalNum = num;

	UNUSED(min_width);

	num = size_conv_unsgned(num, size_spec);

	if (num == 0)
		output_buffer[i--] = '0';

	output_buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		output_buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (format_flags & FLAG_HASH && originalNum != 0)
	{
		output_buffer[i--] = flag_ch;
		output_buffer[i--] = '0';
	}

	i++;

	return (write_unsigned_int(0, i, output_buffer, format_flags,
							   min_width, precision, size_spec));
}

