/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:44:55 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/06/26 20:56:57 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	swap(int *arr, int i, int j);

void	ft_sort_int_tab(int *tab, int size)
{
	int	i_start;
	int	i_end;
	int	carry;

	i_end = 0;
	i_start = 0;
	while (i_start != size - 1)
	{
		while (i_end != size - 1)
		{
			if (tab[i_end] > tab[i_end + 1])
				swap(tab, i_end, i_end + 1);
			i_end++;
		}
		i_end = 0;
		i_start++;
	}
}

void	swap(int *arr, int i, int j)
{
	int	temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main() 
{
    int hel[6]={9,6,10,8,5,7};
    printArray(hel,6);
	ft_sort_int_tab	(hel,6);
	printArray(hel,6);
    return 0;
}
