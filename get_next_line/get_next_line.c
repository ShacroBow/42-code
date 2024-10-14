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

void	free_null(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		ptr = NULL;
	}
}

char	*join_line(int nl_position, char **buffer)
{
	char	*ptr;
	char	*tmp;

	tmp = NULL;
	if (nl_position <= 0 )
	{
		if (**buffer == '\0')
		{
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
		ptr = *buffer;
		*buffer = NULL;
		return (ptr);
	}
	tmp = ft_substr(*buffer, nl_position, BUFFER_SIZE);
	ptr = *buffer;
	ptr[nl_position] = 0;
	*buffer = tmp;
	return (ptr);
}

char	*read_line(int fd, char **buffer, char *readbuffer)
{
	size_t	readlen;
	int		nl_offset;
	char	*tmp;

	nl_offset = ft_strchr(buffer[fd], '\n');
	tmp = NULL;
	readlen = 0;
	while (nl_offset == -1)
	{
		readlen = read(fd, readbuffer, BUFFER_SIZE);
		if (readlen <= 0)
			return (join_line(readlen, &buffer[fd]));
		readbuffer[readlen] = '\0';
		tmp = ft_strjoin(buffer[fd], readbuffer);
		free_null(buffer);
		buffer[fd] = tmp;
		nl_offset = ft_strchr(buffer[fd], '\n');
	}
	return (join_line(nl_offset + 1, &buffer[fd]));
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
	ptr = read_line(fd, buffer, readbuffer);
	free_null(&readbuffer);
	return (ptr);
}