/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:22:42 by nporras-          #+#    #+#             */
/*   Updated: 2025/04/02 15:55:54 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	clean_all(t_philosopher *philos, t_data *data)
{
	free_resources(philos, data);
	free(philos);
}

static void	show_messages(char *msg)
{
	printf("Error: Invalid number of arguments\n");
	printf("Usage: %s <number_of_philosophers> <time_to_die> ", msg);
	printf("<time_to_eat> <time_to_sleep> ");
	printf("[number_of_times_each_philosopher_must_eat]\n");
}

static t_philosopher	*setup_philos(t_data *data, int ac, char **av)
{
	t_philosopher	*philos;

	if (!init_data(data, ac, av))
	{
		printf("Error: Invalid arguments or initialization failed\n");
		return (NULL);
	}
	philos = malloc(sizeof(t_philosopher) * data->num_philos);
	if (!philos)
	{
		free_resources(NULL, data);
		return (NULL);
	}
	init_philosophers(philos, data);
	return (philos);
}

int	main(int ac, char **av)
{
	t_data			data;
	t_philosopher	*philos;

	if (ac < 5 || ac > 6)
	{
		show_messages(av[0]);
		return (1);
	}
	philos = setup_philos(&data, ac, av);
	if (!philos)
		return (1);
	if (!create_threads(philos, &data))
	{
		clean_all(philos, &data);
		return (1);
	}
	monitor_philosophers(philos, &data);
	join_threads(philos, &data);
	clean_all(philos, &data);
	return (0);
}
