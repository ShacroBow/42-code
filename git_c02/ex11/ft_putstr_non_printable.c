/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:57:38 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/06/20 15:12:49 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	hex_converter(int input);

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 32 && str[i] >= 0) || str[i] >= 127)
		{
			write(1, "\\", 1);
			if (str[i] < 16)
			{
				write(1, "0", 1);
				hex_converter(str[i]);
			}
			else
				hex_converter(str[i]);
		}
		else
			write(1, &str[i], 1);
		i += 1;
	}
}

void	hex_converter(int input)
{
	int			i;
	int			j;
	int			temp;
	char		hex_number[8];

	hex_number[0] = '\0';
	hex_number[1] = '\0';
	i = 0;
	while (input != 0)
	{
		temp = input % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 87;
		hex_number[i] = temp;
		i++;
		input = input / 16;
	}
	j = i;
	while (j >= 0)
	{
		write(1, &hex_number[j], 1);
		j--;
	}
}
/* int	main(void)
{
	// int Number = 806655;
	// hex_converter(Number);
	char	*s = "Coucou\ntu vas bien ?";
	ft_putstr_non_printable(s);
	return (0);
} */
