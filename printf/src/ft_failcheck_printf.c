/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_failcheck_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:45:19 by codespace         #+#    #+#             */
/*   Updated: 2024/10/03 13:22:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_failcheck_printf(int k)
{
	if (k == 0)
	{
		write (1, "(null)", 6);
		return (6);
	}
	else if (k == 1)
	{
		write (1, "(nil)", 5);
		return (3);
	}
	return (0);
}
