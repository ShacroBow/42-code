/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:31:33 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/10/14 17:06:18 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEST_LINE_H
# define GET_NEST_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# ifndef FDBUFFER
#  define FDBUFFER 1024
# endif

typedef struct	s_fdstate
{
	size_t	nl_offset;
	char	*buf;
}				t_fdstate;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
int		ft_strchr_getnxtlin(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif