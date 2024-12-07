/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:04:46 by lpolizzi          #+#    #+#             */
/*   Updated: 2024/11/02 20:42:37 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft.h"
# include <stdio.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# define A_TO_B 1
# define B_TO_A 0

typedef struct s_stack
{
	struct s_stack		*prev;
	int					content;
	int					pos;
	int					target_pos;
	int					cost_a;
	int					cost_b;
	struct s_stack		*next;
}						t_stack;

typedef struct s_stack_pair
{
	struct s_stack		*a;
	struct s_stack		*b;
}						t_stack_pair;

typedef struct s_op_list
{
	char				*operation;
	struct s_op_list	*next;
}						t_op_list;

// Check for duplicate elements in the stack
void					check_dupes(t_stack_pair **stacks);

// Check if the given argument is valid
int						is_arg_valid(int ac, const char *arg);

// Calculate the cost of moving an element to the top
int						calculate_cost(int pos, int stack_size);

// Calculate the cost for each element in the stack
void					get_cost(t_stack_pair **stacks);

// Find the node with the lowest cost
t_stack					*get_lowest_cost_node(t_stack *stack);

// Set the position of each element in the stack
void					get_pos(t_stack_pair **stacks);

// Determine the target node for each element in stack `a`
void					get_target_node(t_stack_pair **stacks);

// Initialize the stack with input arguments
void					init_stack(t_stack_pair **stacks, int ac, char **av);

// Main sorting function
void					sort(t_stack_pair **stacks, t_op_list **list);

// Add an operation to the operation list
void					add_op(t_op_list **list, const char *operation);

// Print the list of operations
void					print_op_list(t_op_list *list);

// Push an element from source stack to destination stack
void					pa(t_stack_pair **stacks, t_op_list **list);
void					pb(t_stack_pair **stacks, t_op_list **list);

// Rotate stack `a` or `b`
void					ra(t_stack_pair **stacks, t_op_list **list);
void					rb(t_stack_pair **stacks, t_op_list **list);
void					rr(t_stack_pair **stacks, t_op_list **list);

// Reverse rotate stack `a` or `b`
void					rra(t_stack_pair **stacks, t_op_list **list);
void					rrb(t_stack_pair **stacks, t_op_list **list);
void					rrr(t_stack_pair **stacks, t_op_list **list);

// Perform moves to push the node with lowest cost
void					do_moves(t_stack *node, t_stack_pair **stacks,
							t_op_list **list, int direction);

// Push all elements from stack `b` back to stack `a`
void					push_back_to_a(t_stack_pair **stacks, t_op_list **list);

// Add an element to a linear stack
void					ft_add_to_stack_linear(t_stack **stack, int content);

// Add an element to a circular stack
void					ft_add_to_stack_circular(t_stack **stack, int content);

// Make the stack circular by linking last and first elements
void					make_circular_stack(t_stack *stack);

// Get the size of the stack
int						get_stack_size(t_stack *stack);

// Swap the top two elements of stack `a` or `b`
void					sa(t_stack_pair **stacks, t_op_list **list);
void					sb(t_stack_pair **stacks, t_op_list **list);
void					ss(t_stack_pair **stacks, t_op_list **list);

// Gets the absolute value of an integer
int						ft_abs(int n);

// Convert string to long integer
long					ft_atol(const char *nptr);

// Display error message and free all resources
void					error_msg(t_stack_pair **stacks, t_op_list **list);

// Free all stacks and operation list
void					free_all(t_stack_pair **stacks, t_op_list **list);

#endif
