/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:20:46 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/05/20 14:26:10 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_atoicalc_atoi(char *ptr, int i)
{
	int	k;

	k = 0;
	while (ptr[i] >= 48 && ptr[i] <= 57)
	{
		k *= 10;
		k += (ptr[i] - 48);
		i++;
	}
	return (k);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		j;
	int		k;
	char	*ptr;

	i = 0;
	j = 1;
	ptr = (char *)nptr;
	while ((ptr[i] >= 9 && ptr[i] <= 13) || ptr[i] == 32)
		i++;
	if (ptr[i] == '-' || ptr[i] == '+')
	{
		if (ptr[i] == '-')
			j = -1;
		else
			j = 1;
		i++;
	}
	k = ft_atoicalc_atoi(ptr, i);
	return (k * j);
}
