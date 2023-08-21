#include "main.h"

/**
 * is_digit - Checks if a character is a digit
 * @c: Character to be evaluated
 *
 * Return: 1 if it is a digit, 0 if otherwise
 */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * is_printable - Checks if a character is printable
 * @c: Character to evaluate.
 *
 * Return: 1 if c is printable, 0 otherwise
 */

int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * size_conv_number - Casts a number to the specified size
 * @num: Number to be casted.
 * @target_size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */

long int size_conv_number(long int num, int target_size)
{
	if (target_size == SIZE_LONG)
		return (num);
	else if (target_size == SIZE_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * size_conv_unsgned - Converts an unsigned number to the specified size.
 * @num: Number to be converted.
 * @size: Target size for conversion
 *
 * Return: Casted value of num with the specified size.
 */

long int size_conv_unsgned(unsigned long int num, int size)
{
	if (size == SIZE_LONG)
		return (num);
	else if (size == SIZE_SHORT)
		return ((unsigned short)num);
	return ((unsigned int)num);
}

/**
 * append_hex_code - Append ASCII in hexadecimal code to buffer
 * @output_buffer: Array of characters.
 * @index: Index to start append.
 * @ascii_code: ASCII CODE.
 * Return: 1 Always.
 */

int append_hex_code(char ascii_code, char output_buffer[], int index)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	output_buffer[index++] = '\\';
	output_buffer[index++] = 'x';

	output_buffer[index++] = map_to[ascii_code / 16];
	output_buffer[index] = map_to[ascii_code % 16];

	return (1);
}
