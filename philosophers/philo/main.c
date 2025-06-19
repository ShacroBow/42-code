/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:46:37 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/06/19 15:23:45 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*ft_create_philosopher(t_data *data, int i)
{
	t_philo	*ptr;

	ptr = data->threads[i];
	ptr->id = i;
	ptr->last_meal_time = 0;
	ptr->meals_eaten = 0;
	ptr->data = data;
	ptr->fork = data->fork[i];
	ptr->thread = 0;
	return (ptr);
}

t_data	*ft_memoryhandling(t_data *data)
{
	int	i;

	data->fork = malloc((data->philosophers + 1) * sizeof(pthread_mutex_t));
	if (!data->fork)
		return (NULL);
	i = 0;
	while (i < data->philosophers)
	{
		data->threads[i] = malloc(1 * (sizeof(t_philo)));
		if (data->threads[i] == NULL)
			return (ft_freedata(data, -1));
		data->threads[i] = ft_create_philosopher(data, i);
		if (data->threads[i] == NULL)
			return (ft_freedata(data, -1));
		i++;
	}
	i = 0;
	while (i < data->philosophers)
	{
		if (pthread_mutex_init(&data->fork[i], NULL))
			return (ft_freedata(data, -1), NULL);
		i++;
	}
	return (data);
}

void	*ft_datainit(t_data *data, char **av)
{
	data->philosophers = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->simulation_status = 0;
	data->epoch = 0;
	if (av[5] != NULL)
		data->eat_goal = ft_atoi(av[5]);
	else
		data->eat_goal = -1;
	data->threads = malloc((data->philosophers + 1) * (sizeof(t_philo *)));
	if (data->threads == NULL)
		return (NULL);
	data->threads[data->philosophers] = NULL;
	if (!ft_memoryhandling(data))
		return (free(data->threads), NULL);
	if (pthread_mutex_init(&data->print, NULL))
		return (ft_freedata(data, -1), NULL);
	if (pthread_mutex_init(&data->update, NULL))
		return (ft_freedata(data, -1), NULL);
	if (pthread_mutex_init(&data->barrier, NULL))
		return (ft_freedata(data, -1), NULL);
	return (data);
}

void	ft_usleep(long duration_ms, t_data *data, t_philo *ptr)
{
	long	finish;
	int		sim;

	sim = 1;
	finish = ft_get_time(data) + duration_ms;
	while (ft_get_time(data) < finish && sim > 0)
	{
		if (ptr && ft_philo_die(data, ptr, &sim))
			break ;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_data	data;
	t_philo	*ptr;

	if (!(argc >= 5 && argc <= 6) || !ft_validinput(argc, argv) || \
		ft_datainit(&data, argv) == NULL)
		return (1);
	i = 0;
	pthread_mutex_lock(&data.barrier);
	while (i < data.philosophers)
	{
		ptr = data.threads[i];
		if (pthread_create(&(ptr->thread), NULL, ft_philosopher, &data) != 0)
		{
			pthread_mutex_lock(&data.update);
			data.simulation_status = -1;
			data.threads[i]->thread = 0;
			pthread_mutex_unlock(&data.update);
			pthread_mutex_unlock(&data.barrier);
			return (ft_freedata(&data, -1), 1);
		}
		i++;
	}
	data.epoch = ft_get_time(&data);
	return (pthread_mutex_unlock(&data.barrier), ft_monitor_simulation(&data));
}
