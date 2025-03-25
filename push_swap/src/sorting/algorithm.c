/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:47:13 by nporras-          #+#    #+#             */
/*   Updated: 2025/03/13 12:46:28 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_large(t_stack *a, t_stack *b)
{
	int	best_pos;

	assign_indices(a);
	move_to_b(a, b);
	sort_three(a);
	while (b->size > 0)
	{
		best_pos = find_best_move(a, b);
		execute_move(a, b, best_pos);
	}
	move_position_to_top(a, find_min_position(a));
}

void	sort_stacks(t_stack *a, t_stack *b)
{
	if (a->size <= 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_five(a, b);
	else
		sort_large(a, b);
}
