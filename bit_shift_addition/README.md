Add two integers using only bitwise operators.
---------------


Without recursion, this may be more understandable.

```C
int add(int a, int b)
{
        int tmp;

        while (a != 0) {
                tmp = b & a;
                b = b ^ a;
                a = tmp << 1;
        }
        return b;
}
```
