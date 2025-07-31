/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:08:23 by armkrtch          #+#    #+#             */
/*   Updated: 2025/07/26 19:08:27 by armkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	handle_case_2(t_stack *stack, int first, int second, int third)
{
	if (first > second && second > third)
	{
		sa(stack);
		rra(stack);
	}
}

void	handle_case_4(t_stack *stack, int first, int second, int third)
{
	if (first < second && first < third)
	{
		sa(stack);
		ra(stack);
	}
}

void	sort_three(t_stack *stack)
{
	t_node	*a;
	int		first;
	int		second;
	int		third;

	a = stack->a;
	first = a->value;
	second = a->next->value;
	third = a->next->next->value;
	if (first < second && second < third)
		return ;
	if (first > second && second < third && first < third)
		sa(stack);
	else if (first > second && second > third)
		handle_case_2(stack, first, second, third);
	else if (first > second && first > third)
		ra(stack);
	else if (first < second && first < third)
		handle_case_4(stack, first, second, third);
	else
		rra(stack);
}
