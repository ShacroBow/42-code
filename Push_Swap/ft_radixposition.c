/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radixposition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 22:14:20 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/12/17 06:20:46 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_radixposition_helper(int *sorted, int *buf, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (sorted[i] == buf[j])
			{
				buf[j] = i;
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

	if (buf == NULL || len <= 0)
		return (NULL);
	sorted = (int *)ft_calloc(len, sizeof(int));
	if (!sorted)
		ft_exiterror(buf);
	i = 0;
	while (i < len)
	{
		sorted[i] = buf[i];
		i++;
	}
	ft_quicksort(sorted, len);
	ft_radixposition_helper(sorted, buf, len);
	free(sorted);
	return (buf);
}
/* #include <stdio.h>
#include <stdlib.h>
int main() {
	int array[5] = {12, 5, 6, 3, 13};
	int size = sizeof(array) / sizeof(array[0]);
	for (int i = 0; i < size; i++)
	{
		printf("%2d ", array[i]);
	}
	printf("\n");

	int* positions = ft_radixposition(array, size);
	if (positions != NULL) {
		for (int i = 0; i < size; i++) {
			printf("%2d ", positions[i]);
		}
		printf("\n");
	} else {
		printf("Memory allocation failed.\n");
	}

	return 0;
} */