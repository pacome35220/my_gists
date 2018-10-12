#include <stdio.h>

int main()
{
  int foo = 10;
  int bar = 9321;

  printf("foo: %d, bar: %d\n", foo, bar);
  foo ^= bar;
  bar ^= foo;
  foo ^= bar;
  printf("foo: %d, bar: %d\n", foo, bar);
}
