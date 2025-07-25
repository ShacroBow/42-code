/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:43:45 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/06/19 15:28:13 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_philo_setup_setup(t_data *data, t_philo *ptr)
{
	if (data->philosophers <= 1)
	{
		ptr->last_meal_time = 0;
		ft_usleep(data->time_to_die + 10, data, ptr);
	}
	if (ptr->id % 2 == 0)
		usleep(10);
}

static void	ft_philo_setup(t_data *data, t_philo **ptr, int *next)
{
	pthread_mutex_lock(&data->update);
	if (data->simulation_status == -1)
	{
		pthread_mutex_unlock(&data->update);
		return ;
	}
	(*ptr) = (t_philo *)data->threads[data->simulation_status];
	data->simulation_status++;
	(*next) = (*ptr)->id + 1;
	if ((*ptr)->id == (data->philosophers - 1) && data->philosophers > 1)
		(*next) = 0;
	pthread_mutex_unlock(&data->update);
	pthread_mutex_lock(&data->barrier);
	pthread_mutex_unlock(&data->barrier);
	pthread_mutex_lock(&data->update);
	if (data->simulation_status == -1)
	{
		pthread_mutex_unlock(&data->update);
		return ;
	}
	(*ptr)->last_meal_time = ft_get_time(data);
	pthread_mutex_unlock(&data->update);
	ft_philo_setup_setup(data, *ptr);
}

static void	ft_philo_end(t_data *data, t_philo *ptr)
{
	int	sim;

	sim = 0;
	if (ptr == NULL)
		return ;
	pthread_mutex_lock(&data->update);
	sim = data->simulation_status;
	pthread_mutex_unlock(&data->update);
	if (sim > 0)
	{
		pthread_mutex_lock(&data->update);
		data->simulation_status--;
		pthread_mutex_unlock(&data->update);
	}
	ft_usleep(10000, data, ptr);
	usleep(1000);
}

int	ft_philo_die(t_data *data, t_philo *ptr, int *sim)
{
	if (!data || !ptr || *sim == -1)
		return (1);
	pthread_mutex_lock(&data->update);
	*sim = data->simulation_status;
	if ((((ft_get_time(data) - ptr->last_meal_time) > (data->time_to_die)) || \
	!(*sim)) && ((ptr->meals_eaten < data->eat_goal && data->eat_goal > 0) || \
	data->eat_goal <= 0))
	{
		pthread_mutex_unlock(&data->update);
		print_status(ptr, "died");
		pthread_mutex_lock(&data->update);
		data->simulation_status = 0;
		*sim = data->simulation_status;
		pthread_mutex_unlock(&data->update);
		return (1);
	}
	pthread_mutex_unlock(&data->update);
	return (0);
}

void	*ft_philosopher(void *tmp)
{
	t_data	*data;
	t_philo	*ptr;
	int		next;
	int		simulation;

	data = (t_data *)tmp;
	simulation = 1;
	ptr = NULL;
	ft_philo_setup(data, &ptr, &next);
	pthread_mutex_lock(&data->update);
	simulation = data->simulation_status;
	pthread_mutex_unlock(&data->update);
	while ((ptr && data) && (ptr->meals_eaten < data->eat_goal \
			|| data->eat_goal == -1) && simulation > 0)
	{
		if (ft_philo_die(data, ptr, &simulation))
			break ;
		ft_fat(ptr, data, next);
		print_status(ptr, "is sleeping");
		ft_usleep(data->time_to_sleep, data, ptr);
		print_status(ptr, "is thinking");
	}
	ft_philo_end(data, ptr);
	return (NULL);
}
