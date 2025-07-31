/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:05:08 by armkrtch          #+#    #+#             */
/*   Updated: 2025/07/26 19:05:12 by armkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stacks;

	if (argc < 2)
		return (0);
	stacks = parse_input(argc, argv);
	if (!stacks || !stacks->a || is_sorted(stacks->a))
	{
		if (stacks)
		{
			free_stack(stacks->a);
			free_stack(stacks->b);
			free(stacks);
		}
		return (0);
	}
	if (stack_size(stacks->a) == 2)
		sort_small(stacks);
	else if (stack_size(stacks->a) == 3)
		sort_three(stacks);
	else if (stack_size(stacks->a) <= 5)
		sort_small(stacks);
	else
		radix_sort(stacks);
	return (free_stack(stacks->a), free_stack(stacks->b), free(stacks), 0);
}
