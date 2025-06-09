/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:43:35 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/06/09 19:45:39 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	ptr->meals_eaten += 1;
	pthread_mutex_lock(&data->update);
	ptr->last_meal_time = ft_get_time(data);
	pthread_mutex_unlock(&data->update);
	print_status(ptr, "is eating");
	ft_usleep(data->time_to_eat, data, ptr);
	pthread_mutex_unlock(&(data->fork[ptr->id]));
	pthread_mutex_unlock(&(data->fork[next]));
	if (ptr->meals_eaten == data->eat_goal)
		ptr->meals_eaten += 1;
	return (0);
}
