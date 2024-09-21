/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:13:07 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/06/12 17:21:59 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/* 
int main() 
{
    int a = 10;
    int b = 3;
    int divresult, modresult;

    ft_div_mod(a, b, &divresult, &modresult);

    printf("Division result: %d\n", divresult);
    printf("Modulus result: %d\n", modresult);

    return 0;
} */