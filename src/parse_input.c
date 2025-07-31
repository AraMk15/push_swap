/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:04:27 by armkrtch          #+#    #+#             */
/*   Updated: 2025/07/26 19:04:31 by armkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	handle_input_errors(t_stack *stacks, const char *arg, long num)
{
	if (!is_valid_number(arg))
	{
		free_stack(stacks->a);
		free(stacks);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	if (num < INT_MIN || num > INT_MAX)
	{
		free_stack(stacks->a);
		free(stacks);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	if (has_duplicate(stacks->a, (int)num))
	{
		free_stack(stacks->a);
		free(stacks);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return (1);
}

void	process_single_arg(t_stack *stacks, char *arg_str)
{
	char	**numbers_arr;
	int		j;

	numbers_arr = split_and_validate_input_string(stacks, arg_str);
	j = 0;
	while (numbers_arr[j])
	{
		process_single_number_node(stacks, numbers_arr[j]); // Use helper 2
		j++;
	}
	free(numbers_arr);
}

void	process_multiple_args(t_stack *stacks, int argc, char **argv)
{
	int		i;
	long	num;

	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		handle_input_errors(stacks, argv[i], num);
		node_add_back(&stacks->a, num);
		i++;
	}
}

t_stack	*parse_input(int argc, char **argv)
{
	t_stack	*stacks;

	stacks = malloc(sizeof(t_stack));
	if (!stacks)
		exit(1);
	stacks->a = NULL;
	stacks->b = NULL;
	if (argc == 2)
		process_single_arg(stacks, argv[1]);
	else
		process_multiple_args(stacks, argc, argv);
	return (stacks);
}
