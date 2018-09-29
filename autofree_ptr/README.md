The cleanup attribute runs a function when the variable goes out of scope.
---------------

### https://gist.github.com/a448be546c18a71e34b429c3081b64d8
---------------


You can simplify the syntax by using a macro :

```C
#define autofree(free_func) __attribute__((cleanup(free_func)))
```
