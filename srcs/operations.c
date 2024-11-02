/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:09:00 by lpolizzi          #+#    #+#             */
/*   Updated: 2024/10/30 15:34:41 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	add_op(t_op_list **list, const char *operation)
{
	t_op_list	*new_node;
	t_op_list	*current;

	new_node = malloc(sizeof(t_op_list));
	if (!new_node)
		return ;
	new_node->operation = ft_strdup(operation);
	if (!new_node->operation)
	{
		free(new_node);
		return ;
	}
	new_node->next = NULL;
	if (*list == NULL)
		*list = new_node;
	else
	{
		current = *list;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}

void	print_op_list(t_op_list *list)
{
	t_op_list	*current;

	current = list;
	while (current)
	{
		ft_putendl_fd(current->operation, 1);
		current = current->next;
	}
}
