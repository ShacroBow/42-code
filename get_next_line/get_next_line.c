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

static char	*ft_error_return(int readlen, char **fdbuf, int fd,
							char **readbuffer)
{
	if (readlen == -1)
	{
		if (fdbuf[fd])
			free(fdbuf[fd]);
		if (*readbuffer != NULL)
			free(*readbuffer);
		fdbuf[fd] = NULL;
		*readbuffer = NULL;
		return (NULL);
	}
	if (readlen == 0 && fdbuf[fd] != NULL)
	{
		free(fdbuf[fd]);
		fdbuf[fd] = NULL;
		return (NULL);
	}
	return (NULL);
}

static char	*ft_lefttrim(size_t nl_offset, char **fdbuf, int fd,
						char **readbuffer)
{
	char	*ptr;
	char	*ptr2;

	ptr = ft_substr(fdbuf[fd], nl_offset, ft_strlen(fdbuf[fd]) - nl_offset);
	if (!ptr)
		return (ft_error_return(-1, fdbuf, fd, readbuffer));
	fdbuf[fd][nl_offset] = 0;
	ptr2 = fdbuf[fd];
	fdbuf[fd] = ptr;
	return (ptr2);
}

static char	*ft_stitch_to_nextline(char **fdbuf, int fd, char **readbuffer)
{
	int		i;
	char	*ptr;

	if (fdbuf[fd] == NULL)
	{
		fdbuf[fd] = ft_strjoin("", *readbuffer);
		if (!fdbuf[fd])
			return (ft_error_return(-1, fdbuf, fd, readbuffer));
	}
	else
	{
		ptr = ft_strjoin(fdbuf[fd], *readbuffer);
		free(fdbuf[fd]);
		fdbuf[fd] = ptr;
	}
	i = 0;
	ptr = *readbuffer;
	while (ptr[i] != '\0')
	{
		ptr[i] = '\0';
		i++;
	}
	return (fdbuf[fd]);
}

static char	*ft_nextline(int fd, char **fdbuf, char **readbuffer)
{
	int			readlen;
	char		*nl_offset;
	char		*ptr;

	nl_offset = ft_strchr(fdbuf[fd], '\n');
	while (nl_offset == NULL || fdbuf[fd] == NULL)
	{
		readlen = read(fd, *readbuffer, BUFFER_SIZE);
		if (readlen < 0)
			return (ft_error_return(readlen, fdbuf, fd, readbuffer));
		fdbuf[fd] = ft_stitch_to_nextline(fdbuf, fd, readbuffer);
		if (!fdbuf[fd])
			return (ft_error_return(-1, fdbuf, fd, readbuffer));
		nl_offset = ft_strchr(fdbuf[fd], '\n');
		if (nl_offset == NULL && readlen == 0)
		{
			if (fdbuf[fd] && fdbuf[fd][0] == '\0')
				return (ft_error_return(readlen, fdbuf, fd, readbuffer));
			ptr = ft_strjoin("", fdbuf[fd]);
			ft_error_return(0, fdbuf, fd, readbuffer);
			return (ptr);
		}
	}
	return (ft_lefttrim((nl_offset - fdbuf[fd]) + 1, fdbuf, fd, readbuffer));
}

char	*get_next_line(int fd)
{
	static char	*fdbuf[FDBUFFER] = {0};
	char		*readbuffer;
	char		*ptr;

	readbuffer = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FDBUFFER)
		return (ft_error_return(0, fdbuf, FDBUFFER, &readbuffer));
	readbuffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!readbuffer)
		return (ft_error_return(-1, fdbuf, fd, &readbuffer));
	ptr = ft_nextline(fd, fdbuf, &readbuffer);
	if (readbuffer)
	{
		free(readbuffer);
		readbuffer = NULL;
	}
	return (ptr);
}
