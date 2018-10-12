#include <stdio.h>

void foo(int *ptr)
{
	printf("%d\n", *ptr);
}

int main()
{
	// Using a variable;
	int hello_i_m_useless = 123;

	foo(&hello_i_m_useless);
	// Using anonymous arrays
	foo((int[]){123});
	return 0;
}
