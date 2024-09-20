/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:41:42 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/06/26 17:34:17 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 1 || nb == 0)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}
/* #include <stdio.h>

int	main(void)
{
	int i = 0;
	int result = 1;
	while (result > 0 && i <= 12)
	{
		result = ft_recursive_factorial(i);
		printf("factor is %9d, from i:%9d\n", result, i);
		i++;
	}
	printf("factor is %d\n", ft_recursive_factorial(-11));

	return (0);
} */
