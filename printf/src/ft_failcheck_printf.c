/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_failcheck_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:45:19 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/10/03 19:48:00 by kmashkoo         ###   ########.fr       */
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
