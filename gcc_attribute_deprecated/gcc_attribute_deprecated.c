#include <stdio.h>
#include <string.h>
#include <unistd.h>

/*
 * Deprecating function.
 */

void foo() __attribute__ ((deprecated));

void foo()
{
        write(1, "foo\n", strlen("foo\n"));
}

/*
 * Deprecate a type
 */

typedef int my_type __attribute__ ((deprecated));

/*
 * Deprecate a variable
 */

int g_var __attribute__((deprecated)) = 3231 & 312321;

int main()
{
	my_type x __attribute__((unused)); // Another attribute ;)

	foo();  // Bro, this is deprecated, that's like... not cool.
	printf("%d\n", g_var);
	return 0;
}
