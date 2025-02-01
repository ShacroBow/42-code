
t_array	*ft_chunky(t_array **arraya, t_array **arrayb, t_array **commands);
int		*ft_chunko(t_array **array, int *len, int n);
t_array	*ft_chunked_upa(t_array **array, int *targets, int len);
t_array	*ft_chunked_upb(t_array **array, int *targets, int len);
t_array	*ft_chunkedfinished(t_array **arraya, int *targets, int len);

int	*ft_chunko(t_array **array, int *len, int n)
{
	int	i;
	int	peak;
	int	chunksize;
	int	*ptr;

	peak = ft_value(ft_findhighlow(*array, A));
	chunksize = peak / n;
	if (chunksize == 0)
		return (NULL);
	i = 0;
	while (i < peak)
	{
		(*len) += 1;
		i = chunksize + i;
	}
	i = 1;
	ptr = ft_calloc((*len) + 1, sizeof(int));
	if (!ptr)
		return (NULL);
	while (i < *len)
	{
		ptr[i] = chunksize * i;
		i++;
	}
	ptr[i] = peak;
	return (ptr);
}

t_array	*ft_chunky(t_array **arraya, t_array **arrayb, t_array **com, int n)
{
	int	lena;
	int	lenb;
	int	*ta;
	int	*tb;

	lena = 0;
	lenb = 0;
	ta = ft_chunko(arraya, &lena, n);
	tb = ft_chunko(arrayb, &lenb, n);
	while (!(ft_chunkedfinished(arraya, ta, lena, A) && \
			ft_chunkedfinished(arrayb, ta, lena, B)))
	{
		*com = ft_comadd(ft_chunked_upa(arraya, ta, lena), *com);
		*com = ft_comadd(ft_chunked_upb(arrayb, tb, lenb), *com);
	}
	if (ta != NULL)
		free(ta);
	if (tb != NULL)
		free(tb);
	return (*com);
}

-----------------------------
t_array	*ft_halvesorta(t_array **array, int high, int low)
{
	int		pivot;
	int		i;
	t_array	*head;
	t_array	*last;
	t_array	*pivoted;
	
	

	i = 0;
	1 for above. 2 for below. 0 for same position. 3 for move away = ft_pivothelp(head, pivoted);
	pivoted = ft_findvalue(*array, (high->value / 2));
	pivot = pivoted->value; //(ft_findhighlow(*array, A) / 2)
	*array = ft_pointto(*array, 0);
	head = ft_pointto(*array, 0);
	last = ft_pointto(*array, -1);
	if (ft_halvefinished(array, pivot, high, low))
		return (-1);

	if (ft_pivothelp(head, pivoted) == 2 && head->) // pivot > (ft_index(ft_pointto(array, -1)) / 2))
	{
		if (head->next->value < pivot && head->value < pivot)
			return (ft_swap(head, A));
		if (head->value > pivot)
			return (ft_reverserotate(head, A));
	}
	else if (ft_pivothelp(head, pivoted) == 1)
	{
		if (head->next->index > pivot && head->index < pivot)
			return (ft_swap(head, A));
		if (head->index > pivot)
			return (ft_rotate(head, A));
	}
	if (ft_halvefinished(head, pivoted, high, head))
		return (ft_rotate(head, A));
	if (ft_halvefinished(head, pivoted, head, low))
		return (ft_reverserotate(head, A));
	return (ft_rotate(*array, A));
}

t_array	*ft_halvesortb(t_array **array, int high, int low)
{
	
}

int	ft_findhalve(t_array *array, int high, int low)
{
	
}

t_array	*ft_halvesort(t_array **arraya, t_array **arrayb, t_array **com)
{
	int	higha;
	int	lowa;
	int	highb;
	int	lowb;

	while (!(ft_halvefinished() && ft_halvefinished()))
	{
		*com = ft_comadd(ft_halvesorta(arraya, higha, lowa), *com);
		*com = ft_comadd(ft_halvesortb(arrayb, highb, lowb), *com);
	}
	if (ta != NULL)
		free(ta);
	if (tb != NULL)
		free(tb);
	return (*com);
}

---------------------------------
// // t_array	*ft_orient_sort(t_array **arraya, t_array **arrayb)
// // {
// // 	int		i;
// // 	int		previousval;
// // 	t_array	*tmp;
// // 	t_array	*last;

// // 	tmp = ft_pointto(array, 0);
// // 	last = ft_pointto(array, -1);
// // 	i = 0;
// // 	while (1)
// // 	{
// // 			return (0);
// // 	}
// // }

// static int	ft_compresscommands_helper(int commands, int previousval)
// {
// 	if ((previousval == 1 || previousval == 4 || previousval == 7) && (previousval - 1) == commands)
// 	{
// 		return (previousval + 1);
// 	}
// 	if ((previousval == 0 || previousval == 3 || previousval == 6) && (previousval + 1) == commands)
// 	{
// 		return (previousval + 2);
// 	}
// 	return (-1);
// }

// int	*ft_compresscommands(int *commands, int *len)
// {
// 	int	i;
// 	int	j;
// 	int	previousval;
// 	int	*tmp;

// 	i = 0;
// 	j = 0;
// 	while (i < *len)
// 	{
// 		previousval = commands[i];
// 		i++;
// 		if ((previousval + 1) == commands[i] || (previousval - 1) == commands[i])
// 		{
// 			tmp = ft_comadd(ft_compresscommands_helper(commands[i], previousval), &tmp, &j);
// 			i++;
// 		}
// 		else
// 			tmp = ft_comadd(commands[i], &tmp, &j);
// 	}
// 	*len = j;
// 	return (tmp);
// }
