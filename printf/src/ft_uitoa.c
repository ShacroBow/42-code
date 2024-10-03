/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:25:57 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/10/03 16:56:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen_itoa(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		return (1);
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_revstr_itoa(char *str, unsigned int size)
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

static char	*ft_itoacalc_itoa(char *ptr, unsigned int n)
{
	int	digit;

	digit = 0;
	if (n == 0)
	{
		ptr[digit] = '0';
		digit++;
	}
	else
	{
		while (n > 0)
		{
			ptr[digit] = (n % 10) + '0';
			n /= 10;
			digit++;
		}
	}
	ptr[digit] = '\0';
	ft_revstr_itoa(ptr, digit);
	return (ptr);
}

char	*ft_uitoa(unsigned int n)
{
	int		numsize;
	char	*ptr;

	numsize = ft_intlen_itoa(n);
	ptr = (char *)ft_calloc(numsize + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	ptr = ft_itoacalc_itoa(ptr, n);
	return (ptr);
}
/* #include <stdio.h>
int main(void)
{
	unsigned int test_values[] = {0, 1, 123, 456789, 4294967295}; // Test cases

		char *result = ft_itoa_unsigned_va(test_values[4]);
		if (result)
		{
			printf("ft_itoa(%u) = %s\n", test_values[4], result);
			free(result);
		}
		else
		{
			printf("Memory allocation failed for ft_itoa(%u)\n", test_values[4]);
		}
	return 0;
} */