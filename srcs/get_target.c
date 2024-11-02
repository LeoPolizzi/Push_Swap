/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:10:27 by lpolizzi          #+#    #+#             */
/*   Updated: 2024/10/30 22:35:08 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_stack	*find_max_node(t_stack *b)
{
	t_stack	*curr_b;
	t_stack	*max_node;

	curr_b = b->next;
	max_node = b;
	while (curr_b != b)
	{
		if (curr_b->content > max_node->content)
			max_node = curr_b;
		curr_b = curr_b->next;
	}
	return (max_node);
}

static t_stack	*find_closest_smaller(t_stack *curr_a, t_stack *b)
{
	t_stack	*curr_b;
	t_stack	*closest_smaller;

	curr_b = b;
	closest_smaller = NULL;
	while (1)
	{
		if (curr_b->content < curr_a->content)
		{
			if (!closest_smaller || curr_b->content > closest_smaller->content)
				closest_smaller = curr_b;
		}
		curr_b = curr_b->next;
		if (curr_b == b)
			break ;
	}
	return (closest_smaller);
}

static t_stack	*determine_target_node(t_stack *curr_a, t_stack *b)
{
	t_stack	*closest_smaller;
	t_stack	*max_node;

	closest_smaller = find_closest_smaller(curr_a, b);
	max_node = find_max_node(b);
	if (closest_smaller)
		return (closest_smaller);
	return (max_node);
}

void	get_target_node(t_stack_pair **stacks)
{
	t_stack	*curr_a;
	t_stack	*curr_b;
	t_stack	*target;

	if (!(*stacks) || !(*stacks)->a || !(*stacks)->b)
		return ;
	get_pos(stacks);
	curr_a = (*stacks)->a;

	while (1)
	{
		target = determine_target_node(curr_a, (*stacks)->b);
		curr_a->target_pos = target->pos;
		curr_a = curr_a->next;
		if (curr_a == (*stacks)->a)
			break ;
	}

	curr_b = (*stacks)->b;
	while (1)
	{
		target = determine_target_node(curr_b, (*stacks)->a);
		curr_b->target_pos = target->pos;
		curr_b = curr_b->next;
		if (curr_b == (*stacks)->b)
			break ;
	}
}
