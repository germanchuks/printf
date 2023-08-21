#include "main.h"

/**
 * print_reversed_string - Prints string in reverse order.
 * @args: The list of arguments
 * @output_buffer: The buffer array to handle print (UNUSED)
 * @format_flag:  The active flags
 * @min_width: The width specification (UNUSED)
 * @precision: The precision specification (UNUSED)
 * @size_spec: The size specifier (UNUSED)
 * Return: Numbers of characters printed
 */

int print_reversed_string(va_list args, char output_buffer[],
						  int format_flag, int min_width, int precision, int size_spec)
{
	char *str;
	int i, count = 0;

	UNUSED(output_buffer);
	UNUSED(format_flag);
	UNUSED(min_width);
	UNUSED(size_spec);

	str = va_arg(args, char *);

	if (str == NULL)
	{
		UNUSED(precision);
		str = ")Null(";
	}

	/* Determines length of the string */
	for (i = 0; str[i]; i++)
	{
	}

	for (i = i - 1; i >= 0; i--)
	{
		char character = str[i];

		write(1, &character, 1);
		count++;
	}
	return (count);
}

/**
 * print_rot13string - Print a string in ROT13 encoding.
 * @args: The list of arguments
 * @output_buffer: The buffer array (UNUSED)
 * @format_flag:  The active flags (UNUSED)
 * @min_width: The width spec (UNUSED)
 * @precision: The precision specification (UNUSED)
 * @size_spec: The size specifier (UNUSED)
 *
 * Return: Number of characters printed.
 */

int print_rot13string(va_list args, char output_buffer[],
					  int format_flag, int min_width, int precision, int size_spec)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char original[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(args, char *);
	UNUSED(output_buffer);
	UNUSED(format_flag);
	UNUSED(precision);
	UNUSED(size_spec);
	UNUSED(min_width);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; original[j]; j++)
		{
			if (original[j] == str[i])
			{
				x = rot13[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}

		/* If character is not in original, print as it is*/
		if (!original[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}

/**
 * print_pointer - Prints the value of a pointer variable
 * @args: The list of arguments
 * @output_buffer: The buffer array to handle print
 * @format_flag:  The active flags
 * @min_width: The width specification (UNUSED)
 * @precision: The precision specification (UNUSED)
 * @size_spec: The size specifier (UNUSED)
 *
 * Return: Number of characters printed.
 */

int print_pointer(va_list args, char output_buffer[],
				  int format_flag, int min_width, int precision, int size_spec)
{
	char extra_c = 0, padding_char = ' ';
	int index = BUFF_SIZE - 2, length = 2, padding_start = 1;
	unsigned long num_address;
	char hex_map[] = "0123456789abcdef";
	void *address = va_arg(args, void *);

	UNUSED(size_spec);
	UNUSED(min_width);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	output_buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_address = (unsigned long)address;

	while (num_address > 0)
	{
		output_buffer[index--] = hex_map[num_address % 16];
		num_address /= 16;
		length++;
	}

	/* Handle formatting flags */
	if ((format_flag & FLAG_ZERO) && !(format_flag & FLAG_MINUS))
		padding_char = '0';
	if (format_flag & FLAG_PLUS)
		extra_c = '+', length++;
	else if (format_flag & FLAG_SPACE)
		extra_c = ' ', length++;

	index++;

	return (write_formatted_ptr(output_buffer, index, length,
								min_width, format_flag, padding_char, extra_c, padding_start));
}

/**
 * print_non_printable - Prints ASCII codes in hex of non-printable characters
 * @args: The list of arguments
 * @output_buffer: The buffer array to handle print
 * @format_flag:  The active flags (UNUSED)
 * @min_width: The width specification (UNUSED)
 * @precision: The precision specification (UNUSED)
 * @size_spec: The size specifier (UNUSED)
 *
 * Return: Number of characters printed
 */

int print_non_printable(va_list args, char output_buffer[],
						int format_flag, int min_width, int precision, int size_spec)
{
	int i = 0, hex_offset = 0;
	char *str = va_arg(args, char *);

	UNUSED(format_flag);
	UNUSED(min_width);
	UNUSED(precision);
	UNUSED(size_spec);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			output_buffer[i + hex_offset] = str[i];
		else
			hex_offset += append_hex_code(str[i], output_buffer, i + hex_offset);

		i++;
	}

	output_buffer[i + hex_offset] = '\0';

	return (write(1, output_buffer, i + hex_offset));
}
