A use case of ioctl() to get the size (in character) of the current terminal
---------------


A mysterious legend says that there are two variables in the `struct winsize`  [definition](https://github.com/lattera/glibc/blob/master/bits/ioctl-types.h#L69) in glibc, which represents the pixel size of the terminal.

```C
struct winsize
{
  unsigned short int ws_row;	/* Rows, in characters.  */
  unsigned short int ws_col;	/* Columns, in characters.  */

  /* These are not actually used.  */
  unsigned short int ws_xpixel;	/* Horizontal pixels.  */
  unsigned short int ws_ypixel;	/* Vertical pixels.  */
};
```

But as the comment says in the [glibc file](https://github.com/lattera/glibc/blob/master/bits/ioctl-types.h#L69), these 2 variables are unused by ioctl(), and so unusable.
