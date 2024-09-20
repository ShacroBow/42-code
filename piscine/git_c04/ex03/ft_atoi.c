/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:02:51 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/06/24 15:30:31 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	j = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			j++;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		k *= 10;
		k += (str[i] - 48);
		i++;
	}
	if (j % 2 == 0)
		k *= -1;
	return (-k);
}
/* 
int main (void)
{
	char	*str = "   ---+--+1234ab567";
	
	printf("my script:%d.\n", ft_atoi(str));
	return (0);	
} */