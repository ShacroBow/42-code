/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:22:15 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/12/20 19:36:25 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"
# define A 0
# define B 1
/* getconf ARG_MAX. or 'long sysconf(int name)'for this value in code*/
# define ARGS_MAX 2097152

/*	int value;
	int index;
	t_array *next;*/
typedef struct s_array
{
	int				value;
	int				index;
	struct s_array	*next;
}	t_array;

void	ft_pushswap(int *array, int len);
void	ft_print(int command);
int		*ft_radixposition(int *buf, int len);
int		*ft_parse_arguments(int argc, char **argv);
int		*ft_parse_string(char *argv, int *len);
long	ft_atol(const char *nptr, int *len);
char	*ft_skipwhitespace(char *str);
char	*ft_proper_input(char *str);
int		ft_count_arguments(char *str);
void	ft_exiterror(void *str);
t_array	*ft_createlist(int len);
void	*ft_freelist(t_array *head, int i);
//index < 0. means it will point to last element.
t_array	*ft_pointto(t_array *ptr, int index);
int		*ft_commandresize(int *commands, int len);
int		ft_swap(t_array *array, int aorb);
int		ft_correctindex(t_array *arrayhead);
int		ft_push(t_array *array, t_array **target, int aorb);
int		ft_rotate(t_array *array, int aorb);
int		ft_reverserotate(t_array *array, int aorb);
t_array	*ft_applyarray(t_array *linkedlist, int *array, int len);
void	ft_commandprinter(int *commands, int len);
int		ft_checkchunk(t_array *array, int startindex, int endindex);
int		ft_checksorted(t_array *array);
int		*ft_compresscommands(int *commands, int *len);
int		ft_sort3(t_array *array, int aorb);
t_array	*ft_findhighlow(t_array *array, int aorb);
void	ft_exit_pushswap(t_array *array);
//-unmade
int		ft_movecost(t_array *array);
int		ft_sortsmall(t_array *arraya, t_array *arrayb);
int		ft_sortmid(t_array *arraya, t_array *arrayb);
int		ft_sortlarge(t_array *arraya, t_array *arrayb);
//undoes one single command
int		ft_backtrace(t_array *a, t_array *b, int *commands, int len);

#endif