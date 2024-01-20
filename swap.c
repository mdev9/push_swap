/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:21:53 by marde-vr          #+#    #+#             */
/*   Updated: 2024/01/20 12:55:57 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack *node;
	t_stack	*third;
	t_stack *tmp;

	node = stack;
	while(node->next != stack && node->next->next != stack)
	{
		node = node->next;
	}
	third = node;
	second = node->next;
	first = node->next->next;

	tmp = first;
	first = second;
	second = tmp;

	first->next = second;
	second->next = stack;
	third->next = first;
}

void	sa(t_stacks *stacks)
{
	swap(stacks->a);
}

void	sb(t_stacks *stacks)
{
	swap(stacks->b);
}

void	ss(t_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
}
