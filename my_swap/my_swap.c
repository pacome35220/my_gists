#include <stdio.h>
#include <stdint.h>

// This should work on all primitive besides float.

#define swap(x, y) do {					\
    x = (typeof(x))((uintptr_t)x ^ (uintptr_t)y);	\
    y = (typeof(x))((uintptr_t)y ^ (uintptr_t)x);	\
    x = (typeof(x))((uintptr_t)x ^ (uintptr_t)y);	\
  } while (0)

#define swap2(x, y) (x = (typeof(x))((uintptr_t)x + (uintptr_t)y - (uintptr_t)(y = x)))

int main()
{
  char *foo = "foo";
  char *bar = "bar";

  printf("foo: %s, bar: %s\n", foo, bar);
  swap(foo, bar);
  printf("foo: %s, bar: %s\n", foo, bar);
  swap2(foo, bar);
  printf("foo: %s, bar: %s\n", foo ,bar);
}
