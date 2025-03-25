/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:46:58 by nporras-          #+#    #+#             */
/*   Updated: 2025/03/13 12:45:11 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	abs_val(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	find_min_index_pos(t_stack *stack)
{
	t_node	*current;
	int		min_index;
	int		min_pos;
	int		pos;

	min_index = INT_MAX;
	min_pos = 0;
	pos = 0;
	current = stack->top;
	while (current)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
			min_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (min_pos);
}

static int	calculate_cost(t_stack *a, t_stack *b, int pos_b)
{
	int		cost_a;
	int		cost_b;
	int		target_pos;
	t_node	*node_b;

	node_b = get_node_at_position(b, pos_b);
	if (!node_b)
		return (INT_MAX);
	target_pos = find_target_pos(a, node_b->index);
	if (pos_b <= b->size / 2)
		cost_b = pos_b;
	else
		cost_b = -(b->size - pos_b);
	if (target_pos <= a->size / 2)
		cost_a = target_pos;
	else
		cost_a = -(a->size - target_pos);
	return (abs_val(cost_a) + abs_val(cost_b));
}

int	find_target_pos(t_stack *a, int b_index)
{
	t_node	*current;
	int		target_index;
	int		target_pos;

	target_index = INT_MAX;
	target_pos = 0;
	current = a->top;
	while (current)
	{
		if (current->index > b_index && current->index < target_index)
		{
			target_index = current->index;
			target_pos = get_position(a, current);
		}
		current = current->next;
	}
	if (target_index == INT_MAX)
		return (find_min_index_pos(a));
	return (target_pos);
}

int	find_best_move(t_stack *a, t_stack *b)
{
	int	min_cost;
	int	min_pos;
	int	i;
	int	current_cost;

	min_cost = INT_MAX;
	min_pos = 0;
	i = 0;
	while (i < b->size)
	{
		current_cost = calculate_cost(a, b, i);
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			min_pos = i;
		}
		i++;
	}
	return (min_pos);
}
