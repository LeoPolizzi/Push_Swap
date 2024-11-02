/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:23:43 by lpolizzi          #+#    #+#             */
/*   Updated: 2024/11/02 21:29:12 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_stack	*remove_top_node(t_stack **stack)
{
	t_stack	*top_node;

	if (*stack == NULL)
		return (NULL);
	top_node = *stack;
	if ((*stack)->next == *stack)
		*stack = NULL;
	else
	{
		*stack = (*stack)->next;
		(*stack)->prev = top_node->prev;
		top_node->prev->next = *stack;
	}
	top_node->prev = top_node;
	top_node->next = top_node;
	return (top_node);
}

static void	insert_node_top(t_stack **dest, t_stack *node)
{
	if (*dest == NULL)
	{
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->next = *dest;
		node->prev = (*dest)->prev;
		(*dest)->prev->next = node;
		(*dest)->prev = node;
	}
	*dest = node;
}

static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*node;

	node = remove_top_node(src);
	if (node)
		insert_node_top(dest, node);
}

void	pa(t_stack_pair **stacks, t_op_list **list)
{
	push(&(*stacks)->b, &(*stacks)->a);
	add_op(list, "pa");
}

void	pb(t_stack_pair **stacks, t_op_list **list)
{
	push(&(*stacks)->a, &(*stacks)->b);
	add_op(list, "pb");
}
