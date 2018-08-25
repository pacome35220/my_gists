#include <stdio.h>

typedef struct
{
	int a;
	int b;
	int c;
} info_t;

info_t info[] = {
	{0, 1, 2},
	{3, 4, 5},
	{6, 7, 8},
	{9, 10, 11},
	{12, 13, 14},
	{15, 16, 17}
};

#define SIZEOF(x)	(sizeof(x) / sizeof(x[0]))

int main()
{
        for (int i = 0; i < SIZEOF(info); i++)
                ;//doing some stuff
        printf("array length : %d\n", SIZEOF(info));
        return 0;
}
