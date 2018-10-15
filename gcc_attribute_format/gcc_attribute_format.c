#include <stdio.h>
#include <stdarg.h>

/*
 * attribute apply on function declaration, not definition.
 */

void foo(const char *format, ...) __attribute__((format(printf, 1, 2)));

void foo(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}

int main(void)
{
	foo("%s %s%c%d%d", "foo", "bar", '\n');
}
