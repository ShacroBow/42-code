/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:22:15 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/02/12 17:24:04 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <unistd.h>
# include <stdio.h>
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

t_array	*ft_pushswap(t_array **arraya, t_array **arraybcommands);
void	ft_print(int command);
int		*ft_radixposition(int *buf, int len);
// int		*ft_parse_arguments(char **argv, int *len);
int		*ft_parse_string(char **argv, int *array, int *len);
long	ft_atol(const char *nptr, int *len);
char	*ft_skipwhitespace(char *str);
char	*ft_proper_input(char *str);
int		ft_count_arguments(char *str);
void	ft_exiterror(void *str);
t_array	*ft_createlist(int len);
//index < 0. means it will point to last element.
t_array	*ft_pointto(t_array *ptr, int index);
int		ft_swap(t_array *array, int aorb);
int		ft_correctindex(t_array *arrayhead);
int		ft_push(t_array **array, t_array **target, int aorb);
int		ft_rotate(t_array *array, int aorb);
int		ft_reverserotate(t_array *array, int aorb);
t_array	*ft_applyarray(t_array *linkedlist, int *array, int len);
void	ft_commandprinter(t_array *commands);
int		ft_checkchunk(t_array *array, int startindex, int endindex);
int		ft_checksorted(t_array *array, int aorb);
//A means you look for max. B means you look for min
t_array	*ft_findhighlow(t_array *array, int aorb);
int		ft_index(t_array *array);
// t_array	*ft_next(t_array *array);
int		ft_value(t_array *array);
int		ft_arraysize(t_array *array);
t_array	*ft_comadd(int comadd, t_array *commands);
int		ft_peakfinished(t_array **array, int peak);
void	ft_freearray(t_array **array);
int		ft_checkchunk_b(t_array *array, int startindex, int endindex);
t_array	*ft_backtrace(t_array **arraya, t_array **arrayb, t_array *com, int n);
//sorting algorithms
int		ft_sortsmall(t_array *array);
t_array	*ft_sortswirl(t_array **arraya, t_array **arrayb, t_array **commands);
int		ft_splitstacks(t_array **arraya, t_array **arrayb, int peak);
int		ft_insert_sorta(t_array **arraya, t_array **arrayb);
int		ft_insert_sortb(t_array **arraya, t_array **arrayb);
int		ft_find_direction(t_array *array, int targetcutoff);
t_array	*ft_ogresize(t_array **arraya, t_array **arrayb, t_array **com, int n);
t_array	*ft_ogrechunk(t_array **arya, t_array **aryb, t_array **com, int n);
t_array	*ft_ogrebackchunk(t_array **arya, t_array **aryb, t_array **com);

#endif
