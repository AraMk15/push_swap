/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:12:45 by armkrtch          #+#    #+#             */
/*   Updated: 2025/07/26 19:22:57 by armkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_node *node)
{
	while (node && node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	assign_indices(t_stack *stack)
{
	t_node	*current_a;
	t_node	*compare;
	int		index;

	current_a = stack->a;
	while (current_a)
	{
		index = 0;
		compare = stack->a;
		while (compare)
		{
			if (compare->value < current_a->value)
				index++;
			compare = compare->next;
		}
		current_a->index = index;
		current_a = current_a->next;
	}
}

int	get_max_bits(int max_index)
{
	int	bits;

	bits = 0;
	while (max_index > 0)
	{
		max_index >>= 1;
		bits++;
	}
	return (bits);
}
