/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:20:27 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/06/12 14:09:29 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i_start;
	int	i_end;
	int	carry;

	i_end = size - 1;
	i_start = 0;
	while (i_start < i_end)
	{
		carry = tab[i_start];
		tab[i_start] = tab[i_end];
		tab[i_end] = carry;
		i_start++;
		i_end--;
	}
}

int main() 
{
    int hel[6]={5,6,7,9,10};
    
	ft_rev_int_tab(hel,6);
	printf("%s", hel);
    return 0;
}
