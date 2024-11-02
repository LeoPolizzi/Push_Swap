/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:23:43 by lpolizzi          #+#    #+#             */
/*   Updated: 2024/10/31 13:09:11 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = *src;
	if ((*src)->next == *src)
		*src = NULL;
	else
	{
		*src = (*src)->next;
		(*src)->prev = tmp->prev;
		tmp->prev->next = *src;
	}
	if (*dest == NULL)
	{
		tmp->next = tmp;
		tmp->prev = tmp;
	}
	else
	{
		tmp->next = *dest;
		tmp->prev = (*dest)->prev;
		(*dest)->prev->next = tmp;
		(*dest)->prev = tmp;
	}
	*dest = tmp;
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
