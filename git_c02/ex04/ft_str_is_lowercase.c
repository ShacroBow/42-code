/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:56:04 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/06/20 14:25:24 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 97 && str[i] <= 122))
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
	char str[] = "AS56sDS";
	char dest[] = "fasdasw";
	printf("%i\n", ft_str_is_lowercase(str));
	printf("%i", ft_str_is_lowercase(dest));
}  */