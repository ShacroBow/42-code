/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:25:51 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/11/15 19:32:27 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_production(const char *string, va_list args, int *i)
{
	int	count;

	count = 0;
	if (string[*i] == 'c')
		count += ft_putchar((char)va_arg(args, int));
	else if (string[*i] == 's')
		count += ft_putstring(va_arg(args, char *));
	else if (string[*i] == '%')
		count += ft_putchar('%');
	else if (string[*i] == 'd')
		count += ft_itoa_signed(va_arg(args, int));
	else if (string[*i] == 'i')
		count += ft_itoa_signed(va_arg(args, int));
	else if (string[*i] == 'u')
		count += ft_uitoa_unsigned(va_arg(args, unsigned int));
	else if (string[*i] == 'x')
		count += ft_itohex_low(va_arg(args, unsigned int));
	else if (string[*i] == 'X')
		count += ft_itohex_cap(va_arg(args, unsigned int));
	else if (string[*i] == 'p')
		count += ft_itohex_point((unsigned long int)va_arg(args, void *));
	return (count);
}

int	ft_printf(const char *string, ...)
{
	int		count;
	va_list	args;
	int		i;

	if (!string)
		return (-1);
	va_start(args, string);
	i = 0;
	count = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			count += ft_printf_production(string, args, &i);
		}
		else
			count += ft_putchar(string[i]);
		i++;
	}
	va_end(args);
	return (count);
}
