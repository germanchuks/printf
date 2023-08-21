#include <unistd.h>

/**
 * _putchar - Print char
 * @c: Character to print
 *
 * Return: 1 if successful, -1 if error, NULL otherwise
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}
