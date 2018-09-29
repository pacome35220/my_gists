A simple combination of time(), localtime_r() and snprintf() to get the current time.
---------------

### https://gist.github.com/d216cd65ee388e8c11957e3f71de4a2a
---------------


To simply get the current date + time :

```C
#include <stdio.h>
#include <time.h>

int main()
{
        time_t t = time(NULL);
        char *buffer = ctime(&t);

	printf("%s", buffer);
        return 0;
}
```

Be careful, `ctime` put a '\n' at the end of buffer.
A posix implementation is to use strftime()

```C
#include <time.h>
#include <stdio.h>

#define FULL_DATE_TIME  "%c"    /* Thu Aug 16 13:12:47 2018 */
#define DATE            "%D"	/* 08/16/18 */
#define ISO_DATE        "%F"    /* 2018-08-16 */
#define TIME            "%X"    /* 13:18:08 */

int main()
{
        char buffer[128];
        time_t t = time(NULL);
        struct tm *tm = localtime(&t);

        strftime(buffer, sizeof(buffer), FULL_DATE_TIME, tm);
        printf("%s\n", buffer);
        return 0;
}
```
You can combine them like printf format.

```C
strftime(buffer, sizeof(buffer), "Day : %A, Month: %B, Hour: %H", tm);
/* Day : Thursday, Month: August, Hour: 13 */
```
