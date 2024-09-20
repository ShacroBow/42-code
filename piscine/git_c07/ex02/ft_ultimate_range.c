/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:41:23 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/06/27 18:41:49 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*tab;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	tab = (int *)malloc(sizeof(*tab) * (max - min));
	if (tab == 0)
		return (-1);
	i = 0;
	while (min < max)
	{
		tab[i] = min;
		i++;
		min++;
	}
	*range = tab;
	return (i);
}

/* 
#include <stdio.h>
#include <string.h>

int main()
{
	int one_int = 5;
	int two_int = 10;
	int *result;
	int size;

	size = ft_ultimate_range(&result, one_int, two_int);
	if (size > 0)
	{
		printf("range: ");
		for (int i = 0; i < size; i++)
		{
			printf("%d ", result[i]);
		}
		printf("\nsize:%d\n", size);
		free(result);
	}
	else
	{
		printf("Invalid range:%ls", result);
		free(result);
	}

	return 0;
} */
