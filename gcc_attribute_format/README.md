Tell gcc to check parameters type and display warning on function that use format string, such as printf, scanf, strftime or strfmon
---------------

### https://gist.github.com/998dc05976282badc5ce53a0ba7000f1
---------------


The usage is simple :
 ```C
__attribute__((format(archetype, string-index, first-to-check)))
```
- _archetype_  determines how the format string is interpreted, and should be printf, scanf, strftime or strfmon.
- _string-index_ specifies which argument is the format string (starting from 1).
- _first-to-check_ is the number of the first variadic argument corresponding (or not) to format string.
