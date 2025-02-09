
#include "minitalk.h"

static void ft_handler(int signal)
{
	if (signal == SIGUSR1)
	{
		write(1, "server confirmation\n", 20);
	}
	else if (signal == SIGUSR2)
	{
		write(1, "server end confirmation\n", 24);
		exit(0);
	}
}
static void ft_sendto_server(int pid, const char *str)
{
	int				i;
	unsigned char	byte;

	i = 0;
	byte = 0;
	while (*str)
	{
		byte = *str;
		i = 0;
		while (i < 8)
		{
			if (byte & 128)
				kill(pid, SIGUSR1) == -1;
			else if (!(byte & 128))
				kill(pid, SIGUSR2) == -1;
			i++;
			byte = (byte << 1);
			pause();
		}
		str++;
	}
	while (1)
		kill(pid, SIGUSR2);
}
int main(int argc, char **argv)
{
	int					pid;
	struct sigaction	s_client;

	if (argc != 3)
	{
		write(1, "invalid input. needed \"./client <pid> <message>\"", 48);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) < 0)
	{
		write(1, "kill failed - pid incorrect?\n", 29);
		return (1);
	}
	sigemptyset(&(s_client.sa_mask));
	s_client.sa_flags = SA_RESTART;
	s_client.sa_handler = ft_handler;
	printf("clientpid%d\n", getpid());
	if (sigaction(SIGUSR1, &s_client, NULL) || sigaction(SIGUSR2, &s_client, NULL))
	{
		write(1, "sigaction fail\n", 15);
		exit(1);
	}
	ft_sendto_server(pid, argv[2]);
	return (0);
}