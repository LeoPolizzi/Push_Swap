/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:03:43 by lpolizzi          #+#    #+#             */
/*   Updated: 2024/10/30 22:38:41 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static char	**ft_splitargs(const int ac, const char *str, char c)
{
	if (is_arg_valid(ac, str))
		return (ft_split(str, c));
	else
		return (NULL);
}

static void	process_single_arg(t_stack_pair **stacks, const int ac, char **av)
{
	char	**nums;
	int		i;

	i = 0;
	nums = ft_splitargs(ac, av[1], ' ');
	if (!nums)
		error_msg((*stacks)->a, NULL, NULL);
	while (nums[i])
	{
		if (!is_arg_valid(ac, nums[i]))
			error_msg((*stacks)->a, NULL, NULL);
		ft_add_to_stack_linear(&((*stacks)->a), ft_atoi(nums[i]));
		i++;
	}
	free(nums);
}

static void	process_multiple_args(t_stack_pair **stacks, const int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_arg_valid(ac, av[i]))
			error_msg((*stacks)->a, NULL, NULL);
		ft_add_to_stack_linear(&((*stacks)->a), ft_atoi(av[i]));
		i++;
	}
}

void	init_stack(t_stack_pair **stacks, int ac, char **av)
{
	if (ac == 2)
		process_single_arg(stacks, ac, av);
	else
		process_multiple_args(stacks, ac, av);
	check_dupes((*stacks)->a);
	make_circular_stack((*stacks)->a);
}

