/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:10:45 by nporras-          #+#    #+#             */
/*   Updated: 2025/03/13 12:42:07 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_node_at_position(t_stack *stack, int pos)
{
	t_node	*current;
	int		i;

	if (pos < 0 || pos >= stack->size)
		return (NULL);
	current = stack->top;
	i = 0;
	while (current && i < pos)
	{
		current = current->next;
		i++;
	}
	return (current);
}

int	get_position(t_stack *stack, t_node *node)
{
	t_node	*current;
	int		pos;

	pos = 0;
	current = stack->top;
	while (current && current != node)
	{
		pos++;
		current = current->next;
	}
	if (!current)
		return (-1);
	return (pos);
}

int	get_value_at(t_stack *stack, int pos)
{
	t_node	*node;

	node = get_node_at_position(stack, pos);
	if (node)
		return (node->value);
	return (0);
}

void	move_position_to_top(t_stack *stack, int pos)
{
	int	moves;

	if (pos <= stack->size / 2)
	{
		moves = pos;
		while (moves--)
			ra(stack);
	}
	else
	{
		moves = stack->size - pos;
		while (moves--)
			rra(stack);
	}
}

int	find_min_position(t_stack *stack)
{
	t_node	*current;
	int		min_val;
	int		min_pos;
	int		current_pos;

	current = stack->top;
	min_val = current->value;
	min_pos = 0;
	current_pos = 0;
	current = current->next;
	while (current)
	{
		current_pos++;
		if (current->value < min_val)
		{
			min_val = current->value;
			min_pos = current_pos;
		}
		current = current->next;
	}
	return (min_pos);
}
