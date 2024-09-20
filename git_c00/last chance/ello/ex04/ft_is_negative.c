/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:39:29 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/06/06 19:39:34 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	int	pos;
	int	neg;

	pos = 'P';
	neg = 'N';
	if (n >= 0)
	{
		write(1, &pos, 1);
	}
	else if (n < 0)
	{
		write(1, &neg, 1);
	}
}
/*  int main()
{
    ft_is_negative(-1);
	return 0;
}  */
