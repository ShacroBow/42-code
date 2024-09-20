/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:23:59 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/09/19 19:43:08 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	ptr = (char *)s;
	i = 0;
	while (ptr[i] != '\0')
	{
		i++;
		if (ptr[i] == c)
		{
			return (ptr + i);
		}
	}
	return (0);
}
/* 
#include <string.h>
#include <stdio.h>

int main() 
{
	char str[50] = "Hello, world! This is Helo a test.";
	char *result;

	result = ft_strchr(str, '4');
	printf("1my script       %s\n", result);

	result = ft_strchr(str, 'H');
	printf("2my script       %s\n", result);

	result = ft_strchr(str, '.');
	printf("3my script       %s\n", result);
 
	result = ft_strchr(str, 'T');
	printf("4my script       %s\n", result);

	result = ft_strchr(str, 'w');
	printf("5my script       %s\n", result);

	result = ft_strchr(str, '!');
	printf("6my script       %s\n\n", result);

	result = strchr(str, '4');
	printf("1original script %s\n", result);
	
	result = strchr(str, 'H');
	printf("2original script %s\n", result);
	
	result = strchr(str, '.');
	printf("3original script %s\n", result);

	result = strchr(str, 'T');
	printf("4original script %s\n", result);

	result = strchr(str, 'w');
	printf("5original script %s\n", result);
	
	result = strchr(str, '!');
	printf("6original script %s\n", result);
	return 0;
} */