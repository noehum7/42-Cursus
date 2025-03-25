/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:47:17 by nporras-          #+#    #+#             */
/*   Updated: 2025/03/13 12:47:40 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stack *a)
{
	if (a->size <= 1)
		return ;
	if (a->size == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(a);
		return ;
	}
}

void	sort_three(t_stack *a)
{
	int	values[3];

	if (a->size <= 2)
		return (sort_two(a));
	values[0] = get_value_at(a, 0);
	values[1] = get_value_at(a, 1);
	values[2] = get_value_at(a, 2);
	if (values[0] > values[1] && values[1] < values[2] && values[0] < values[2])
		sa(a);
	else if (values[0] > values[1] && values[1] > values[2])
	{
		sa(a);
		rra(a);
	}
	else if (values[0] > values[1] && values[0] > values[2])
		ra(a);
	else if (values[0] < values[1] && values[1] > values[2]
		&& values[0] < values[2])
	{
		sa(a);
		ra(a);
	}
	else if (values[0] < values[1] && values[1] > values[2])
		rra(a);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	min_pos;

	if (a->size <= 3)
	{
		sort_three(a);
		return ;
	}
	while (a->size > 3)
	{
		min_pos = find_min_position(a);
		move_position_to_top(a, min_pos);
		pb(b, a);
	}
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}
