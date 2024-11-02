/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:24:57 by lpolizzi          #+#    #+#             */
/*   Updated: 2024/10/30 22:17:02 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	sort_stack_of_three(t_stack_pair **stacks, t_op_list **list)
{
	int	top;
	int	mid;
	int	bot;

	top = (*stacks)->a->content;
	mid = (*stacks)->a->next->content;
	bot = (*stacks)->a->prev->content;
	if (top > mid && mid < bot && top < bot)
		sa(stacks, list);
	else if (top > mid && mid > bot)
	{
		sa(stacks, list);
		rra(stacks, list);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(stacks, list);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(stacks, list);
		ra(stacks, list);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(stacks, list);
}

static void	sort_small_stack(t_stack_pair **stacks, t_op_list **list)
{
	int	stack_size;

	stack_size = get_stack_size((*stacks)->a);
	if (stack_size == 2)
	{
		if ((*stacks)->a->content > (*stacks)->a->next->content)
			sa(stacks, list);
	}
	else if (stack_size == 3)
		sort_stack_of_three(stacks, list);
}

void	do_single_moves(t_stack_pair **stacks, int *moves_a, int *moves_b,
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

void	do_multiple_moves(t_stack_pair **stacks, int *moves_a, int *moves_b,
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

void	push_back_to_a(t_stack_pair **stacks, t_op_list **list)
{
	int		stack_size;

	stack_size = get_stack_size((*stacks)->b);
	while (stack_size)
	{
		pa(stacks, list);
		stack_size = get_stack_size((*stacks)->b);
	}
}

void	sort(t_stack_pair **stacks, t_op_list **list)
{
	t_stack	*node_to_move;
	int		stack_size;

	stack_size = get_stack_size((*stacks)->a);
	if (stack_size <= 1)
		return ;
	if (stack_size <= 3)
		sort_small_stack(stacks, list);
	else
	{
		while (get_stack_size((*stacks)->a) > 3 && get_stack_size((*stacks)->b) < 2)
			pb(stacks, list);
		stack_size = get_stack_size((*stacks)->a);
		while (stack_size)
		{
			get_target_node(stacks);
			get_cost(stacks);
			node_to_move = get_lowest_cost_node((*stacks)->a);
			do_moves(node_to_move, stacks, list, A_TO_B);
			stack_size = get_stack_size((*stacks)->a);
		}
		push_back_to_a(stacks, list);
	}
}
