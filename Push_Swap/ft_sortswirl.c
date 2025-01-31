
#include "pushswap.h"


int	ft_insert_sorta(t_array **arraya, t_array **arrayb)
{
	t_array	*head;
	t_array	*last;

	*arraya = ft_pointto(*arraya, 0);
	head = ft_pointto(*arraya, 0);
	last = ft_pointto(*arraya, -1);
	if (ft_checksorted(*arraya, A) || \
		(ft_checksorted(*arrayb, B) && *arraya == NULL) || !(*arraya))
		return (-1);
	if (head->next->next->value == ft_value(ft_findhighlow(head, B)))
		return (ft_rotate(head, A));
	if (head->value > head->next->value)
		return (ft_swap(head, A));
	if (last->value < head->next->value && head->value < last->value)
		return (ft_reverserotate(head, A));
	if (ft_checkchunk(head, ft_index(ft_findhighlow(head, B)), \
		ft_index(ft_findhighlow(head, B)) - 1))
		return (ft_reverserotate(head, A));
	return (ft_rotate(*arraya, A));
}

int	ft_insert_sortb(t_array **arraya, t_array **arrayb)
{
	t_array	*head;
	t_array	*last;

	*arraya = ft_pointto(*arraya, 0);
	head = ft_pointto(*arrayb, 0);
	last = ft_pointto(*arrayb, -1);
	if ((ft_checksorted(head, A) && *arrayb == NULL) || \
		ft_checksorted(*arrayb, B) || !(*arrayb))
		return (-1);
	if (ft_checkchunk_b(head, ft_index(ft_findhighlow(head, A)), \
		ft_index(ft_findhighlow(head, A)) - 1))
		return (ft_rotate((*arrayb), B));
	if (head->value < head->next->value)
		return (ft_swap((*arrayb), B));
	if (head->value > last->value && last->value > head->next->value)
		return (ft_reverserotate((*arrayb), B));
	return (ft_rotate((*arrayb), B));
}

int	ft_splitstacks(t_array **arraya, t_array **arrayb, int peak)
{
	t_array	*head;
	t_array	*last;
	int		mid;

	mid = (peak / 2);
	*arraya = ft_pointto(*arraya, 0);
	head = ft_pointto(*arraya, 0);
	last = ft_pointto(*arraya, -1);
	if (ft_checksorted(*arraya, A))
		return (-1);
	if (!ft_peakfinished(arraya, peak) && (head->value <= mid || mid == 0))
		return (ft_push(arraya, arrayb, A));
	if (!ft_peakfinished(arraya, peak) && ft_find_direction(head, mid) == 2)
		return (ft_reverserotate(*arraya, A));
	else
		if (!ft_peakfinished(arraya, peak) && ft_find_direction(head, mid) == 1)
			return (ft_rotate(*arraya, A));
	else
		if (!ft_peakfinished(arraya, peak) && ft_find_direction(head, mid) == 0)
			return (ft_rotate(*arraya, A));
	return (-1);
}

int ft_peakfinished(t_array **arraya, int peak)
{
	int underudder;	
	t_array	*tmp;
	t_array	*last;

	tmp = ft_pointto(*arraya, 0);
	last = ft_pointto(*arraya, -1);
	underudder = (peak / 2);
	while (1)
	{
		if (tmp->value <= underudder)
			return (0);
		if (tmp->index == last->index)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_array	*ft_sortswirl(t_array **arraya, t_array **arrayb, t_array **commands)
{
	int		peak;

	peak = ft_value(ft_findhighlow(*arraya, A));
	while (!ft_peakfinished(arraya, peak) && !ft_checksorted(*arraya, A))
		*commands = ft_comadd(ft_splitstacks(arraya, arrayb, peak), *commands);
	while (!(ft_checksorted(*arraya , A) && *arrayb == NULL))
	{
		*arraya = ft_pointto(*arraya, 0);
		*arrayb = ft_pointto(*arrayb, 0);
		*commands = ft_comadd(ft_insert_sorta(arraya, arrayb), *commands);
		*commands = ft_comadd(ft_insert_sortb(arraya, arrayb), *commands);
		while ((ft_checksorted(*arraya , A) && ft_checksorted(*arrayb, B)))
				*commands = ft_comadd(ft_push(arrayb, arraya, B), *commands);
	}
	return (*commands);
}