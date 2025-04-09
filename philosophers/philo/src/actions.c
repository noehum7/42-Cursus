/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:22:31 by nporras-          #+#    #+#             */
/*   Updated: 2025/04/02 15:53:53 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philosopher *philo)
{
	long	current_time;

	print_state(philo, "is eating");
	current_time = get_time_ms();
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = current_time;
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
	precise_sleep(philo->data->time_to_eat);
}

void	philo_sleep(t_philosopher *philo)
{
	print_state(philo, "is sleeping");
	precise_sleep(philo->data->time_to_sleep);
}

void	philo_think(t_philosopher *philo)
{
	print_state(philo, "is thinking");
}
