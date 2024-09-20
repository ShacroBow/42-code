/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:41:25 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/06/27 18:48:46 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strdup(char *s1)
{
	char			*str;
	unsigned int	i;

	if (!s1)
		return (0);
	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!str)
		return (0);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
/* 
#include <stdio.h>
#include <string.h>

int main() {
	char *one_string = "Hello, World!";
	char *one_stringcpy = ft_strdup(one_string);

	char *two_string = "Hello, World!";
	char *two_stringcpy = strdup(two_string);


	if (one_stringcpy == 0 || two_stringcpy == 0) 
	{
		printf("Memory allocation failed.\n");
		return 1;
	}

	printf("Original String: %s\n", one_string);
	printf("Duplicated String: %s\n\n", one_stringcpy);

	printf("OG Original String: %s\n", one_string);
	printf("OG Duplicated String: %s\n\n", one_stringcpy);

	free(one_stringcpy);
	free(two_stringcpy);
	return 0;
}
 */