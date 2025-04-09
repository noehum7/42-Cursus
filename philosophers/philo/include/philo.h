/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:22:47 by nporras-          #+#    #+#             */
/*   Updated: 2025/04/02 15:53:24 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_required;
	long			start_time;
	int				someone_died;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
}		t_data;

typedef struct s_philosopher
{
	int				id;
	long			last_meal_time;
	int				meals_eaten;
	pthread_t		thread;
	pthread_mutex_t	meal_mutex;
	t_data			*data;
}		t_philosopher;

int		init_data(t_data *data, int ac, char **av);
void	init_philosophers(t_philosopher *philos, t_data *data);
int		init_mutexes(t_data *data);

int		create_threads(t_philosopher *philos, t_data *data);
void	join_threads(t_philosopher *philos, t_data *data);
void	*philosopher_routine(void *arg);

void	philo_eat(t_philosopher *philo);
void	philo_sleep(t_philosopher *philo);
void	philo_think(t_philosopher *philo);

int		take_forks(t_philosopher *philo);
void	release_forks(t_philosopher *philo);

void	monitor_philosophers(t_philosopher *philos, t_data *data);
int		check_death(t_data *data);

long	get_time_ms(void);
void	precise_sleep(long milliseconds);

int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
void	print_state(t_philosopher *philo, char *state);
void	free_resources(t_philosopher *philos, t_data *data);

#endif
