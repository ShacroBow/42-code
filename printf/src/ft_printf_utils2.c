/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:26:43 by codespace         #+#    #+#             */
/*   Updated: 2024/10/01 15:10:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_itohex_va(va_list args)
{
	unsigned int	x;
	char			*ptr;
	int				len;

	x = va_arg(args, size_t);
	ptr = ft_itohex(x);
	len = ft_strlen(ptr);
	if (!ptr)
		return (0);
	write(1, ptr, len);
	free(ptr);
	return (len);
}

int	ft_itohex_cap_va(va_list args)
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

int	ft_itohex_point_va(va_list args)
{
	void			*x;
	char			*ptr;
	int				len;

	x = va_arg(args, void *);
	if (!x)
	{
		return (ft_failcheck_printf(1));
	}
	ptr = ft_itohex((unsigned long int)x);
	if (!ptr)
		return (ft_failcheck_printf(1));
	len = ft_strlen(ptr);
	write(1, "0x", 2);
	write(1, ptr, len);
	free(ptr);
	return (len + 2);
}
