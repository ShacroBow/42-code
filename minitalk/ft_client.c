/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:26:21 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/02/27 18:49:49 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_sendbit(int pid, int signal)
{
	int	check;

	check = 0;
	usleep(20);
	if (signal == SIGUSR1)
	{
		check = kill(pid, SIGUSR1);
		if (check == -1)
		{
			write(1, "kill failed - general faliure\n", 30);
			exit(1);
		}
		pause();
	}
	if (signal == SIGUSR2)
	{
		check = kill(pid, SIGUSR2);
		if (check == -1)
		{
			write(1, "kill failed - general faliure\n", 30);
			exit(1);
		}
		pause();
	}
}

static void	ft_handler(int signal)
{
	if (signal == SIGUSR1)
	{
		write(1, "server ping\n", 12);
	}
	else if (signal == SIGUSR2)
	{
		write(1, "server end confirmation\n", 24);
		exit(0);
	}
}

static void	ft_sendto_server(int pid, const char *str)
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
				ft_sendbit(pid, SIGUSR1);
			else
				ft_sendbit(pid, SIGUSR2);
			i++;
			byte = (byte << 1);
		}
		str++;
	}
	i = 0;
	while (i++ < 8)
		ft_sendbit(pid, SIGUSR2);
}

static void	*ft_sendlength(int pid, const char *str)
{
	int		i;
	int		len;
	char	buf[20];
	char	*sendint;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	while (i < 19)
		buf[i++] = '\0';
	if (len > 10000)
		return (write(2, "len error\n", 10), NULL);
	if (len == 0)
		return (ft_sendto_server(pid, "0"), (void *)str);
	while (len > 0)
	{
		buf[--i] = (len % 10) + '0';
		len /= 10;
	}
	buf[19] = '\0';
	sendint = buf + i;
	ft_sendto_server(pid, sendint);
	return (sendint);
}

int	main(int argc, char **argv)
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
		return (write(1, "kill failed - pid incorrect?\n", 29), 1);
	sigemptyset(&(s_client.sa_mask));
	s_client.sa_flags = SA_RESTART;
	s_client.sa_handler = ft_handler;
	write(1, "pid[", 4);
	ft_putnbr(getpid());
	write(1, "]\n", 2);
	ft_sigactionhandle(s_client);
	if (ft_sendlength(pid, argv[2]) != NULL)
		ft_sendto_server(pid, argv[2]);
	else
		return (1);
	return (0);
}
