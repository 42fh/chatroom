#include <unistd.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>

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
	if (ac != 2)
		exit_with_message(2, "please provide exactly one argument\n");		

	int server_socket;
	(void) ac;
	(void) av;
		
	server_socket = socket(PF_INET, SOCK_STREAM, 0);
	if (server_socket < 0)
		exit_with_message(10, "Failed to create socket");
			
	struct in_addr localhost;
	localhost.s_addr = htonl(INADDR_LOOPBACK);

	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_port = htons(atoi(av[1]));
	address.sin_addr = localhost;

	if (bind(server_socket, (struct sockaddr *) &address, sizeof(address)) < 0)
		exit_with_message(11, "bind failed\n");
	
	if (listen(server_socket, 10) < 0)
		exit_with_message(12, "listen failed\n");

	int client_socket;
	struct sockaddr_in client_address;
	socklen_t client_address_length = sizeof(client_address);

	client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);

	if (client_socket < 0)
		exit_with_message(13, "accept failed");
	else
		put_string_fd("client was just accepted\n", 1);	

	close(client_socket);
	
	struct timeval timeout;
	timeout.tv_sec = 10;
	timeout.tv_usec = 1;

	
	select(1, NULL, NULL, NULL, &timeout);
	return (0);
}

