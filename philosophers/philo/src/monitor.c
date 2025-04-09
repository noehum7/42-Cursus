/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:23:00 by nporras-          #+#    #+#             */
/*   Updated: 2025/04/02 15:55:42 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_all_ate(t_data *data, int total_meals)
{
	pthread_mutex_lock(&data->death_mutex);
	if (!data->someone_died && total_meals == data->num_philos)
	{
		data->someone_died = 1;
		pthread_mutex_unlock(&data->death_mutex);
		pthread_mutex_lock(&data->print_mutex);
		printf("All philosophers have eaten %d times\n", data->meals_required);
		pthread_mutex_unlock(&data->print_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->death_mutex);
	return (0);
}

static int	check_philosopher_death(t_philosopher *philo, long current_time)
{
	long	time_since_last_meal;

	pthread_mutex_lock(&philo->meal_mutex);
	time_since_last_meal = current_time - philo->last_meal_time;
	pthread_mutex_unlock(&philo->meal_mutex);
	return (time_since_last_meal > philo->data->time_to_die);
}

static int	count_meals(t_philosopher *philos, t_data *data)
{
	int	i;
	int	total_meals;

	i = 0;
	total_meals = 0;
	while (i < data->num_philos && !check_death(data))
	{
		pthread_mutex_lock(&philos[i].meal_mutex);
		if (data->meals_required > 0
			&& philos[i].meals_eaten >= data->meals_required)
			total_meals++;
		pthread_mutex_unlock(&philos[i].meal_mutex);
		i++;
	}
	return (total_meals);
}

static void	mark_death(t_philosopher *philo, long time_diff)
{
	pthread_mutex_lock(&philo->data->death_mutex);
	if (!philo->data->someone_died)
	{
		philo->data->someone_died = 1;
		pthread_mutex_unlock(&philo->data->death_mutex);
		pthread_mutex_lock(&philo->data->print_mutex);
		printf("%ld %d died\n", time_diff, philo->id);
		pthread_mutex_unlock(&philo->data->print_mutex);
	}
	else
		pthread_mutex_unlock(&philo->data->death_mutex);
}

void	monitor_philosophers(t_philosopher *philos, t_data *data)
{
	int		i;
	long	current_time;
	int		total_meals;

	usleep(1000);
	while (!check_death(data))
	{
		i = 0;
		while (i < data->num_philos && !check_death(data))
		{
			current_time = get_time_ms();
			if (check_philosopher_death(&philos[i], current_time))
			{
				mark_death(&philos[i], current_time - data->start_time);
				return ;
			}
			i++;
		}
		total_meals = count_meals(philos, data);
		if (data->meals_required > 0 && check_all_ate(data, total_meals))
			return ;
		usleep(500);
	}
}
