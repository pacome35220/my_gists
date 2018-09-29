Add two integers using only bitwise operators.
---------------

### https://gist.github.com/b24802b29585482e1fb0cb35f9321e1d
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
