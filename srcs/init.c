/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:03:43 by lpolizzi          #+#    #+#             */
/*   Updated: 2024/11/02 21:29:24 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

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
		error_msg(stacks, NULL);
	while (nums[i])
	{
		if (!is_arg_valid(ac, nums[i]))
		{
			free_split(nums);
			error_msg(stacks, NULL);
			return ;
		}
		ft_add_to_stack_linear(&((*stacks)->a), ft_atoi(nums[i]));
		i++;
	}
	free_split(nums);
}

static void	process_multiple_args(t_stack_pair **stacks, const int ac,
		char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_arg_valid(ac, av[i]))
			error_msg(stacks, NULL);
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
	check_dupes(stacks);
	make_circular_stack((*stacks)->a);
}
