/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:25:54 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/09/30 14:46:57 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar_va(va_list args)
{
	char	x;

	x = (char )va_arg(args, int);
	write(1, &x, 1);
	return (1);
}

int	ft_putstring_va(va_list args)
{
	char	*x;
	int		len;

	x = va_arg(args, char *);
	len = ft_strlen(x);
	write(1, &x, len);
	return (len);
}

int	ft_itoa_va(va_list args)
{
	int		x;
	char	*ptr;
	int		len;

	x = va_arg(args, int);
	ptr = ft_itoa(x);
	len = ft_strlen(ptr);
	if (!ptr)
	{
		return (-1);
	}
	write(1, ptr, len);
	free(ptr);
	return (len);
}

int	ft_itoa_unsigned_va(va_list args)
{
	unsigned int	x;
	char			*ptr;
	int				len;

	x = va_arg(args, unsigned int);
	ptr = ft_itoa_unsigned(x);
	len = ft_strlen(ptr);
	if (!ptr)
	{
		return (-1);
	}
	write(1, ptr, len);
	free(ptr);
	return (len);
}

int	ft_itohex_va(va_list args, int k)
{
	unsigned int	x;
	char			*ptr;
	int				len;
	int				i;

	i = 0;
	x = va_arg(args, size_t);
	ptr = ft_itohex(x);
	len = ft_strlen(ptr);
	if (!ptr)
	{
		return (-1);
	}
	while (k == 1 && ptr[i])
	{
		ptr[i] = ft_toupper(ptr[i]);
		i++;
	}
	write(1, ptr, len);
	free(ptr);
	return (len);
}
