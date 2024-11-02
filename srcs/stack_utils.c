/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:34:35 by lpolizzi          #+#    #+#             */
/*   Updated: 2024/10/28 20:52:14 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_add_to_stack_linear(t_stack **stack, int content)
{
	t_stack	*new_node;
	t_stack	*current;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->content = content;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = new_node;
	new_node->prev = current;
}

void	ft_add_to_stack_circular(t_stack **stack, int content)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->content = content;
	new_node->next = new_node;
	new_node->prev = new_node;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	last = *stack;
	while (last->next != *stack)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
	new_node->next = *stack;
	(*stack)->prev = new_node;
}

void	make_circular_stack(t_stack *stack)
{
	t_stack	*first;

	if (!stack)
		return ;
	first = stack;
	while (stack->next)
		stack = stack->next;
	stack->next = first;
	first->prev = stack;
}

int	get_stack_size(t_stack *stack)
{
	int		size;
	t_stack	*curr;

	if (!stack)
		return (0);
	size = 1;
	curr = stack->next;
	while (curr != stack)
	{
		size++;
		curr = curr->next;
	}
	return (size);
}
