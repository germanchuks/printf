#include "main.h"

/**
 * handle_write_char - Prints a string
 * @c: char types.
 * @output_buffer: Buffer array to handle print
 * @format_flags:  Calculates active flags.
 * @min_width: get width.
 * @precision: precision specifier
 * @size_spec: Size specifier
 *
 * Return: Number of chars printed.
 */
int handle_write_char(char c, char output_buffer[],
					  int format_flags, int min_width, int precision, int size_spec)
{
	int i = 0;
	char padding_char = ' ';

	UNUSED(precision);
	UNUSED(size_spec);

	if (format_flags & FLAG_ZERO)
		padding_char = '0';

	output_buffer[i++] = c;
	output_buffer[i] = '\0';

	if (min_width > 1)
	{
		output_buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < min_width - 1; i++)
			output_buffer[BUFF_SIZE - i - 2] = padding_char;

		if (format_flags & FLAG_MINUS)
			return (write(1, &output_buffer[0], 1) +
					write(1, &output_buffer[BUFF_SIZE - i - 1], min_width - 1));
		else
			return (write(1, &output_buffer[BUFF_SIZE - i - 1], min_width - 1) +
					write(1, &output_buffer[0], 1));
	}

	return (write(1, &output_buffer[0], 1));
}

/**
 * write_num_buff - Write a number using a bufffer
 * @indx: The index at which the number starts on the buffer
 * @buff_out: The buffer
 * @fmt_flags: The active Flags
 * @min_width: The width specifier
 * @prec: The Precision specifier
 * @len: The number length
 * @padd_char: The padding character
 * @prefix_char: The extra character
 * Return: Number of printed characters.
 */

int write_num_buff(int indx, char buff_out[], int fmt_flags, int min_width,
				   int prec, int len, char padd_char, char prefix_char)
{
	int i, padd_start = 1;

	if (prec == 0 && indx == BUFF_SIZE - 2 && buff_out[indx]
			== '0' && min_width == 0)
		return (0);
	if (prec == 0 && indx == BUFF_SIZE - 2 && buff_out[indx] == '0')
		buff_out[indx] = padd_char = ' ';
	if (prec > 0 && prec < len)
		padd_char = ' ';
	while (prec > len)
		buff_out[--indx] = '0', len++;
	if (prefix_char != 0)
		len++;
	if (min_width > len)
	{
		for (i = 1; i < min_width - len + 1; i++)
			buff_out[i] = padd_char;
		buff_out[i] = '\0';
		if (fmt_flags & FLAG_MINUS && padd_char == ' ')
		{
			if (prefix_char)
				buff_out[--indx] = prefix_char;
			return (write(1, &buff_out[indx], len) +
					write(1, &buff_out[1], i - 1));
		}
		else if (!(fmt_flags & FLAG_MINUS) && padd_char == ' ')
		{
			if (prefix_char)
				buff_out[--indx] = prefix_char;
			return (write(1, &buff_out[1], i - 1) +
					write(1, &buff_out[indx], len));
		}
		else if (!(fmt_flags & FLAG_MINUS) && padd_char == '0')
		{
			if (prefix_char)
				buff_out[--padd_start] = prefix_char;
			return (write(1, &buff_out[padd_start], i - padd_start) +
					write(1, &buff_out[indx], len - (1 - padd_start)));
		}
	}
	if (prefix_char)
		buff_out[--indx] = prefix_char;
	return (write(1, &buff_out[indx], len));
}

/**
 * write_integer - Writes a formatted number to a buffer
 * @is_negative: Indicates if number is negative
 * @index: The starting index in the buffer
 * @output_buffer: The buffer array to handle print
 * @format_flags: The active flags
 * @min_width: The minimum output width
 * @precision: The precision specifier
 * @size_spec: The size specifier
 *
 * Return: Number of characters printed.
 */

