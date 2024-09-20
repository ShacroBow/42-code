/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:57:52 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/06/26 11:57:05 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (0);
	else if (index <= 2)
		return (1);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
/* 
#include <stdio.h>

int main() {
	int num = 0;

	while (num <= 10)
	{
		printf("Fibonacci sequence for %2d is: %2d\n", num, ft_fibonacci(num));
		num++;
	}
	return 0;
} */
