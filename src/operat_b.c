/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operat_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:10:37 by armkrtch          #+#    #+#             */
/*   Updated: 2025/07/26 19:10:43 by armkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pb(t_stack *stack)
{
	t_node	*tmp;

	if (!stack->a)
		return ;
	tmp = stack->a;
	stack->a = stack->a->next;
	tmp->next = stack->b;
	stack->b = tmp;
	ft_putstr_fd("pb\n", 1);
}

void	rb(t_stack *stack)
{
	t_node	*firts;
	t_node	*last;

	if (!stack->b || !stack->b->next)
		return ;
	firts = stack->b;
	stack->b = stack->b->next;
	firts->next = NULL;
	last = stack->b;
	while (last->next)
		last = last->next;
	last->next = firts;
	ft_putstr_fd("rb\n", 1);
}

void	rrb(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack->b || !stack->b->next)
		return ;
	prev = NULL;
	last = stack->b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->b;
	stack->b = last;
	ft_putstr_fd("rrb\n", 1);
}

void	sb(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack->b || !(stack->b->next))
		return ;
	first = stack->b;
	second = stack->b->next;
	first->next = second->next;
	second->next = first;
	stack->b = second;
	ft_putstr_fd("sb\n", 1);
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
	ft_putstr_fd("rr\n", 1);
}
