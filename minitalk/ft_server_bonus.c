/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:50:23 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/02/10 14:35:14 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_global	g_recieve;

static void	ft_handler(int signal, siginfo_t *info, void *nothing)
{
	if (0)
		nothing++;
	if (signal == SIGUSR1)
		g_recieve.byte = (g_recieve.byte) | (128 >> g_recieve.i);
	g_recieve.i++;
	if (g_recieve.i == 8 && g_recieve.byte != 0)
	{
		write(1, &(g_recieve.byte), 1);
		g_recieve.byte = 0;
		g_recieve.i = 0;
	}
	usleep(20);
	if (g_recieve.byte == 0 && g_recieve.i > 7)
	{
		write(1, "\n", 1);
		g_recieve.byte = 0;
		g_recieve.i = 0;
		kill(info->si_pid, SIGUSR2);
	}
	else
		kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	s_server;

	sigemptyset(&(s_server.sa_mask));
	s_server.sa_flags = SA_SIGINFO | SA_RESTART;
	s_server.sa_sigaction = ft_handler;
	ft_sigactionhandle(s_server);
	write(1, "pid[", 4);
	ft_putnbr(getpid());
	write(1, "]\n", 2);
	g_recieve.byte = 0;
	g_recieve.i = 0;
	while (1)
		pause();
	return (0);
}
