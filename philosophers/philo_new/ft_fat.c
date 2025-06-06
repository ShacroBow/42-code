/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:43:35 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/06/06 20:45:41 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_fat(t_philo *ptr, t_data *data, t_philo *next, int simulation)
{
	if (simulation > 0)
	{
		print_status(ptr, "has taken a fork");
		pthread_mutex_lock(&(data->fork[ptr->id]));
		pthread_mutex_lock(&(data->fork[next->id]));
		ptr->meals_eaten += 1;
		ptr->last_meal_time = ft_get_time(data);
		print_status(ptr, "is eating");
		ft_usleep(data->time_to_eat, data, ptr, next);
		pthread_mutex_unlock(&(data->fork[ptr->id]));
		pthread_mutex_unlock(&(data->fork[next->id]));
	}
	return (0);
}
