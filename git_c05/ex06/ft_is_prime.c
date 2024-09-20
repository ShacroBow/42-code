/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:59:40 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/06/26 15:04:19 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int		n;
	int		b;

	if (nb <= 0 || nb == 1 || nb == 4)
		return (0);
	n = 2;
	while (n < nb / 2)
	{
		b = nb / n;
		if (n * b == nb)
			return (0);
		n++;
	}
	return (1);
}
/* 
#include <stdio.h>

int main ()
{
	int i = -5;
	while (i <= 100)
	{
		printf("the number%3d is prime: %2d\n", i, ft_is_prime(i));
		i++;
	}
	return 0;
} */