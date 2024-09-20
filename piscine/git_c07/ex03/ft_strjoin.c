/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:41:34 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/06/27 18:49:27 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		*dest = src[i];
		i++;
		dest++;
	}
	return (dest);
}

int	return_length(int size, char **strs, int size_sep)
{
	int	i;
	int	len;

	i = 0;
	len = size_sep * -1;
	while (i < size)
	{
		len += size_sep + ft_strlen(strs[i]);
		i++;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*res;
	int		len;

	if (size == 0)
	{
		res = (char *)malloc(1);
		return (res);
	}
	len = return_length(size, strs, ft_strlen(sep));
	i = 0;
	res = malloc(sizeof(char) * (len + 1));
	if (res == 0)
		return (0);
	while (i < size)
	{
		res = ft_strcpy(res, strs[i]);
		if ((i + 1) < size)
			res = ft_strcpy(res, sep);
		i++;
	}
	*(res) = '\0';
	return (res - len);
}
/* 
#include <stdio.h>

int main()
{
	char *s1 = "Hello";
	char *s2 = "world!";
	char *s3 = "It is a";
	char *s4 = "new DAY!!";
	char *strs[] = {s1, s2, s3, s4};
	char *sep = "-->-<--";
	char *result = ft_strjoin(4, strs, sep);

	if (*result != '\0')
	{
		printf("Joined string:%s\n", result);
		free(result);
	}
	else
	{
		printf("Failed to join strings:%s\n", result);
		free(result); 
	}

	return 0;
} */
