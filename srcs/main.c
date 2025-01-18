#include <unistd.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>



void put_string_fd(const char *str, int fd)
{
	write(fd, str, strlen(str));
}

void exit_with_message(int status, const char *message)
{
	put_string_fd(message, 2);
	exit(status);
}

int main(int ac, char **av)
{
	int server_socket;
	(void) ac;
	(void) av;
		
	server_socket = socket(PF_INET, SOCK_STREAM, 0);
	if (server_socket < 0)
		exit_with_message(1, "Failed to create socket");
			

	
	struct timeval timeout;
	timeout.tv_sec = 1;
	timeout.tv_usec = 1;

	
	select(1, NULL, NULL, NULL, &timeout);
	return (0);
}

