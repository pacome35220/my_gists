#include <signal.h>
#include <stdlib.h>

void signal_handler(int signum)
{
	psignal(signum, "Landing smoothly after intercepting a ");
	exit(1);
}

int main()
{
	signal(SIGSEGV, signal_handler);
	raise(SIGSEGV); /* raise(3) send a signal to calling process */
	return 0;
}
