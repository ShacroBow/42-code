/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:26:28 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/11/13 14:01:52 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_sizecorrection(char *ptr)
{
	char	*temp;

	temp = ft_strdup(ptr);
	free(ptr);
	return (temp);
}

static void	ft_revstr(char *str, unsigned int size)
{
	int		i_start;
	int		i_end;
	char	carry;

	i_start = 0;
	i_end = size - 1;
	while (i_start < i_end)
	{
		carry = str[i_start];
		str[i_start] = str[i_end];
		str[i_end] = carry;
		i_start++;
		i_end--;
	}
}

static char	*ft_itohexcalc(char *ptr)
{
	ptr = ft_sizecorrection(ptr);
	ft_revstr(ptr, ft_strlen(ptr));
	return (ptr);
}

char	*ft_itohex(size_t n)
{
	char	*refrence;
	char	*ptr;
	int		j;
	int		i;

	j = 0;
	i = 0;
	ptr = ft_calloc(20 + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	refrence = "0123456789abcdef";
	if (n == 0)
		ptr[0] = refrence[0];
	while (n > 0)
	{
		i = n % 16;
		n = n / 16;
		ptr[j] = refrence[i];
		j++;
	}
	return (ft_itohexcalc(ptr));
}
/* 
#include <stdio.h>
#include <limits.h>

int main(void)
{
	size_t test_values[] = {0, 1, 16, 15, 241, 255, \
	 65535, ULONG_MAX, ULLONG_MAX};
	size_t num_tests = sizeof(test_values) / sizeof(test_values[0]);
	char *hex_string;

	for (size_t i = 0; i < num_tests; i++)
	{
		hex_string = ft_itohex(test_values[i]);
		if (hex_string)
		{
			printf("Decimal: %10zu -> Hexadecimal: %s\n"\
			, test_values[i], hex_string);
			free(hex_string);
		}
		else
		{
			printf("Failed to convert %zu to hexadecimal.\n", test_values[i]);
		}
	}
	printf("\n");
	char *ptr;
	char *test = "heyogfdgfdg";

	ptr = ft_itohex((unsigned long)test);
	if (!ptr)
		return (ft_failcheck_printf(1));
	ft_putstring("0x");
	ft_putstring(ptr);
	free(ptr);
	printf("\n");
	ft_printf("%p\n", test);
	printf("%p\n", test);
	return 0;
} */