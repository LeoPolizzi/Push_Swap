/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:42:55 by lpolizzi          #+#    #+#             */
/*   Updated: 2024/11/02 20:42:57 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	do_single_moves(t_stack_pair **stacks, int *moves_a, int *moves_b,
		t_op_list **list)
{
	if (*moves_a > 0)
	{
		ra(stacks, list);
		(*moves_a)--;
	}
	else if (*moves_a < 0)
	{
		rra(stacks, list);
		(*moves_a)++;
	}
	if (*moves_b > 0)
	{
		rb(stacks, list);
		(*moves_b)--;
	}
	else if (*moves_b < 0)
	{
		rrb(stacks, list);
		(*moves_b)++;
	}
}

static void	do_multiple_moves(t_stack_pair **stacks, int *moves_a, int *moves_b,
		t_op_list **list)
{
	if (*moves_a > 0 && *moves_b > 0)
	{
		rr(stacks, list);
		(*moves_a)--;
		(*moves_b)--;
	}
	else if (*moves_a < 0 && *moves_b < 0)
	{
		rrr(stacks, list);
		(*moves_a)++;
		(*moves_b)++;
	}
}

void	do_moves(t_stack *node, t_stack_pair **stacks, t_op_list **list,
		int direction)
{
	int	moves_a;
	int	moves_b;

	moves_a = node->cost_a;
	moves_b = node->cost_b;
	while (moves_a != 0 && moves_b != 0)
	{
		do_multiple_moves(stacks, &moves_a, &moves_b, list);
		if ((moves_a < 0 && moves_b > 0) || (moves_a > 0 && moves_b < 0))
			break ;
	}
	while (moves_a != 0 || moves_b != 0)
		do_single_moves(stacks, &moves_a, &moves_b, list);
	if (direction == A_TO_B)
		pb(stacks, list);
	else if (direction == B_TO_A)
		pa(stacks, list);
}
