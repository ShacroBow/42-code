/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:01:32 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/09/11 19:07:21 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = (char *)dest;
	s = (const char *)src;
	i = 0;
	if (d < s)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	return (dest);
}
/* 
#include <stdio.h>
#include <string.h> 

int main() 
{ 
	char str[50] = "the magic number is fourty two"; 
	char *ptr;
	printf("\nBefore str memmove():  %s\n", str); 


	ptr = (char *)memmove(str+10, str+4, 40); 
	printf("After memmove():       %s\n", ptr);
	printf("plan string:           %s\n\n", str);

	ptr = (char *)ft_memmove(str+10, str+4, 40); 
	printf("After ft_memmove():    %s\n", ptr); 
	printf("plan string:           %s\n", str);
	return 0; 
} */
