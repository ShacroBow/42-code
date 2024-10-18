/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:31:21 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/10/14 17:14:17 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr_getnxtlin(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	if (s == NULL)
		return (-1);
	while (ptr[i] != '\0')
	{
		if (ptr[i] == (unsigned char)c)
			return (i);
		i++;
	}
	if ((unsigned char)c == '\0')
		return (i);
	return (-1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	str_len;
	char	*ptr;

	if (!s)
		return (NULL);
	str_len = 0;
	while (s[str_len] != '\0')
		str_len++;
	if (start >= str_len)
		return (ft_calloc(1, 1));
	if (len > str_len - start)
		len = str_len - start;
	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	i;

	len_src = 0;
	while (src[len_src] != '\0')
		len_src++;
	if (size == 0)
		return (len_src);
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (len_src);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	str = (char *)ft_calloc(j + i + 1, sizeof(char));
	j = -1;
	i = -1;
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i + j] = s2[j];
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	size_t			sizecheck;
	unsigned char	*ptr;

	i = 0;
	sizecheck = nmemb * size;
	if (sizecheck != 0 && sizecheck / nmemb != size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (i != sizecheck)
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}
