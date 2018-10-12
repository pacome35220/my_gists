#include "stdio.h"

int sample_function(int *ptr)
{
  printf("%d\n", *ptr);
}

int main()
{
  // Using a variable;
  int hello_i_m_useless = 123;

  sample_function(&hello_i_m_useless);
  // Using anonymous arrays
  sample_function((int[]){123});
  return 0;
}
