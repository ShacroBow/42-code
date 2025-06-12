/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:43:35 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/05/10 18:43:36 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_fat(t_philo *ptr, t_data *data, t_philo *next, int simulation)
{
	pthread_mutex_lock(data->fork);
	if (simulation > 0 && next->fork_taken == 0 && ptr->fork_taken == 0)
	{
		pthread_mutex_unlock(data->fork);
		print_status(ptr, "has taken a fork");
		pthread_mutex_lock(data->fork);
		next->fork_taken = 1;
		ptr->fork_taken = 1;
		pthread_mutex_unlock(data->fork);
		ptr->meals_eaten += 1;
		print_status(ptr, "is eating");
		usleep(data->time_to_eat * 1000);
		ptr->last_meal_time = ft_get_time();
		pthread_mutex_lock(data->fork);
		next->fork_taken = 0;
		ptr->fork_taken = 0;
		pthread_mutex_unlock(data->fork);
		print_status(ptr, "putting forks back");
	}
	else
	{
		pthread_mutex_unlock(data->fork);
		return (1);
	}
	return (0);
}
