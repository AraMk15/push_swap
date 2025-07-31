/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:07:47 by armkrtch          #+#    #+#             */
/*   Updated: 2025/07/26 19:07:49 by armkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_small(t_stack *stack)
{
	int	size;
	int	min_idx;

	size = stack_size(stack->a);
	if (size == 2 && (stack->a->value > stack->a->next->value))
		sa(stack);
	else if (size == 3)
		sort_three(stack);
	else if (size > 3)
	{
		while (stack_size(stack->a) > 3)
		{
			min_idx = find_min(stack->a);
			move_to_top(stack->a, min_idx, stack);
			pb(stack);
		}
		sort_three(stack);
		while (stack->b)
			pa(stack);
	}
}
