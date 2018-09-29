#define _GNU_SOURCE
#include <limits.h>
#include <stdio.h>

void __sub(void *i, size_t size)
{
	if (size == UCHAR_WIDTH)
		*(char *) i += UCHAR_MAX;
	else if (size == USHRT_WIDTH)
		*(short *) i += USHRT_MAX;
	else if (size == UINT_WIDTH)
		*(int *) i += UINT_MAX;
	else if (size == ULONG_WIDTH)
		*(long *) i += ULONG_MAX;
	else
		*(size_t *) i += ULLONG_MAX;
}

#define sub(i)  __sub(i, sizeof(*i) * CHAR_BIT)

int main(void)
{
	int number = 42;

	printf("%d\n", number);

	sub(&number);

	printf("%d\n", number);
	return 0;
}
