/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 22:32:31 by lpolizzi          #+#    #+#             */
/*   Updated: 2024/10/30 22:34:30 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	error_msg(t_stack_pair **stacks, t_op_list **list)
{
	ft_putendl_fd("Error", 2);
	free_all(stacks, list);
	exit(1);
}
