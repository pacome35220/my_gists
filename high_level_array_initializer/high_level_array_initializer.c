#include <stdio.h>

int main()
{
	int foo[10] = { [0 ... 4] = 1, [5 ... 8] = 2, [9] = 3 };

	for (int i = 0; i < 10; i++)
		printf("%d ", foo[i]);
	return 0;
}
