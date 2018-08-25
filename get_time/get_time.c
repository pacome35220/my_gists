#include <stdio.h>
#include <time.h>

void get_time(char *buffer, size_t buflen)
{
	struct tm tm;
	time_t now;

	now = time(NULL);
	localtime_r(&now, &tm);
	snprintf(buffer, buflen, "%2.2d:%2.2d:%2.2d ", tm.tm_hour, tm.tm_min, tm.tm_sec);
}

int main()
{
	char buf[BUFSIZ];

	get_time(buf, sizeof(buf));
	printf("%s\n", buf);
	return 0;
}
