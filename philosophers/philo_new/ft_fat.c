/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kha <kha@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:43:35 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/06/09 04:05:59 by kha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_fat(t_philo *ptr, t_data *data, t_philo *next, int simulation)
{
	if (simulation < 1)
		return (1);
	if (ptr->id % 2)
	{
		pthread_mutex_lock(&(data->fork[ptr->id]));
		print_status(ptr, "has taken a fork");
		pthread_mutex_lock(&(data->fork[next->id]));
	}
	else
	{
		pthread_mutex_lock(&(data->fork[next->id]));
		print_status(ptr, "has taken a fork");
		pthread_mutex_lock(&(data->fork[ptr->id]));
	}
	print_status(ptr, "has taken a fork");
	ft_philo_die(data, ptr, &simulation);
	ptr->meals_eaten += 1;
	ptr->last_meal_time = ft_get_time(data);
	print_status(ptr, "is eating");
	ft_usleep(data->time_to_eat, data, ptr);
	pthread_mutex_unlock(&(data->fork[ptr->id]));
	pthread_mutex_unlock(&(data->fork[next->id]));
	return (0);
}
