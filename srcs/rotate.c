/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:15:50 by lpolizzi          #+#    #+#             */
/*   Updated: 2024/10/30 15:29:59 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	rotate(t_stack **stack)
{
	if (*stack == NULL || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->next;
}

void	ra(t_stack_pair **stacks, t_op_list **list)
{
	rotate(&(*stacks)->a);
	add_op(list, "ra");
}

void	rb(t_stack_pair **stacks, t_op_list **list)
{
	rotate(&(*stacks)->b);
	add_op(list, "rb");
}

void	rr(t_stack_pair **stacks, t_op_list **list)
{
	rotate(&(*stacks)->a);
	rotate(&(*stacks)->b);
	add_op(list, "rr");
}
