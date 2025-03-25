/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:47:30 by nporras-          #+#    #+#             */
/*   Updated: 2025/03/13 12:42:27 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	ft_atoi_safe(const char *str, int *num)
{
	long	result;
	int		i;
	int		sign;

	result = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX) || (sign == -1
				&& result > (long)INT_MAX + 1))
			return (0);
		i++;
	}
	*num = (int)(result * sign);
	return (1);
}

void	free_stack(t_stack *stack)
{
	t_node	*temp;

	while (stack->top)
	{
		temp = stack->top;
		stack->top = stack->top->next;
		free(temp);
	}
	stack->size = 0;
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	push(t_stack *stack, int value)
{
	t_node	*node;
	t_node	*temp;

	node = new_node(value);
	if (!stack->top)
		stack->top = node;
	else
	{
		temp = stack->top;
		while (temp->next)
			temp = temp->next;
		temp->next = node;
	}
	stack->size++;
}
