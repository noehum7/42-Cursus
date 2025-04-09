/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:23:00 by nporras-          #+#    #+#             */
/*   Updated: 2025/04/02 15:57:01 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_death_message(t_philosopher *philo, char *state)
{
	int	already_dead;

	pthread_mutex_lock(&philo->data->death_mutex);
	already_dead = philo->data->someone_died;
	if (!already_dead)
	{
		philo->data->someone_died = 1;
		pthread_mutex_unlock(&philo->data->death_mutex);
		pthread_mutex_lock(&philo->data->print_mutex);
		printf("%ld %d %s\n", get_time_ms() - philo->data->start_time,
			philo->id, state);
		pthread_mutex_unlock(&philo->data->print_mutex);
	}
	else
		pthread_mutex_unlock(&philo->data->death_mutex);
}

int	check_args(int ac, t_data *data)
{
	if (data->num_philos <= 0 || data->num_philos > 200)
		return (1);
	if (data->time_to_die <= 0 || data->time_to_sleep <= 0
		|| data->time_to_eat <= 0)
		return (1);
	if (ac == 6 && data->meals_required <= 0)
		return (1);
	return (0);
}

int	check_death(t_data *data)
{
	int	result;

	result = 0;
	pthread_mutex_lock(&data->death_mutex);
	result = data->someone_died;
	pthread_mutex_unlock(&data->death_mutex);
	return (result);
}

void	free_resources(t_philosopher *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_destroy(&philos[i].meal_mutex);
		pthread_mutex_destroy(&data->fork_mutex[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->death_mutex);
	free(data->fork_mutex);
}

void	print_state(t_philosopher *philo, char *state)
{
	int	is_death_message;

	is_death_message = (ft_strcmp(state, "died") == 0);
	if (is_death_message)
		print_death_message(philo, state);
	else
	{
		pthread_mutex_lock(&philo->data->print_mutex);
		if (!check_death(philo->data))
		{
			printf("%ld %d %s\n", get_time_ms() - philo->data->start_time,
				philo->id, state);
		}
		pthread_mutex_unlock(&philo->data->print_mutex);
	}
}
