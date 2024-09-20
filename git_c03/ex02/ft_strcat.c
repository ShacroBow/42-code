/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:26:44 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/09/10 13:43:56 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/* int	main(void) 
{
	char str1[50] = "this is funny:";
	char str2[6] = "HAHA";

	char *results;
	char *results2;
	
	printf("The strings is:%s.\n", str1);
	
	printf("The strings is:%s.\n", ft_strcat(str1, str2));
	
	printf("The strings is:%s.\n", strcat(str1, str2));

	return 0;
} */