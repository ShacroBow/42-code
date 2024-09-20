/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:13:25 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/06/20 14:15:45 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 65 && str[i] <= 90))
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
	char str[] = "ABCDED";
	char dest[] = "AS56sDS";
	printf("%i\n", ft_str_is_uppercase(str));
	printf("%i", ft_str_is_uppercase(dest));
}  */