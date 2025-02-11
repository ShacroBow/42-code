/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radixposition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 22:14:20 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/02/11 19:47:09 by codespace        ###   ########.fr       */
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
				printf("sorted[i][%3d] = buf[j][%3d] -i[%d]-j[%d]\n", sorted[i], buf[j], i, j);
				break ;
			}
			printf("uniquesorted[i][%3d] = buf[j][%3d] -i[%d]-j[%d]\n", sorted[i], buf[j], i, j);
			j++;
		}
		i++;
	}
}

int	*ft_radixposition(int *buf, int len)
{
	int	*sorted;
	int	i;

	i = 0;
	if (buf == NULL || len <= 0)
		return (NULL);
	sorted = NULL;
	sorted = ft_calloc(len, sizeof(int));
	if (!sorted)
		// ft_exiterror(buf);
	
	printf("sorted[i][%3d] = buf[i][%3d] -i[%d]-len[%d]\n", sorted[i], buf[i], i, len);
	while (i < len)
	{
		int tmp = buf[i];
		sorted[i] = tmp;
		printf("sorted[i][%5d] = buf[i][%5d] -i[%d]\n", sorted[i], buf[i], i);
		i++;
	}
	ft_quicksort(sorted, len);
	for (int i = 0; i < len; i++)
		printf("[%3d] ", sorted[i]);
	printf("\n");
	ft_radixposition_helper(sorted, buf, i);
	for (int i = 0; i < len; i++)
		printf("[%3d] ", buf[i]);
	printf("\n");
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