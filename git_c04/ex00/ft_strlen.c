/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:18:29 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/06/25 11:54:07 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		i++;
	}
	return (i);
}
/* int main()
{
	char *str1 = "Hello, world!";
	char *str2 = "";

	printf("Length of '%s' is %d\n", str1, ft_strlen(str1));
	printf("Length of '%s' is %d\n", str2, ft_strlen(str2));
	return (0);
} */