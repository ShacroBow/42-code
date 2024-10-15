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

static void	ft_nullit(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
}

static char	*ft_lefttrim(int readlen, t_fdstate **fdstate, int fd)
{
	char	*ptr;
	char	*tmp;

	tmp = NULL;
	if (readlen <= 0 )
	{
		if (fdstate[fd]->buf == NULL)
		{
			ft_nullit(fdstate[fd]->buf);
			ft_nullit(fdstate[fd]);
			return (NULL);
		}
		ptr = fdstate[fd]->buf;
		fdstate[fd]->buf = NULL;
		return (ptr);
	}
	tmp = ft_substr(fdstate[fd]->buf, readlen, BUFFER_SIZE);
	ptr = fdstate[fd]->buf;
	ptr[readlen] = '\0';
	fdstate[fd]->buf = tmp;
	return (ptr);
}

static char	*ft_nextline(int fd, t_fdstate **fdstate, char *readbuffer)
{
	size_t	readlen;
	char	*ptr;

	fdstate[fd]->nl_offset = ft_strchr_getnxtlin(fdstate[fd]->buf, '\n');
	ptr = NULL;
	readlen = 0;
	while (fdstate[fd]->nl_offset == (size_t)-1)
	{
		readlen = read(fd, readbuffer, BUFFER_SIZE);
		if (readlen == (size_t)EOF || readlen == 0)
			return (ft_lefttrim(readlen, fdstate, fd));
		readbuffer[readlen] = '\0';
		ptr = ft_strjoin(fdstate[fd]->buf, readbuffer);
		if (!ptr)
			return (NULL);
		ft_nullit(fdstate[fd]->buf);
		fdstate[fd]->buf = ptr;
		fdstate[fd]->nl_offset = ft_strchr_getnxtlin(fdstate[fd]->buf, '\n');
	}
	return (ft_lefttrim(fdstate[fd]->nl_offset + 1, fdstate, fd));
}

char	*get_next_line(int fd)
{
	static t_fdstate	*fdstate[FDBUFFER + 1] = {0};
	char				*readbuffer;
	char				*ptr;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FDBUFFER)
		return (NULL);
	if (fdstate[fd] == NULL)
	{
		fdstate[fd] = (t_fdstate *)ft_calloc(1, sizeof(t_fdstate));
		if (!fdstate[fd])
			return (NULL);
		fdstate[fd]->buf = (char *)ft_calloc(1, 1);
		if (!fdstate[fd]->buf)
			return (NULL);
		fdstate[fd]->nl_offset = 0;
	}
	readbuffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!readbuffer)
		return (NULL);
	ptr = ft_nextline(fd, fdstate, readbuffer);
	ft_nullit(readbuffer);
	return (ptr);
}