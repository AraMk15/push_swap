/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:06:16 by armkrtch          #+#    #+#             */
/*   Updated: 2025/07/26 19:07:00 by armkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	process_bit_iteration(t_stack *stack, int bit, int size)
{
	int	pushed;
	int	i;

	pushed = 0;
	i = 0;
	while (i < size)
	{
		if (((stack->a->index >> bit) & 1) == 0)
		{
			pb(stack);
			pushed++;
		}
		else
			ra(stack);
		i++;
	}
	while (pushed > 0)
	{
		pa(stack);
		pushed--;
	}
}

void	radix_sort(t_stack *stack)
{
	int	size;
	int	max_bits;
	int	bit;

	bit = 0;
	size = stack_size(stack->a);
	max_bits = get_max_bits(size - 1);
	assign_indices(stack);
	while (bit < max_bits)
	{
		process_bit_iteration(stack, bit, size);
		bit++;
	}
}
