/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:31:45 by lpolizzi          #+#    #+#             */
/*   Updated: 2024/10/30 15:30:15 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	int		temp;

	if (*stack == NULL || (*stack)->next == *stack)
		return ;
	first = *stack;
	second = first->next;
	temp = first->content;
	first->content = second->content;
	second->content = temp;
}

void	sa(t_stack_pair **stacks, t_op_list **list)
{
	swap(&(*stacks)->a);
	add_op(list, "sa");
}

void	sb(t_stack_pair **stacks, t_op_list **list)
{
	swap(&(*stacks)->b);
	add_op(list, "sb");
}

void	ss(t_stack_pair **stacks, t_op_list **list)
{
	swap(&(*stacks)->a);
	swap(&(*stacks)->b);
	add_op(list, "ss");
}
