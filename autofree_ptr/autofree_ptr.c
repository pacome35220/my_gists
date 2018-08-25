#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct test
{
	int data;
	char *str;
};

struct test *init(int data)
{
	struct test *t = malloc(sizeof *t);

	t->data = data;
	t->str = strdup("Hello World !");
	return t;
}

void print_data(struct test *t)
{
	printf("%d\n", t->data);
	printf("%s\n", t->str);
}

void destroy(struct test **t)
{
	free((*t)->str);
	free(*t);
}

int main(void)
{
	__attribute__((cleanup(destroy))) struct test *t = init(23);

	print_data(t);
	return 0; // no memory leaks                                                          
}
