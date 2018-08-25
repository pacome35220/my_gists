#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MY_ASSERT(expression)						\
	if (expression)							\
		;							\
	else {								\
		fprintf(stderr, "%s:%d: %s: Assertion `%s' failed.\n",	\
			__FILE__,					\
			__LINE__,					\
			__ASSERT_FUNCTION,				\
			#expression);					\
		abort();						\
	}

int main(void)
{
	int i = 0;

	MY_ASSERT(i == 0);
	MY_ASSERT(i == 1);
	return 0;
}
