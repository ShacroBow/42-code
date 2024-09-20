/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:49:02 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/06/26 11:23:06 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}
/* int	main(void)
{
	char str1[] = "Hello";
	char str2[] = "Hell0";

	int result = ft_strcmp(str1, str2);
	
	printf("my strings is: %d.\n", result);
	
	int result2 = strcmp(str1, str2);
	printf("original strings is: %d.\n", result2);
	return 0;
} */