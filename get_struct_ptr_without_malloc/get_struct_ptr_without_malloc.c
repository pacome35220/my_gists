#include <stdio.h>

typedef struct
{
	int i;
	long j;
} data_t;

data_t *get_struct_ptr_without_malloc()
{
	static data_t data;
	
	data.i = 4;
	data.j = 4;
	return &data;
}

int main()
{
	data_t *data = get_struct_ptr_without_malloc();

	printf("%d\n", data->i);
	printf("%ld\n", data->j);
	return 0;
}
