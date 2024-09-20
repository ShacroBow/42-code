/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:40:04 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/06/26 17:34:20 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	while (0 < nb)
	{
		result = nb * result;
		nb--;
	}
	return (result);
}
/* #include <stdio.h>

int	main(void)
{
	int i = 0;
	int result = 1;
	while (result > 0 && i <= 12)
	{
		result = ft_iterative_factorial(i);
		printf("factor is %9d, from i:%9d\n", result, i);
		i++;
	}
	printf("factor is %d\n", ft_iterative_factorial(5));

	return (0);
} */
