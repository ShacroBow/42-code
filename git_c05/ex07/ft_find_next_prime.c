/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:06:58 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/06/26 15:07:01 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int		n;
	int		b;

	if (nb <= 0 || nb == 1)
		nb = 2;
	n = 2;
	while (n <= nb / 2)
	{
		b = nb / n;
		if (n * b == nb)
			return (ft_find_next_prime(nb + 1));
		n++;
	}
	return (nb);
}
/*
 #include <stdio.h>

int main ()
{
	int i = -5;
    while (i <= 100)
    {
        printf("the number%3d next prime is: %2d\n", i, ft_find_next_prime(i));
        i++;
    }
	return 0;
} */