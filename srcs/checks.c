/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 23:39:14 by lpolizzi          #+#    #+#             */
/*   Updated: 2024/10/30 22:26:19 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	check_dupes(t_stack *stack)
{
	t_stack	*outer;
	t_stack	*inner;

	if (!stack || !stack->next)
		return ;
	outer = stack;
	while (outer)
	{
		inner = outer->next;
		while (inner)
		{
			if (outer->content == inner->content)
			{
				error_msg(NULL, stack, NULL);
				return ;
			}
			inner = inner->next;
		}
		outer = outer->next;
	}
}

int	is_arg_valid(const int ac, const char *arg)
{
	size_t	i;
	long	atol;

	i = 0;
	if (ac == 2)
	{
		while ((arg[i] >= '0' && arg[i] <= '9') || arg[i] == ' '
			|| arg[i] == '-' || arg[i] == '+')
			i++;
	}
	else
	{
		while ((arg[i] >= '0' && arg[i] <= '9') || arg[i] == '-'
			|| arg[i] == '+')
			i++;
	}
	if (i == ft_strlen(arg))
	{
		atol = ft_atol(arg);
		if (atol >= INT_MIN && atol <= INT_MAX)
			return (1);
	}
	return (0);
}
