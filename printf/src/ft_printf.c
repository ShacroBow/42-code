/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:25:51 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/09/30 14:57:26 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_printf_textread3(const char *string, va_list args)
{
	int	count;

	count = 0;
	if (*string == 'x')
	{
		count += ft_itohex_va(args, 0);
	}
	else if (*string == 'X')
	{
		count += ft_itohex_va(args, 0);
	}
	else if (*string == 'p')
	{
		count += ft_itohex_va(args, 0);
	}
	return (count);
}

static int	ft_printf_textread2(const char *string, va_list args)
{
	int		count;

	count = 0;
	if (*string == 'd')
	{
		count += ft_itoa_va(args);
	}
	else if (*string == 'i')
	{
		count += ft_itoa_va(args);
	}
	else if (*string == 'u')
	{
		count += ft_itoa_unsigned_va(args);
	}
	return (count);
}

static int	ft_printf_textread1(const char *string, va_list args)
{
	int	count;

	count = 0;
	if (*string == 'c')
	{
		count += ft_putchar_va(args);
	}
	else if (*string == 's')
	{
		count += ft_putstring_va(args);
	}
	else if (*string == '%')
	{
		write(1, (void *) '%', 1);
		count += 1;
	}
	return (count);
}

static int	ft_printf_textread(const char *string, va_list args)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			if (string[i] == 'c' || string[i] == 's' || string[i] == '%')
				count += ft_printf_textread1(string + i, args);
			if (string[i] == 'd' || string[i] == 'i' || string[i] == 'u')
				count += ft_printf_textread2(string + i, args);
			if (string[i] == 'x' || string[i] == 'X' || string[i] == 'p')
				count += ft_printf_textread3(string + i, args);
		}
		write(1, (string + i), 1);
		i++;
		count++;
	}
	return (count);
}

int	ft_printf(const char *string, ...)
{
	int		count;
	va_list	args;

	va_start(args, string);
	count = ft_printf_textread(string, args);
	va_end(args);
	return (count);
}
