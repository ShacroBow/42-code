/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:25:51 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/09/30 16:09:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		write(1, "0x", 2);
		count += 2 + ft_itohex_va(args, 0);
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
	else if (*string == '%' && *(string - 1) == '%')
	{
		write(1, "%", 1);
		count += 1;
	}
	return (count);
}

static int	ft_printf_textread(const char *string, va_list args, int *i)
{
	int	count;

	count = 0;
	if (string[*i] == '%')
	{
		*i = 1 + *i;
		if (string[*i] == 'c' || string[*i] == 's' || (string[*i] == '%'))
			count += ft_printf_textread1(string + *i, args);
		else if (string[*i] == 'd' || string[*i] == 'i' || string[*i] == 'u')
			count += ft_printf_textread2(string + *i, args);
		else if (string[*i] == 'x' || string[*i] == 'X' || string[*i] == 'p')
			count += ft_printf_textread3(string + *i, args);
		*i = 1 + *i;
	}
	if (string[*i] != '%')
	{
		write(1, (string + *i), 1);
		*i = 1 + *i;
		count++;
	}
	return (count);
}

int	ft_printf(const char *string, ...)
{
	int		count;
	va_list	args;
	int		i;

	va_start(args, string);
	i = 0;
	count = 0;
	while (string[i] != '\0')
		count += ft_printf_textread(string, args, &i);
	va_end(args);
	return (count);
}
