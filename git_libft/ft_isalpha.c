/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:16:03 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/09/11 19:05:43 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1024);
	}
	else
		return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{

	printf("yay %i\n", isalpha('b'));
	printf("yay %i", ft_isalpha('b'));
	return (0);
} */