/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:08:57 by lpolizzi          #+#    #+#             */
/*   Updated: 2024/10/31 13:08:58 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*temp;

	if (!stack || !*stack)
		return ;
	current = *stack;
	current->prev->next = NULL;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*stack = NULL;
}

static void	free_op_list(t_op_list **list)
{
	t_op_list	*current;
	t_op_list	*temp;

	if (!list || !*list)
		return ;
	current = *list;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp->operation);
		free(temp);
	}
	*list = NULL;
}

void	free_all(t_stack_pair *stacks, t_op_list **list)
{
	free_stack(&(stacks->a));
	free_stack(&(stacks->b));
	free_op_list(list);
}
