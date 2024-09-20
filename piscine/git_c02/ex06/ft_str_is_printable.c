/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:12:39 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/09/03 12:01:33 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 32 && str[i] <= 126))
		{
			i++;
		}
		else
			return (0);
	}
	return (1);
}

/* int	main(void)
{
	char str[] = "AS5''sDS";
	char dest[] = "AS\n56sDS";
	printf("%i\n", ft_str_is_printable(str));
	printf("%i", ft_str_is_printable(dest));
}  */