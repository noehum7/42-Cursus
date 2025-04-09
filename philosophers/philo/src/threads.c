/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:22:31 by nporras-          #+#    #+#             */
/*   Updated: 2025/04/02 15:56:08 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	single_philosopher_routine(t_philosopher *philo)
{
	int	fork_index;

	fork_index = philo->id - 1;
	pthread_mutex_lock(&philo->data->fork_mutex[fork_index]);
	print_state(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->data->fork_mutex[fork_index]);
	precise_sleep(philo->data->time_to_die);
}

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (philo->data->num_philos == 1)
	{
		single_philosopher_routine(philo);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!check_death(philo->data))
	{
		if (!take_forks(philo))
			continue ;
		philo_eat(philo);
		release_forks(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

int	create_threads(t_philosopher *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, philosopher_routine,
				&philos[i]) != 0)
		{
			while (--i >= 0)
				pthread_join(philos[i].thread, NULL);
			return (0);
		}
		i++;
	}
	return (1);
}

void	join_threads(t_philosopher *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
}
