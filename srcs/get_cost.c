/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:54:10 by lpolizzi          #+#    #+#             */
/*   Updated: 2024/10/30 22:34:56 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	calculate_cost(int pos, int stack_size)
{
	int	forward_moves;
	int	backward_moves;

	if (stack_size <= 0)
		return (0);
	forward_moves = pos;
	backward_moves = -(stack_size - pos);
	if (forward_moves <= ABS(backward_moves))
		return (forward_moves);
	else
		return (backward_moves);
}

void	get_cost(t_stack_pair **stacks)
{
	t_stack	*curr_a;
	int		stack_size_a;
	int		stack_size_b;

	if (!stacks || !*stacks || !(*stacks)->a || !(*stacks)->b)
		return ;
	stack_size_a = get_stack_size((*stacks)->a);
	stack_size_b = get_stack_size((*stacks)->b);
	curr_a = (*stacks)->a;
	while (1)
	{
		curr_a->cost_a = calculate_cost(curr_a->pos, stack_size_a);
		if (curr_a->target_pos >= 0 && curr_a->target_pos < stack_size_b)
			curr_a->cost_b = calculate_cost(curr_a->target_pos, stack_size_b);
		else
			curr_a->cost_b = 0;
		curr_a = curr_a->next;
		if (curr_a == (*stacks)->a)
			break ;
	}
}

t_stack	*get_lowest_cost_node(t_stack *stack)
{
	t_stack	*curr;
	t_stack	*lowest_cost_node;

	if (!stack)
		return (NULL);
	curr = stack->next;
	lowest_cost_node = stack;
	while (curr != stack)
	{
		if (abs(curr->cost_a)
			+ abs(curr->cost_b) < abs(lowest_cost_node->cost_a)
			+ abs(lowest_cost_node->cost_b))
			lowest_cost_node = curr;
		curr = curr->next;
	}
	return (lowest_cost_node);
}
