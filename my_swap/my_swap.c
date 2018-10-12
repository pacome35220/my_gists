#include <stdio.h>
#include <stdint.h>

// This should work on all primitive besides float.

#define swap(type, x, y) do {			\
    x = (type)((uintptr_t)x ^ (uintptr_t)y);	\
    y = (type)((uintptr_t)y ^ (uintptr_t)x);	\
    x = (type)((uintptr_t)x ^ (uintptr_t)y);	\
  } while (0)

#define swap2(type, x, y) (x = (type)((uintptr_t)x + (uintptr_t)y - (uintptr_t)(y = x)))

int main()
{
  char *foo = "foo";
  char *bar = "bar";

  printf("foo: %s, bar: %s\n", foo, bar);
  swap(char *, foo, bar);
  printf("foo: %s, bar: %s\n", foo, bar);
  swap2(char *, foo, bar);
  printf("foo: %s, bar: %s\n", foo ,bar);
}
