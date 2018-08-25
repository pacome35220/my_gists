#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct {
	int *n;
	char *str;
	void *data;
} data;

void destructor(void)
{
	puts(data.str);
	puts("Goodbye !");

	free(data.n);
	free(data.str);
	free(data.data);
}

int main(void)
{
	data.n = malloc(sizeof(int) * 10);
	data.str = strdup("Hello World !");
	data.data = malloc(500);
	atexit(destructor);

	/* doing stuff */

	return 0;
}
