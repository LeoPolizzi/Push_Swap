/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:45:01 by lpolizzi          #+#    #+#             */
/*   Updated: 2024/11/02 20:42:16 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	find_min_node(t_stack_pair **stacks, int *min_value, int *min_pos)
{
	t_stack	*current;
	int		stack_size;
	int		i;

	current = (*stacks)->a;
	*min_value = current->content;
	*min_pos = 0;
	i = 0;
	stack_size = get_stack_size((*stacks)->a);
	while (i < stack_size)
	{
		if (current->content < *min_value)
		{
			*min_value = current->content;
			*min_pos = i;
		}
		current = current->next;
		i++;
	}
}

static void	rotate_to_top(t_stack_pair **stacks, int min_pos, t_op_list **list)
{
	int	stack_size;

	stack_size = get_stack_size((*stacks)->a);
	if (min_pos <= stack_size / 2)
	{
		while (min_pos-- > 0)
			ra(stacks, list);
	}
	else
	{
		while (min_pos++ < stack_size)
			rra(stacks, list);
	}
}

void	put_in_order(t_stack_pair **stacks, t_op_list **list)
{
	int	min_value;
	int	min_pos;

	if (!(*stacks) || !(*stacks)->a || !(*stacks)->a->next)
		return ;
	find_min_node(stacks, &min_value, &min_pos);
	rotate_to_top(stacks, min_pos, list);
}

int	main(int ac, char **av)
{
	t_stack_pair	*stacks;
	t_op_list		*list;

	if (ac < 2)
		exit(EXIT_FAILURE);
	stacks = malloc(sizeof(t_stack_pair));
	if (!stacks)
		return (EXIT_FAILURE);
	stacks->a = NULL;
	stacks->b = NULL;
	list = NULL;
	init_stack(&stacks, ac, av);
	sort(&stacks, &list);
	put_in_order(&stacks, &list);
	print_op_list(list);
	free_all(&stacks, &list);
	return (EXIT_SUCCESS);
}
