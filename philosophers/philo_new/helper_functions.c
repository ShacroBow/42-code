/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 19:15:56 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/06/12 18:36:13 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	ft_get_time(t_data *data)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000) - data->epoch);
}

void	print_status(t_philo *philo, const char *status)
{
	t_data	*data;
	int		simulation;

	data = (t_data *)philo->data;
	pthread_mutex_lock(&data->print);
	pthread_mutex_lock(&data->update);
	simulation = data->simulation_status;
	pthread_mutex_unlock(&data->update);
	if (simulation > 0 && (data->eat_goal > 0) && \
		philo->meals_eaten <= data->eat_goal)
		printf("%-5ld %2d %s\n", ft_get_time(data), philo->id + 1, status);
	else if (simulation > 0 && data->eat_goal == -1)
		printf("%-5ld %2d %s\n", ft_get_time(data), philo->id + 1, status);
	pthread_mutex_unlock(&data->print);
}
//printf("%-5ld %2d %d %s\n", ft_get_time(data), \
//philo->id, philo->meals_eaten, status);

void	*ft_validinput(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i])
		{
			if (!(argv[j][i] >= 48 && argv[j][i] <= 57))
				return (NULL);
			i++;
		}
		j++;
	}
	return (argv[0]);
}

static void	ft_forkit(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philosophers && data->fork != NULL)
	{
		pthread_mutex_destroy(&(data->fork[i]));
		i++;
	}
	free(data->fork);
}

void	*ft_freedata(t_data *data, int sim)
{
	int	i;

	i = 0;
	usleep(10000);
	while (i < data->philosophers && data->threads != NULL)
	{
		if (data->threads[i] == NULL)
			break ;
		pthread_join(data->threads[i]->thread, NULL);
		free(data->threads[i]);
		data->threads[i] = NULL;
		i++;
	}
	if (data->threads)
		free(data->threads);
	ft_forkit(data);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->update);
	pthread_mutex_destroy(&data->barrier);
	data->simulation_status = sim;
	return (NULL);
}
