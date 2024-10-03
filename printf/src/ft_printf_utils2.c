/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:26:43 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/10/03 19:49:47 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_itohex_low(unsigned int x)
{
	char			*ptr;
	int				len;

	ptr = ft_itohex(x);
	if (!ptr)
		return (0);
	len = ft_strlen(ptr);
	write(1, ptr, len);
	free(ptr);
	return (len);
}

int	ft_itohex_cap(unsigned int x)
{
	char			*ptr;
	int				len;
	int				i;

	i = 0;
	ptr = ft_itohex(x);
	len = ft_strlen(ptr);
	if (!ptr)
		return (0);
	while (ptr[i])
	{
		ptr[i] = ft_toupper(ptr[i]);
		i++;
	}
	write(1, ptr, len);
	free(ptr);
	return (len);
}

int	ft_itohex_point(unsigned long int x)
{
	char	*ptr;
	int		count;

	ptr = NULL;
	count = 0;
	if (!x)
	{
		return (2 + ft_failcheck_printf(1));
	}
	ptr = ft_itohex(x);
	if (!ptr)
		return (2 + ft_failcheck_printf(1));
	count += ft_putstring("0x");
	count += ft_putstring(ptr);
	free(ptr);
	return (count);
}
