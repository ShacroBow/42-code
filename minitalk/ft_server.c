
#include "minitalk.h"

t_global recieve;

static void ft_putnbr(int n)
{
	char buffer[10];
	int i = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	while (n > 0)
	{
		buffer[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	while (i > 0)
		write(1, &buffer[--i], 1);
}

static void ft_handler(int signal, siginfo_t *info, void *nothing)
{
	if (0)
		nothing++;
	if (signal == SIGUSR1)
		recieve.byte = (recieve.byte << 1) | 1;
	else
		recieve.byte = recieve.byte << 1;
	recieve.i++;
	if (recieve.i == 8 && recieve.byte != 0)
	{
		write(1, &(recieve.byte), 1);
		recieve.byte = 0;
		recieve.i = 0;
		usleep(50);
	}
	kill(info->si_pid, SIGUSR1);
	if (recieve.byte == 0 && recieve.i == 8)
	{
		write(1, "\n", 1);
		recieve.i = 0;
		kill(info->si_pid, SIGUSR2);
	}
}

int main(void)
{
	struct sigaction s_server;

	sigemptyset(&(s_server.sa_mask));
	s_server.sa_flags = SA_SIGINFO | SA_RESTART;
	s_server.sa_sigaction = ft_handler;
	if (sigaction(SIGUSR1, &s_server, NULL) || sigaction(SIGUSR2, &s_server, NULL))
	{
		write(1, "sigaction fail\n", 15);
		exit(1);
	}
	write(1, "pid[", 4);
	ft_putnbr(getpid());
	write(1, "]\n", 2);
	recieve.byte = 0;
	recieve.i = 0;
	while (1)
		pause();
	return (0);
}