Many libC functions return a pointer to a structure allocated in the stack, with a static keyword, to avoid malloc.
---------------

### https://gist.github.com/38cff048a386fff6f6cdac7d6239d319
---------------


It's not a good practice, but you can do the same with a buffer, to avoid malloc.

```C
char *my_getcwd()
{
	static char buffer[1024];

        getcwd(buffer, sizeof(buffer));
	return buffer;
}
```

Normally, the compiler will say `function returns address of local variable`, but with `static` keyword, you can get it !
