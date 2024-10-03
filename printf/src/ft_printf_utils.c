/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:25:54 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/10/03 19:49:25 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char x)
{
	write(1, &x, 1);
	return (1);
}

int	ft_putstring(char *x)
{
	int	count;

	count = 0;
	if (x == NULL)
		return (ft_failcheck_printf(0));
	while (x[count] != '\0')
	{
		count += ft_putchar(x[count]);
	}
	return (count);
}

int	ft_itoa_signed(int x)
{
	char	*ptr;
	int		count;

	count = 0;
	ptr = ft_itoa(x);
	if (!ptr)
		return (0);
	count += ft_putstring(ptr);
	free(ptr);
	return (count);
}

int	ft_uitoa_unsigned(unsigned int x)
{
	char			*ptr;
	int				count;

	count = 0;
	ptr = ft_uitoa(x);
	if (!ptr)
		return (0);
	count += ft_putstring(ptr);
	free(ptr);
	return (count);
}
