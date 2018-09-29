Different implementations of subtraction without using the '-' operator
---------------

### https://gist.github.com/be6599eda0c2a297a3756c68e812058d
---------------


The trick is to add the maximum value that can be stored by the type and to take advantage of the [integer overflow](https://en.wikipedia.org/wiki/Integer_overflow).

All macros used here are defined in `limits.h`
Another implementation is to use [ones' complement](https://en.wikipedia.org/wiki/Ones%27_complement) with [NOT ('~') operator](https://en.wikipedia.org/wiki/Bitwise_operation#NOT).

```C
#include <stdio.h>

int sub(int a, int b)
{
        return a + (~b) + 1;
}

int main(void)
{
        printf("%d - %d = %d\n", 4, 7, sub(4, 7)); // print "4 - 7 = -3"
        return 0;
}
```
