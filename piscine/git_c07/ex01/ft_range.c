/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:41:14 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/06/27 18:47:56 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max)
		return (0);
	tab = (int *)malloc(sizeof(*tab) * (max - min));
	if (tab == 0)
		return (tab);
	i = 0;
	while (min < max)
	{
		tab[i] = min;
		i++;
		min++;
	}
	return (tab);
}
/* 
#include <stdio.h>
#include <string.h>

	int main() 
	{
		int one_int = 5;
		int two_int = 10;
		int *result;

		result = ft_range(one_int, two_int);
		if (result != 0)
		{
			printf("range: ");
			for (int i = 0; i < two_int - one_int; i++)
			{
				printf("%d ", result[i]);
			}
			printf("\n");
			free(result);
		}

		return 0;
	}
 */