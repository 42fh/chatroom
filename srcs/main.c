#include <sys/select.h>

#define NULL 0

int main(int ac, char **av)
{
	(void) av;
	(void) ac;
	struct timeval timeout;
	timeout.tv_sec = 1;
	timeout.tv_usec = 1;

	
	select(1, NULL, NULL, NULL, &timeout);
	return (0);
}

