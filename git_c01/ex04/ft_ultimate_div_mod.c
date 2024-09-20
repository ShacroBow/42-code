/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:31:58 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/06/10 12:32:00 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}
/* 
int main() 
{
    int a = 10;
    int b = 3;
    int *divresult, *modresult;
    
    divresult = &a;
    modresult = &b;

    ft_ultimate_div_mod(divresult, modresult);

    printf("Division result: %d\n", *divresult);
    printf("Modulus result: %d\n", *modresult);

    return 0;
} */
