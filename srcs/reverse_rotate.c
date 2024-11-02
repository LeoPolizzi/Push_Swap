/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:49:54 by lpolizzi          #+#    #+#             */
/*   Updated: 2024/10/30 15:29:25 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	reverse_rotate(t_stack **stack)
{
	if (*stack == NULL || (*stack)->prev == *stack)
		return ;
	*stack = (*stack)->prev;
}

void	rra(t_stack_pair **stacks, t_op_list **list)
{
	reverse_rotate(&(*stacks)->a);
	add_op(list, "rra");
}

void	rrb(t_stack_pair **stacks, t_op_list **list)
{
	reverse_rotate(&(*stacks)->b);
	add_op(list, "rrb");
}

void	rrr(t_stack_pair **stacks, t_op_list **list)
{
	reverse_rotate(&(*stacks)->a);
	reverse_rotate(&(*stacks)->b);
	add_op(list, "rrr");
}
