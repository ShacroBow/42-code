/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:33:32 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/10/03 19:50:18 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	int count = 0;
	ft_printf("\nhey myprint %%d:%d %%%%: %%,%%: %%X:%X \n", 1, 1225);
	printf("\nhey ogprint %%d:%d %%%%: %%,%% %%X:%X \n", 1, 1225);
	printf("\n---MY PRINTF---\n");
	ft_printf("char %c\n", '5');
	ft_printf("string %s\n", "hey");
	ft_printf("pointer in hex %p\n", (void *)ULONG_MAX);
	ft_printf("decimal %d\n", INT_MIN);
	ft_printf("int %i\n", INT_MIN);
	ft_printf("unsigned %u\n", UINT_MAX);
	ft_printf("hex %x\n", ULONG_MAX);
	ft_printf("HEX %X\n", 1255);
	ft_printf("precentage %%\n");
	printf("\n---ORIGINAL PRINTF---\n");
	printf("char %c\n", '5');
	printf("string %s\n", "hey");
	printf("pointer in hex %p\n", (void *)ULONG_MAX);
	printf("decimal %d\n", INT_MIN);
	printf("int %i\n", INT_MIN);
	printf("unsigned %u\n", UINT_MAX);
	printf("hex %x\n", UINT_MAX);
	printf("HEX %X\n", 1255);
	printf("precentage %%\n");
	
	printf("\n-----null checking.------\n");
	
	count = ft_printf("myprint:p %p\n",NULL);
	ft_printf("count:p %d\n", count);
	count = printf("Ogprint:p %p\n",NULL);
	printf("count:P %d\n\n", count);
	
	char *s1 = " HEYOOO";
	count = ft_printf("myprint:p %p\n", s1);
	ft_printf("count:p %d\n", count);
	count = printf("Ogprint:p %p\n", s1);
	printf("count:P %d\n\n", count);
	count = printf("Ogprint:p %p\n", s1);
	printf("count:P %d\n\n", count);

	count = ft_printf("myprint:d %d\n",'\0');
	ft_printf("count:d %d\n", count);
	count = printf("Ogprint:d %d\n",'\0');
	printf("count:d %d\n\n", count);
	
	char *ptr = NULL;
	count = ft_printf("myprint:s %s\n", ptr);
	ft_printf("count:s %d\n", count);
	count = printf("Ogprint:s %s\n", ptr);
	printf("count:s %d\n\n", count);
	
	printf("\n-----francinette checking.------\n");
	int temp;
	printf("\n");
	temp = ft_printf("%c\n", '0');
	printf("\n");
	printf("%d\n", temp);

	printf("\n");
	temp = printf("%c\n", '0');
	printf("\n");
	printf("%d\n", temp);
	printf("\n");

	ft_printf("wow:%c\n", '0' - 256);
	printf("wow:%c\n", '0' - 256);


	// printf("\n");
	// ft_printf("%s", "");
	printf("\n");	
	printf(" %s", "");
	printf("\n");
	
	printf("\n-----Odd testing.------\n");
	char *s2 = "hey buddy";
	printf("\n");
	ft_printf(" %s %s %s %s %s", " - ", "", "4", "", s2);
	printf("\n");
	ft_printf(" %s %s %s %s %s", " - ", "", "4", "", s2);
	printf("\n");
	ft_printf(" %s %s %s %s %s", " - ", "", "4", "", s2);
	printf("\n");
	printf(" %s %s %s %s %s", " - ", "", "4", "", s2);
	printf("\n");
	
	
	
	temp = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf("\n%d\n", temp);
	temp = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);

	printf("\n%d\n", temp);
	
}
/* 
write all the code as a in paramater va_arg
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