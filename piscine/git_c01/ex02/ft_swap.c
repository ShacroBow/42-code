/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:00:32 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/06/10 11:00:35 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}
/* int main()
{
    int x = 10;
    int y = 20;

    printf("Before swapping: x = %d, y = %d\n", x, y);

    ft_swap(&x, &y);

    printf("After swapping: x = %d, y = %d\n", x, y);

    return 0;
} */
