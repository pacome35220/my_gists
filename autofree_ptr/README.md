The cleanup attribute runs a function when the variable goes out of scope.
---------------


You can simplify the syntax by using a macro :

```C
#define autofree(free_func) __attribute__((cleanup(free_func)))
```
