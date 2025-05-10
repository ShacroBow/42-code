/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:43:45 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/05/10 18:44:36 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_philo_setup(t_data *data, t_philo **ptr, t_philo **next)
{
	pthread_mutex_lock(data->update);
	(*ptr) = (t_philo *)data->threads[data->simulation_status];
	data->simulation_status++;
	(*next) = (t_philo *)data->threads[(*ptr)->id + 1];
	if ((*ptr)->id == (data->philosophers - 1) && data->philosophers > 1)
		(*next) = data->threads[0];
	pthread_mutex_unlock(data->update);
	pthread_mutex_lock(data->barrier);
	usleep(10);
	pthread_mutex_unlock(data->barrier);
	(*ptr)->last_meal_time = ft_get_time();
}

static void	ft_philo_end(t_data *data, t_philo *ptr)
{
	print_status(ptr, "became fat");
	pthread_mutex_lock(data->update);
	data->simulation_status--;
	pthread_mutex_unlock(data->update);
	usleep(data->time_to_sleep + data->time_to_eat * 10000);
	pthread_mutex_lock(data->barrier);
	usleep(100);
	pthread_mutex_unlock(data->barrier);
}

static int	ft_philo_die(t_data *data, t_philo *ptr, t_philo *next, int *sim)
{
	if (((ft_get_time() - ptr->last_meal_time) > (data->time_to_die)) || !next)
	{
		print_status(ptr, "died");
		pthread_mutex_lock(data->update);
		data->simulation_status = 0;
		*sim = data->simulation_status;
		pthread_mutex_unlock(data->update);
		return (1);
	}
	pthread_mutex_lock(data->update);
	*sim = data->simulation_status;
	pthread_mutex_unlock(data->update);
	return (0);
}

void	*ft_philosopher(void *tmp)
{
	t_data	*data;
	t_philo	*ptr;
	t_philo	*next;
	int		simulation;

	data = (t_data *)tmp;
	simulation = 1;
	ft_philo_setup(data, &ptr, &next);
	while ((ptr->meals_eaten < data->eat_goal || data->eat_goal == -1) && \
			simulation > 0)
	{
		if (ft_philo_die(data, ptr, next, &simulation))
			break ;
		if (next && ft_fat(ptr, data, next, simulation) && simulation > 0)
			continue ;
		print_status(ptr, "is thinking");
		usleep(data->time_to_sleep * 1000);
		if (ft_philo_die(data, ptr, next, &simulation))
			break ;
		print_status(ptr, "is sleeping");
		usleep(data->time_to_sleep * 1000);
	}
	if (simulation > 0)
		ft_philo_end(data, ptr);
	return (NULL);
}
