/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operat_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:08:54 by armkrtch          #+#    #+#             */
/*   Updated: 2025/07/26 19:20:54 by armkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa(t_stack *stack)
{
	t_node	*tmp;

	if (!stack->b)
		return ;
	tmp = stack->b;
	stack->b = stack->b->next;
	tmp->next = stack->a;
	stack->a = tmp;
	ft_putstr_fd("pa\n", 1);
}

void	ra(t_stack *stack)
{
	t_node	*firts;
	t_node	*last;

	if (!stack->a || !stack->a->next)
		return ;
	firts = stack->a;
	stack->a = stack->a->next;
	firts->next = NULL;
	last = stack->a;
	while (last->next)
		last = last->next;
	last->next = firts;
	ft_putstr_fd("ra\n", 1);
}

void	rra(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack->a || !stack->a->next)
		return ;
	prev = NULL;
	last = stack->a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->a;
	stack->a = last;
	ft_putstr_fd("rra\n", 1);
}

void	sa(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack->a || !(stack->a->next))
		return ;
	first = stack->a;
	second = stack->a->next;
	first->next = second->next;
	second->next = first;
	stack->a = second;
	ft_putstr_fd("sa\n", 1);
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
	ft_putstr_fd("rrr\n", 1);
}
