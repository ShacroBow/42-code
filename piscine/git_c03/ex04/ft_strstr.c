/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:05:12 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/06/26 16:11:54 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			++j;
		}
		++i;
	}
	return (0);
}
/* int main() {
	char str[] = "Hello, world! This is Helo a test.";
	char *result = ft_strstr(str, "world");
	printf("%s\n", result);

	result = ft_strstr(str, "world");
	printf("my script %s\n", result);

	result = ft_strstr(str, "Helo");
	printf("my script %s\n", result);

	result = ft_strstr(str, "HELLO");
	printf("my script %s\n", result);
< n)
	{
		dest[i] = '\0';
		i++;

	result = strstr(str, "world");
	printf("original script %s\n", result);

	result = strstr(str, "Helo");
	printf("original script %s\n", result);

	result = strstr(str, "HELLO");
	printf("original script %s\n", result);
	return 0;
} */