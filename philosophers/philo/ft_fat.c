/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:43:35 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/06/19 15:22:58 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_quick(t_philo *ptr, t_data *data)
{
	pthread_mutex_lock(&data->update);
	if (ptr->meals_eaten == data->eat_goal)
		ptr->meals_eaten += 1;
	pthread_mutex_unlock(&data->update);
}

int	ft_fat(t_philo *ptr, t_data *data, int next)
{
	if (ptr->id % 2)
	{
		pthread_mutex_lock(&(data->fork[ptr->id]));
		print_status(ptr, "has taken a fork");
		pthread_mutex_lock(&(data->fork[next]));
	}
	else
	{
		pthread_mutex_lock(&(data->fork[next]));
		print_status(ptr, "has taken a fork");
		pthread_mutex_lock(&(data->fork[ptr->id]));
	}
	print_status(ptr, "has taken a fork");
	pthread_mutex_lock(&data->update);
	ptr->meals_eaten += 1;
	ptr->last_meal_time = ft_get_time(data);
	pthread_mutex_unlock(&data->update);
	print_status(ptr, "is eating");
	ft_usleep(data->time_to_eat, data, ptr);
	pthread_mutex_unlock(&(data->fork[ptr->id]));
	pthread_mutex_unlock(&(data->fork[next]));
	ft_quick(ptr, data);
	return (0);
}
