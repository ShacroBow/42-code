/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:48:55 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/06/09 19:21:27 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_philo
{
	int				id;
	long			last_meal_time;
	int				meals_eaten;
	pthread_t		thread;
	pthread_mutex_t	fork;
	void			*data;
}	t_philo;

typedef struct s_data
{
	int				philosophers;
	t_philo			**threads;
	long int		time_to_die;
	long int		time_to_eat;
	long int		time_to_sleep;
	int				eat_goal;
	long int		epoch;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	update;
	pthread_mutex_t	barrier;
	int				simulation_status;
}	t_data;

void		*ft_philosopher(void *tmp);
void		print_status(t_philo *philo, const char *status);
int			ft_fat(t_philo *ptr, t_data *data, int next);
long		ft_get_time(t_data *data);
void		print_status(t_philo *philo, const char *status);
void		*ft_validinput(int argc, char **argv);
void		*ft_freedata(t_data *data, int sim);
int			ft_atoi(const char *nptr);
void		ft_usleep(long duration_ms, t_data *data, t_philo *ptr);
int			ft_philo_die(t_data *data, t_philo *ptr, int *sim);
int			ft_monitor_simulation(t_data *d);

//drd, helgrind and --fair-sched=yes
#endif