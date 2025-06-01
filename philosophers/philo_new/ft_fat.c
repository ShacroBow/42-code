/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:43:35 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/06/01 21:12:04 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_fat(t_philo *ptr, t_data *data, t_philo *next, int simulation)
{
	pthread_mutex_lock(data->fork);
	if (simulation > 0 && next->fork_taken == 0 && ptr->fork_taken == 0)
	{
		next->fork_taken = 1;
		ptr->fork_taken = 1;
		ptr->meals_eaten += 1;
		pthread_mutex_unlock(data->fork);
		print_status(ptr, "is eating");
		ft_usleep(data->time_to_eat, data, ptr, next);
		ptr->last_meal_time = ft_get_time(data);
		pthread_mutex_lock(data->fork);
		next->fork_taken = 0;
		ptr->fork_taken = 0;
		pthread_mutex_unlock(data->fork);
	}
	else
	{
		pthread_mutex_unlock(data->fork);
		return (1);
	}
	return (0);
}
