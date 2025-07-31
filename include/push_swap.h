/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:05:41 by armkrtch          #+#    #+#             */
/*   Updated: 2025/07/26 19:05:46 by armkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../Libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*a;
	t_node	*b;
}	t_stack;

// operations
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

// utils
long	ft_atoi(const char *str);
int		stack_size(t_node *node);
int		find_min(t_node *stack);
void	move_to_top(t_node *stack, int idx, t_stack *s);
t_node	*create_node(int value);
void	node_add_back(t_node **stack, int value);
int		is_sorted(t_node *node);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
int		is_valid_number(const char *str);
int		has_duplicate(t_node *stack, int value);
void	assign_indices(t_stack *stack);
int		get_max_bits(int max_index);
int		handle_input_errors(t_stack *stacks, const char *arg, long num);
void	handle_case_2(t_stack *stack, int first, int second, int third);
void	handle_case_4(t_stack *stack, int first, int second, int third);
void	process_bit_iteration(t_stack *stack, int bit, int size);
void	process_single_arg(t_stack *stacks, char *arg_str);
void	process_multiple_args(t_stack *stacks, int argc, char **argv);
char	**split_and_validate_input_string(t_stack *stacks, char *arg_str);
void	process_single_number_node(t_stack *stacks, char *number_str);

//main functions
void	sort_three(t_stack *stack);
t_stack	*parse_input(int argc, char **argv);
void	sort_small(t_stack *stack);
void	radix_sort(t_stack *stack);
void	free_stack(t_node *stack);

#endif
