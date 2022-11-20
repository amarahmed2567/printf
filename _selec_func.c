#include "main.h"
#include <stddef.h>

/**
 * *_selec_func - selects the functions output according to a format
 * @c: The specified format
 * @va-list: The specified format
 * Return: The function to be used
 */
int (*_selec_func(char c))(va_list)
{
	if (c == 'c')
		return (_print_char);
	if (c == 's')
		return (_print_str);

	return (NULL);
}
