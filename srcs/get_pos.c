/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:22:51 by lpolizzi          #+#    #+#             */
/*   Updated: 2024/10/29 19:26:39 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	set_pos(t_stack *stack)
{
	t_stack	*curr;
	int		pos;

	if (!stack)
		return ;
	curr = stack;
	pos = 0;
	while (1)
	{
		curr->pos = pos;
		pos++;
		curr = curr->next;
		if (curr == stack)
			break ;
	}
}

void	get_pos(t_stack_pair **stacks)
{
	set_pos((*stacks)->a);
	set_pos((*stacks)->b);
}
