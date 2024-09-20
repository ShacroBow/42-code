/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:57:31 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/06/26 11:59:23 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i * i <= nb && i <= 46340)
	{
		if (i * i == nb)
			return (i);
		else
			i++;
	}
	return (0);
}

/* #include <stdio.h>

int main()
{
	int i = -5;
	while (i <= 100)
	{
		printf("Square root of %3d is: %2d\n", i, ft_sqrt(i));
		i++;
	}

    return 0;
} */
