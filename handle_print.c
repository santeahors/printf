#include "main.h"
/**
 * handle_print - Function for handling the printing process.
 * @fmt: The format specifier.
 * @i: Index used for calculating length, width, etc.
 * @list: Variable parameter list.
 * @buffer: Buffer where the result is temporarily stored.
 * @flags: Flags that control edge cases and formatting.
 * @width: Width of the argument.
 * @precision: Precision of the argument.
 * @size: Size of the argument.
 * @printed_chars: Pointer to the count of printed characters.
 *
 * Return: 0 on success.
 */
int handle_print(
	const char *fmt,
	int *i,
	va_list list, char buffer[], int flags, int width, int precision, int size)
{
	int chars_written = 0;
	char format_specifier;

	if (valid_format_specifier(fmt[*i]))
	{
		format_specifier = fmt[*i];
		switch (format_specifier)
		{
			case "d":
			case "d":
			chars_written =
				print_int(va_arg(list, int), buffer, flags, width, precision, size);
			break;
			case "c":
			chars_written =
				print_int(va_arg(list, int), buffer, flags, width, precision, size);
			break;
			case "s":
			chars_written =
				print_string(va_arg(list, char*), buffer, flags, width, precision, size);
			break;
			case "b":
			chars_written = print_binary(
					va_arg(list, unsigned int), buffer, flags, width, precision, size);
			break;
			default:
			chars_written =
				handle_unknown_format(fmt[*i], buffer);
			break;
		}
	}
	else
	{
		buffer[0] = fmt[*i];
		chars_written = 1;
	}
	(*i)++;
	*print_chars += chars_written;

	va_end(list);
	return (0);
}
