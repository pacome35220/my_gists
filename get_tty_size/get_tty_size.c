#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

int get_tty_size(struct winsize *ws, int fd)
{
	if (isatty(fd) && ioctl(fd, TIOCGWINSZ, ws) != -1)
		return 0;
	return -1;
}

int main()
{
	struct winsize ws;
	int fd = STDIN_FILENO;  /* fd must be an open file descriptor referred to a tty */

	if (get_tty_size(&ws, fd) == -1) {
		perror(NULL);   /* perror to know why the error occurred */
		return 1;
	}
	printf("Rows: %d\n", ws.ws_row);
	printf("Cols: %d\n", ws.ws_col);
	return 0;
}
