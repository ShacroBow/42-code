/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radixposition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 22:14:20 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/02/12 17:25:16 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_radixposition_helper(int *sorted, int *buf, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (buf[i] == sorted[j])
			{
				buf[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

int	*ft_radixposition(int *buf, int len)
{
	int	*sorted;
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	if (buf == NULL || len <= 0)
		return (NULL);
	sorted = NULL;
	sorted = ft_calloc(len, sizeof(int));
	if (!sorted)
		ft_exiterror(buf);
	while (i < len)
	{
		tmp = buf[i];
		sorted[i] = tmp;
		i++;
	}
	ft_quicksort(sorted, len);
	ft_radixposition_helper(sorted, buf, i);
	free(sorted);
	return (buf);
}
/* 
#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int array[12] = {12, 5, 6, 3, -1344, -44, 700, 1000, -125, 0};
	int size = 10;
	for (int i = 0; i < size; i++)
	{
		printf("[%3d] ", array[i]);
	}
	printf("\n");

	int* positions = ft_radixposition(array, size);
	for (int i = 0; i < size; i++)
	{
		printf("[%3d] ", array[i]);
	}
	printf("\n");
	if (positions != NULL) {
		for (int i = 0; i < size; i++) {
			printf("%2d ", positions[i]);
		}
		printf("\n");
	} else {
		printf("Memory allocation failed.\n");
	}

	return 0;
}
 */
