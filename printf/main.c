/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:33:32 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/09/30 15:53:24 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "libftprintf.h"
#include <limits.h>

int	main(void)
{
	ft_printf("hey og %%d:%d %%%%: %%,%% f: \n", 1);
	printf("hey og %%d:%d %%%%: %%,%% X: \n", 1);
	printf("\n---MY PRINTF---\n");
	ft_printf("char %c\n", '5');
	ft_printf("string %s\n", "hey");
	ft_printf("pointer in hex %p\n", (void *)1255);
	ft_printf("decimal %d\n", INT_MAX);
	ft_printf("int %i\n", INT_MAX);
	ft_printf("unsigned %u\n", UINT_MAX);
	ft_printf("hex %x\n", 1255);
	ft_printf("HEX %X\n", 1255);
	ft_printf("precentage %%\n");
	printf("\n---ORIGINAL PRINTF---\n");
	printf("char %c\n", '5');
	printf("string %s\n", "hey");
	printf("pointer in hex %p\n", (void *)1255);
	printf("decimal %d\n", INT_MAX);
	printf("int %i\n", INT_MAX);
	printf("unsigned %u\n", UINT_MAX);
	printf("hex %x\n", 1255);
	printf("HEX %X\n", 1255);
	printf("precentage %%\n");
}
/* 
	max(3, 14,42,15,24);

int max(int ap, ...);
int ft_printf(const char *ap, ...);
int ft_printf(const char *ap, ... )
{
	va_list	args;
	double		x;
	int		i;

	va_start(args, ap);
	for (i = 0; i < strlen(ap) ; i++)
	{
		if (ap[i] == '%' && ap[i + 1] == 'd')
		{
			x = va_arg(args, int);
			printf("%d", x);
			i += 2;
		}
		else if (ap[i] == '%' && ap[i + 1] == 'i')
		{
			x = va_arg(args, int);
			printf("%d", x);
			i += 2;
		}
		else if (ap[i] == '%' && ap[i + 1] == 'f')
		{
			x = va_arg(args, double);
			printf("%f", x);
			i += 2;
		}
		else if (ap[i] == '%' && ap[i + 1] == 'u')
		{
			x = va_arg(args, unsigned int);
			printf("%u", x);
			i += 2;
		}
		else if (ap[i] == '%' && ap[i + 1] == '%')
		{
			printf("%c", ap[i]);
			i += 2;
		}
		printf("%c", ap[i]);
		
	}
	va_end(args);
	return i;
} */
// int max(int ap, ...)
// {
// 	va_list args;
// 	int x;
// 	int max;

// 	va_start(args, ap);
// 	for(int i = 0; i<ap;i++)
// 	{
// 		x = va_arg(args, int);
// 		if(i== 0)
// 			max = x;
// 		else if (x > max)
// 			max = x;
// 		printf("argc:%d", i);
// 		printf(" =  x:%d\n", x);
// 	}
// 	printf("\nmax: %d\n", max);
// 	va_end(args);
// 	return (0);
// }