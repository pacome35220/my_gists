#include <stdio.h>
#include <stdint.h>

// This should work on all primitive besides float.

#define my_swap(x, y) do {					\
		x = (typeof(x))((uintptr_t)x ^ (uintptr_t)y);	\
		y = (typeof(x))((uintptr_t)y ^ (uintptr_t)x);	\
		x = (typeof(x))((uintptr_t)x ^ (uintptr_t)y);	\
	} while (0)

int main()
{
	char *foo = "foo";
	char *bar = "bar";

	printf("foo: %s, bar: %s\n", foo, bar);
	my_swap(foo, bar);
	printf("foo: %s, bar: %s\n", foo ,bar);
}
