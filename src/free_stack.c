/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:03:57 by armkrtch          #+#    #+#             */
/*   Updated: 2025/07/26 19:04:03 by armkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack(t_node *stack)
{
	t_node	*current;
	t_node	*tmp;

	current = stack;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
}

char	**split_and_validate_input_string(t_stack *stacks, char *arg_str)
{
	char	**numbers_arr;

	numbers_arr = ft_split(arg_str, ' ');
	if (!numbers_arr)
	{
		free(stacks);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	if (!numbers_arr[0])
	{
		free(numbers_arr);
		free(stacks);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return (numbers_arr);
}

void	process_single_number_node(t_stack *stacks, char *number_str)
{
	long	num;

	num = ft_atoi(number_str);
	handle_input_errors(stacks, number_str, num);
	node_add_back(&stacks->a, (int)num);
}
