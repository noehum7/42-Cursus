/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:22:31 by nporras-          #+#    #+#             */
/*   Updated: 2025/04/02 15:54:29 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	get_fork_indices(t_philosopher *philo, int *left, int *right)
{
	*left = philo->id - 1;
	*right = (philo->id % philo->data->num_philos);
}

static int	take_forks_even(t_philosopher *philo, int left, int right)
{
	pthread_mutex_lock(&philo->data->fork_mutex[right]);
	pthread_mutex_lock(&philo->data->fork_mutex[left]);
	if (check_death(philo->data))
	{
		pthread_mutex_unlock(&philo->data->fork_mutex[left]);
		pthread_mutex_unlock(&philo->data->fork_mutex[right]);
		return (0);
	}
	print_state(philo, "has taken a fork");
	print_state(philo, "has taken a fork");
	return (1);
}

static int	take_forks_odd(t_philosopher *philo, int left, int right)
{
	pthread_mutex_lock(&philo->data->fork_mutex[left]);
	pthread_mutex_lock(&philo->data->fork_mutex[right]);
	if (check_death(philo->data))
	{
		pthread_mutex_unlock(&philo->data->fork_mutex[right]);
		pthread_mutex_unlock(&philo->data->fork_mutex[left]);
		return (0);
	}
	print_state(philo, "has taken a fork");
	print_state(philo, "has taken a fork");
	return (1);
}

int	take_forks(t_philosopher *philo)
{
	int	left_fork;
	int	right_fork;

	if (check_death(philo->data))
		return (0);
	get_fork_indices(philo, &left_fork, &right_fork);
	if (philo->id % 2 == 0)
		return (take_forks_even(philo, left_fork, right_fork));
	else
		return (take_forks_odd(philo, left_fork, right_fork));
}

void	release_forks(t_philosopher *philo)
{
	int	left_fork;
	int	right_fork;

	get_fork_indices(philo, &left_fork, &right_fork);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&philo->data->fork_mutex[left_fork]);
		pthread_mutex_unlock(&philo->data->fork_mutex[right_fork]);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->fork_mutex[right_fork]);
		pthread_mutex_unlock(&philo->data->fork_mutex[left_fork]);
	}
}
