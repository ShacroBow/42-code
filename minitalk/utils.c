/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:25:50 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/02/11 13:39:16 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int n)
{
	char	buffer[10];
	int		i;

	i = 0;
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

int	ft_atoi(const char *nptr)
{
	int		i;
	int		j;
	int		k;
	char	*ptr;

	i = 0;
	j = 1;
	k = 0;
	ptr = (char *)nptr;
	while ((ptr[i] >= 9 && ptr[i] <= 13) || ptr[i] == 32)
		i++;
	if (ptr[i] == '-' || ptr[i] == '+')
	{
		if (ptr[i] == '-')
			j = (j * -1);
		i++;
	}
	while (ptr[i] >= 48 && ptr[i] <= 57)
	{
		k *= 10;
		k += (ptr[i] - 48);
		i++;
	}
	return (k * j);
}

void	ft_sigactionhandle(struct sigaction s_target)
{
	if (sigaction(SIGUSR1, &s_target, NULL) || \
		sigaction(SIGUSR2, &s_target, NULL))
	{
		write(1, "sigaction fail\n", 15);
		exit(1);
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			sizecheck;
	size_t			i;
	unsigned char	*ptr;

	sizecheck = nmemb * size;
	if (sizecheck != 0 && sizecheck / nmemb != size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (0);
	i = 0;
	while (i != (nmemb * size))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
