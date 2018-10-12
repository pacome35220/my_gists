#include <stdio.h>
#include <stdint.h>

// This should work on all primitive besides float.

#define swap(type, x, y) do {			\
    x = (type)((uintptr_t)x ^ (uintptr_t)y);	\
    y = (type)((uintptr_t)y ^ (uintptr_t)x);	\
    x = (type)((uintptr_t)x ^ (uintptr_t)y);	\
  } while (0)

int main()
{
  char *foo = "10";
  char *bar = "-932";

  printf("foo: %s, bar: %s\n", foo, bar);
  swap(char *, foo, bar);
  printf("foo: %s, bar: %s\n", foo, bar);
}
