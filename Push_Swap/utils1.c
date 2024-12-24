/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:15:03 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/12/20 20:56:34 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

long	ft_atol(const char *nptr, int *len)
{
	int			i;
	long int	sign;
	long int	res;

	if (nptr == NULL || nptr[0] == '\0')
		return (0);
	i = 0;
	*len = 0;
	sign = 1;
	while ((nptr[i] == '-' || nptr[i] == '+') || ft_isspace(nptr[i]))
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	res = 0;
	while (nptr[i] == '0')
		i++;
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		res= (res * 10) + (nptr[i] - '0');
		i++;
		*len += 1;
	}
	return (res * sign);
}

char *ft_proper_input(char *str)
{
	size_t	i;
	short	in;

	i = 0;
	in = 1;
	if (str == NULL)
		return (NULL);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) || ((str[i] == '-'|| str[i] == '+') && in == 1)))
			return (NULL);
		if ((str[i] == '-'|| str[i] == '+') && in == 0)
			return (NULL);
		if ((str[i] == '-'|| str[i] == '+') && in == 1)
			in = 1;
		else if (in == 1)
			in = 0;
		i++;
	}
	return (str);
}

int	ft_count_arguments(char *str)
{
	long int	i;
	long int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]))
		 i++;
		if (ft_isdigit(str[i]) || (str[i] == '-'|| str[i] == '+'))
			j += 1;
		while (ft_isdigit(str[i]) || (str[i] == '-'|| str[i] == '+'))
			i++;
	}
	return (j);
}

char	*ft_skipwhitespace(char *str)
{
	int i;

	i = 0;
	if (str == NULL || str[i] == '\0')
		return NULL;// ft_exiterror(NULL);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (str + i);
}

void ft_exiterror(void *str)
{
	if (str != NULL)
		free(str);
	write(2, "Error\n", 6);
	exit(1);
}