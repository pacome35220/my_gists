#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/*
** attribut apply on function declaration, not definition.
*/

void die(const char *format, ...) __attribute__((format(printf, 1, 2)));

void die(const char *format, ...)
{
	va_list args;
	va_start (args, format);

	vprintf(format, args);
	va_end(args);
	exit(1);
}

int main()
{

	die("%s %s%c%d%d", "foo", "bar", '\n');
}
