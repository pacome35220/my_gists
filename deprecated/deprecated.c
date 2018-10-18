#include <stdio.h>
#include <unistd.h>
#include <string.h>


/*
** Deprecating function.
*/

void foo() __attribute__((deprecated));

void foo()
{
	write(1, "foo\n", strlen("foo\n"));
}

/*
** Deprecate a type
*/

typedef int T __attribute__ ((deprecated));

/*
** Deprecate a variable
*/

int g_var __attribute__((deprecated)) = 3231 & 312321;

int main()
{
	foo();	// Bro, this is deprecated, that's like... not cool.
	T x __attribute__((unused)); // Another attribute ;)
	printf("%d\n", g_var);
	return 0;
}
