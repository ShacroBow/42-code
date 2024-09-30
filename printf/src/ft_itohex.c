/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:26:28 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/09/30 14:55:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen(size_t n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static int	ft_itohexcalc(size_t n, char *ptr, char *refrence, int *j)
{
	int	i;

	i = 0;
	if (n > 0)
	{
		i = n % 16;
		n = n / 16;
		ptr[*j] = refrence[i];
	}
	else if (n <= 16)
	{
		i = n % 16;
		ptr[*j] = refrence[i];
	}
	return (n);
}

char	*ft_itohex(size_t n)
{
	char	*refrence;
	char	*ptr;
	int		j;

	j = ft_intlen(n);
	ptr = ft_calloc(j + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[j--] = '\0';
	refrence = "0123456789abcdef";
	if (n == 0)
	{
		ft_itohexcalc(n, ptr, refrence, &j);
	}
	while (j >= 0)
	{
		n = ft_itohexcalc(n, ptr, refrence, &j);
		j--;
	}
	return (ptr);
}
/* 
#include <stdio.h>

int main(void)
{
	size_t test_values[] = {0, 1, 16, 15, 241, 255, \
	 65535, 1048575, 4294967295};
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

	return 0;
} */