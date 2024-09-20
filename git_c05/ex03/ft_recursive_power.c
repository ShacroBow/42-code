/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:03:53 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/06/26 11:55:11 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}
/* 
#include <stdio.h>

int	main(void)
{
	int i = 1;
	int power = 2;
	int	result = 0;

	while (power < 10)
	{
		printf("\nnow power:%d \n", power);
		while (i <= 5)
		{
			result = ft_recursive_power(i, power);
			printf("result is %7d, from input:%2d. from power:%2d\n"
				, result, i, power);
			i++;
		}
		i = 1;
		power++;
	}
	printf("power is %d\n", ft_recursive_power(50, 3));

	return (0);
} */