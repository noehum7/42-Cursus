/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:22:57 by nporras-          #+#    #+#             */
/*   Updated: 2025/04/02 15:56:15 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	precise_sleep(long milliseconds)
{
	long	start_time;
	long	elapsed;

	start_time = get_time_ms();
	while (1)
	{
		elapsed = get_time_ms() - start_time;
		if (elapsed >= milliseconds)
			break ;
		usleep(100);
	}
}
