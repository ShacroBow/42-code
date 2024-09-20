/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:09:18 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/06/27 18:52:01 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <bsd/string.h>

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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_dst;
	unsigned int	len_src;
	unsigned int	rem;
	unsigned int	i;

	len_dst = ft_strlen(dest);
	len_src = ft_strlen(src);
	rem = 0;
	i = 0;
	if (size > len_dst)
		rem = len_src + len_dst;
	else
		rem = len_src + size;
	while (src[i] && (len_dst + 1) < size)
	{
		dest[len_dst] = src[i];
		len_dst++;
		i++;
	}
	dest[len_dst] = '\0';
	return (rem);
}

int	main(void)
{
	char dest[50] = "Hello, ";
	char src[] = "world!";
	
	char dest2[50] = "Hello, ";
	char src2[] = "world!";
	// unsigned int size = 20;
	
	printf("Resulting length: %u\n", ft_strlcat(dest, src, 4));
	printf("my script: %s\n", dest);

	printf("2Resulting length: %lu\n", strlcat(dest2, src2, 4));
	printf("2original script: %s\n", dest);
	return 0;
}