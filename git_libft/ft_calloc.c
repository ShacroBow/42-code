/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:01:24 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/09/19 12:05:31 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	*ft_memset_calloc(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i != n)
	{
		ptr[i] = c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	sizecheck;
	void	*ptr;

	if (!nmemb || !size)
		return (0);
	sizecheck = nmemb * size;
	if ((sizecheck / size) != nmemb)
		return (0);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (0);
	ptr = ft_memset_calloc(ptr, '\0', nmemb * size);
	return (ptr);
}
/*#include <stdio.h>

void ft_printarray(int *array, int amount)
{
	for (int i = 0; i < amount; i++)
	{
		printf("%d ", array[i]);
	}
}

int main() {
	int amount = 30;
	int *array;

	array = (int *)ft_calloc(amount, sizeof(int));
	if (!array)
	{ 
		printf("fail:\n");
		return 0;
	}
	printf("My script array values:\n");
	ft_printarray(array, amount);
	printf("\n");
	free(array);

	array = (int *)calloc(amount, sizeof(int));
	if (!array)
	{
		printf("fail:\n");
		return 0;
	}
	printf("Original script array values:\n");
	ft_printarray(array, amount);
	printf("\n");
	free(array);

	return 0; 
} */