/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:33:04 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/09/10 13:28:49 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int	digit;

	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		ft_putnbr(nb);
	}
	else
	{
		if (nb > 9)
		{
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
		else
		{
			digit = nb + 48;
			write(1, &digit, 1);
		}
	}
}
/* int	main(void)
{
	ft_putnbr(10);
	write(1, "\n", 1);
	ft_putnbr(-5);
	write(1, "\n", 1);
	ft_putnbr(7054);
	write(1, "\n", 1);
	ft_putnbr(-50341);
	write(1, "\n", 1);
	ft_putnbr(2147483647);
	write(1, "\n", 1);
	ft_putnbr(-2147483648);
	write(1, "\n", 1);
	write(1, "\n", 1);
	return (0);
} */