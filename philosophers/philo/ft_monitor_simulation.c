/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor_simulation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:39:56 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/06/19 15:15:47 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_if_all_fat(t_data *data)
{
	int	i;
	int	all_fat;

	if (data->eat_goal == -1)
		return (0);
	i = 0;
	all_fat = 1;
	pthread_mutex_lock(&data->update);
	while (i < data->philosophers)
	{
		if (data->threads[i]->meals_eaten < data->eat_goal)
			all_fat = 0;
		i++;
	}
	if (all_fat)
		data->simulation_status = 0;
	pthread_mutex_unlock(&data->update);
	return (all_fat);
}

static int	ft_skipper(t_data *data, int i)
{
	pthread_mutex_lock(&data->update);
	if (data->eat_goal > 0 && data->threads[i] && \
		data->threads[i]->meals_eaten >= data->eat_goal)
	{
		pthread_mutex_unlock(&data->update);
		return (1);
	}
	pthread_mutex_unlock(&data->update);
	return (0);
}

static int	check_for_death(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philosophers)
	{
		while (ft_skipper(data, i))
			i++;
		if (i >= data->philosophers)
			break ;
		pthread_mutex_lock(&data->update);
		if ((ft_get_time(data) - data->threads[i]->last_meal_time) > \
		data->time_to_die)
		{
			pthread_mutex_unlock(&data->update);
			print_status(data->threads[i], "died");
			pthread_mutex_lock(&data->update);
			data->simulation_status = 0;
			pthread_mutex_unlock(&data->update);
			return (1);
		}
		pthread_mutex_unlock(&data->update);
		i++;
	}
	return (0);
}

int	ft_monitor_simulation(t_data *d)
{
	while (1)
	{
		if (check_for_death(d) || check_if_all_fat(d))
			break ;
		usleep(100);
	}
	usleep(10000);
	ft_freedata(d, 0);
	if (d->simulation_status == -1)
		return (1);
	return (0);
}