int write_integer(int is_negative, int index, char output_buffer[],
				  int format_flags, int min_width, int precision, int size_spec)
{
	int length = BUFF_SIZE - index - 1;
	char padding_char = ' ', extra_ch = 0;

	UNUSED(size_spec);

	if ((format_flags & FLAG_ZERO) && !(format_flags & FLAG_MINUS))
		padding_char = '0';
	if (is_negative)
		extra_ch = '-';
	else if (format_flags & FLAG_PLUS)
		extra_ch = '+';
	else if (format_flags & FLAG_SPACE)
		extra_ch = ' ';

	return (write_num_buff(index, output_buffer, format_flags, min_width,
						   precision, length, padding_char, extra_ch));
}

/**
 * write_formatted_ptr - Write a memory address
 * @buff_out: Arrays of characters to store the formatted output
 * @indx: The index at which the number starts in the buffer
 * @len: The length of the hexadecimal number
 * @min_width: The width specifier
 * @fmt_flags: The flags specifier
 * @padd_char: The character representing the padding
 * @prefix_char: The character representing extra char
 * @padd_start: The index at which padding should start
 *
 * Return: Number of written characters.
 */

int write_formatted_ptr(char buff_out[], int indx, int len, int min_width,
						int fmt_flags, char padd_char, char prefix_char, int padd_start)
{
	int i;

	if (min_width > len)
	{
		for (i = 3; i < min_width - len + 3; i++)
			buff_out[i] = padd_char;
		buff_out[i] = '\0';
		if (fmt_flags & FLAG_MINUS && padd_char == ' ')
		{
			buff_out[--indx] = 'x';
			buff_out[--indx] = '0';
			if (prefix_char)
				buff_out[--indx] = prefix_char;
			return (write(1, &buff_out[indx], len) +
					write(1, &buff_out[3], i - 3));
		}
		else if (!(fmt_flags & FLAG_MINUS) && padd_char == ' ')
		{
			buff_out[--indx] = 'x';
			buff_out[--indx] = '0';
			if (prefix_char)
				buff_out[--indx] = prefix_char;
			return (write(1, &buff_out[3], i - 3) +
					write(1, &buff_out[indx],
						  len));
		}
		else if (!(fmt_flags & FLAG_MINUS) && padd_char == '0')
		{
			if (prefix_char)
				buff_out[--padd_start] = prefix_char;
			buff_out[1] = '0';
			buff_out[2] = 'x';
			return (write(1, &buff_out[padd_start], i - padd_start) +
					write(1, &buff_out[indx], len - (1 - padd_start) - 2));
		}
	}
	buff_out[--indx] = 'x';
	buff_out[--indx] = '0';
	if (prefix_char)
		buff_out[--indx] = prefix_char;
	return (write(1, &buff_out[indx], BUFF_SIZE - indx - 1));
}

/**
 * write_unsigned_int - Writes an unsigned number
 * @is_negative: Not used for unsigned numbers
 * @i: The index at which the number starts in the buffer
 * @output_buffer: The array of characters to store the formatted output
 * @format_flags: The flags specifier
 * @min_width: The width specifier
 * @precision: The precision specifier
 * @size_spec: The size specifier
 *
 * Return: Number of written characters.
 */

int write_unsigned_int(int is_negative, int i,
					   char output_buffer[],
					   int format_flags, int min_width, int precision, int size_spec)
{
	int length = BUFF_SIZE - i - 1;
	int chars_written = 0;
	char padding_char = ' ';

	UNUSED(is_negative);
	UNUSED(size_spec);

	if (precision == 0 && i == BUFF_SIZE - 2 && output_buffer[i] == '0')
		return (0);

	if (precision > 0 && precision < length)
		padding_char = ' ';

	while (precision > length)
	{
		output_buffer[--i] = '0';
		length++;
	}

	if ((format_flags & FLAG_ZERO) && !(format_flags & FLAG_MINUS))
		padding_char = '0';

	if (min_width > length)
	{
		for (chars_written = 0; chars_written < min_width - length; chars_written++)
			output_buffer[chars_written] = padding_char;

		output_buffer[chars_written] = '\0';

		if (format_flags & FLAG_MINUS)
			return (write(1, &output_buffer[i], length) +
					write(1, &output_buffer[0],
						  chars_written));
		else
			return (write(1, &output_buffer[0], chars_written) +
					write(1, &output_buffer[i],
						  length));
	}

	return (write(1, &output_buffer[i], length));
}
