/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:39:42 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/06/26 11:22:51 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (*(dest + i))
	{
		i++;
	}
	while (j < nb && src[j] != '\0')
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
	char str1[20] = "funny:";
	char str2[6] = "HAHA";
	
	printf("The strings is:%s.\n", str1);
	
	printf("The strings is:%s.\n", ft_strncat(str1, str2, 2));
	
	printf("The strings is:%s.\n", strncat(str1, str2, 2));

	return 0;
} */