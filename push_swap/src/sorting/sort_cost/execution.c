/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:47:02 by nporras-          #+#    #+#             */
/*   Updated: 2025/03/13 12:46:04 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_simultaneous_rotations(t_stack *a, t_stack *b, int *cost_a,
		int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

static void	execute_individual_rotations(t_stack *a, t_stack *b, int cost_a,
		int cost_b)
{
	while (cost_a > 0)
	{
		ra(a);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(a);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rb(b);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(b);
		cost_b++;
	}
}

static void	execute_rotate(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	execute_simultaneous_rotations(a, b, &cost_a, &cost_b);
	execute_individual_rotations(a, b, cost_a, cost_b);
}

void	move_to_b(t_stack *a, t_stack *b)
{
	int	size;
	int	mid_index;
	int	pushed;
	int	i;

	size = a->size;
	mid_index = size / 2;
	pushed = 0;
	i = 0;
	while (i < size && pushed < size - 3)
	{
		if (a->top->index <= mid_index)
		{
			pb(b, a);
			pushed++;
		}
		else
			ra(a);
		i++;
	}
	while (a->size > 3)
		pb(b, a);
}

void	execute_move(t_stack *a, t_stack *b, int pos_b)
{
	int		cost_a;
	int		cost_b;
	int		target_pos;
	t_node	*node_b;

	node_b = get_node_at_position(b, pos_b);
	if (!node_b)
		return ;
	target_pos = find_target_pos(a, node_b->index);
	if (pos_b <= b->size / 2)
		cost_b = pos_b;
	else
		cost_b = -(b->size - pos_b);
	if (target_pos <= a->size / 2)
		cost_a = target_pos;
	else
		cost_a = -(a->size - target_pos);
	execute_rotate(a, b, cost_a, cost_b);
	pa(a, b);
}
