/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:45:45 by nporras-          #+#    #+#             */
/*   Updated: 2025/03/13 12:39:31 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}		t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}		t_stack;

void	init_stack(t_stack *stack);
t_node	*new_node(int value);

int		validate_input(char **av);
int		process_args(t_stack *a, int ac, char **av);

void	free_stack(t_stack *stack);
void	ft_error(void);
int		ft_atoi_safe(const char *str, int *num);
void	push(t_stack *stack, int value);
int		is_sorted(t_stack *stack);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *b, t_stack *a);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

t_node	*get_node_at_position(t_stack *stack, int pos);
int		get_position(t_stack *stack, t_node *node);
int		get_value_at(t_stack *stack, int pos);
void	move_position_to_top(t_stack *stack, int pos);
int		find_min_position(t_stack *stack);

void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);
void	sort_large(t_stack *a, t_stack *b);
void	sort_stacks(t_stack *a, t_stack *b);
void	assign_indices(t_stack *a);

int		find_target_pos(t_stack *a, int b_index);
int		find_best_move(t_stack *a, t_stack *b);
void	move_to_b(t_stack *a, t_stack *b);
void	execute_move(t_stack *a, t_stack *b, int pos_b);

#endif
