/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:22:38 by nporras-          #+#    #+#             */
/*   Updated: 2025/04/02 15:55:15 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_fork_mutexes(t_data *data)
{
	int	i;

	i = 0;
	data->fork_mutex = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (!data->fork_mutex)
		return (0);
	while (i < data->num_philos)
	{
		if (pthread_mutex_init(&data->fork_mutex[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&data->fork_mutex[i]);
			free(data->fork_mutex);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	init_control_mutexes(t_data *data)
{
	int	i;

	if (pthread_mutex_init(&data->print_mutex, NULL) != 0
		|| pthread_mutex_init(&data->death_mutex, NULL) != 0)
	{
		i = 0;
		while (i < data->num_philos)
			pthread_mutex_destroy(&data->fork_mutex[i++]);
		free(data->fork_mutex);
		return (0);
	}
	return (1);
}

void	init_philosophers(t_philosopher *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		philos[i].id = i + 1;
		philos[i].meals_eaten = 0;
		philos[i].last_meal_time = data->start_time;
		philos[i].data = data;
		pthread_mutex_init(&philos[i].meal_mutex, NULL);
		i++;
	}
}

int	init_data(t_data *data, int ac, char **av)
{
	data->num_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->meals_required = ft_atoi(av[5]);
	else
		data->meals_required = -1;
	if (data->num_philos <= 0 || data->num_philos > 200
		|| data->time_to_die <= 0 || data->time_to_eat <= 0
		|| data->time_to_sleep <= 0 || (ac == 6 && data->meals_required <= 0))
		return (0);
	data->someone_died = 0;
	data->start_time = get_time_ms();
	if (!init_mutexes(data))
		return (0);
	return (1);
}

int	init_mutexes(t_data *data)
{
	if (!init_fork_mutexes(data))
		return (0);
	if (!init_control_mutexes(data))
		return (0);
	return (1);
}
