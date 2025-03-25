/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:47:27 by nporras-          #+#    #+#             */
/*   Updated: 2025/03/13 12:41:37 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac < 2)
		return (0);
	if (!validate_input(av))
		ft_error();
	init_stack(&a);
	init_stack(&b);
	if (!process_args(&a, ac, av))
	{
		free_stack(&a);
		ft_error();
	}
	if (!is_sorted(&a))
		sort_stacks(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
