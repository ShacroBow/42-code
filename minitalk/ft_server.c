/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:26:17 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/02/27 17:53:20 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_global	g_var;

static void	ft_mallocfail(void)
{
	write(2, "malloc fail\n", 12);
	exit(1);
}

static void	ft_readlength(void)
{
	if ((g_var.ln < 6) && (g_var.byte == 0 && g_var.i > 7))
	{
		g_var.ln = ft_atoi(g_var.ptr);
		write(1, g_var.ptr, g_var.count);
		write(1, " = len\n", 7);
		if (g_var.ln <= 5)
			g_var.ln = 7;
		if (g_var.ptr != NULL)
		{
			free(g_var.ptr);
			g_var.ptr = NULL;
		}
		g_var.count = 0;
		g_var.i = 0;
		g_var.ptr = ft_calloc(g_var.ln + 1, sizeof(unsigned char));
		if (g_var.ptr == NULL)
			ft_mallocfail();
	}
	if (g_var.ln <= 4 && (g_var.i > 7))
	{
		g_var.ln++;
		g_var.ptr[g_var.ln] = g_var.byte;
		g_var.i = 0;
		g_var.byte = 0;
	}
}

static void	ft_writeorping(siginfo_t *info)
{
	usleep(60);
	if (g_var.ln < 6)
		ft_readlength();
	if (g_var.ln > 5 && g_var.byte == 0 && g_var.i > 7)
	{
		write(1, g_var.ptr, g_var.count);
		write(1, "\n", 1);
		kill(info->si_pid, SIGUSR2);
		if (g_var.ptr != NULL)
		{
			free(g_var.ptr);
			g_var.ptr = NULL;
		}
	}
	else
		kill(info->si_pid, SIGUSR1);
}

static void	ft_handler(int signal, siginfo_t *info, void *nothing)
{
	if (signal == SIGUSR1)
		g_var.byte = (g_var.byte) | (128 >> g_var.i);
	g_var.i++;
	if (g_var.i == 8 && g_var.byte != 0)
	{
		g_var.ptr[(g_var.count)] = g_var.byte;
		g_var.byte = 0;
		g_var.i = 0;
		g_var.count++;
	}
	if (g_var.i > 8 || (nothing == (void *)-1 && nothing == (void *)1))
	{
		g_var.i = 1;
		g_var.ln = 0;
		g_var.count = 0;
		if (g_var.ptr != NULL)
		{
			free(g_var.ptr);
			g_var.ptr = NULL;
		}
		g_var.ptr = ft_calloc(12, sizeof(unsigned char));
		if (g_var.ptr == NULL)
			ft_mallocfail();
	}
	ft_writeorping(info);
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
	g_var.byte = 0;
	g_var.i = 8;
	g_var.ptr = NULL;
	while (1)
		pause();
	return (0);
}
