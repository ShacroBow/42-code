/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:19:56 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/10/14 17:09:16 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free_null(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

static char	*ft_lefttrim(int nl_offset, char **buffer)
{
	char	*ptr;
	char	*tmp;

	tmp = NULL;
	if (nl_offset <= 0 )
	{
		if (**buffer == '\0')
		{
			free(*buffer);
			buffer = NULL;
			return (NULL);
		}
		ptr = *buffer;
		*buffer = NULL;
		return (ptr);
	}
	tmp = ft_substr(*buffer, nl_offset, BUFFER_SIZE);
	ptr = *buffer;
	ptr[nl_offset] = '\0';
	*buffer = tmp;
	return (ptr);
}

static char	*ft_nextline(int fd, char **buffer, char *readbuffer)
{
	size_t	readlen;
	int		nl_offset;
	char	*ptr;

	nl_offset = ft_strchr_getnxtlin(buffer[fd], '\n');
	ptr = NULL;
	readlen = 0;
	while (nl_offset == -1)
	{
		readlen = read(fd, readbuffer, BUFFER_SIZE);
		if (readlen <= 0)
			return (ft_lefttrim(readlen, &buffer[fd]));
		readbuffer[readlen] = '\0';
		ptr = ft_strjoin(buffer[fd], readbuffer);
		if (!ptr)
			return (NULL);
		free_null(&buffer[fd]);
		buffer[fd] = ptr;
		nl_offset = ft_strchr_getnxtlin(buffer[fd], '\n');
	}
	return (ft_lefttrim(nl_offset + 1, &buffer[fd]));
}

char	*get_next_line(int fd)
{
	static char	*buffer[FDBUFFER + 1] = {0};
	char		*readbuffer;
	char		*ptr;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FDBUFFER)
		return (NULL);
	if (buffer[fd] == NULL)
		buffer[fd] = ft_strdup("");
	readbuffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (readbuffer == NULL)
		return (NULL);
	ptr = ft_nextline(fd, buffer, readbuffer);
	free_null(&readbuffer);
	return (ptr);
}