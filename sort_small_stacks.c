/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:41:47 by marde-vr          #+#    #+#             */
/*   Updated: 2024/02/01 19:33:57 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_min(t_stack *stack) // remove ?
{
	t_stack	*node;

	node = stack;
	while (node->next->value < node->value)
		node = node->next;
	return (node);
}

t_stack	*stack_max(t_stack *stack) // remove ?
{
	t_stack	*node;

	node = stack;
	while (node->next->value > node->value)
		node = node->next;
	return (node);
}

void	sort_stack_of_size_3(t_stack **stack_a)
{
	int	first;
	int	second;
	int	last;

	first = (*stack_a)->next->next->value;
	second = (*stack_a)->next->value;
	last = (*stack_a)->value;
	if (first < second && second > last && last > first)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first > second && second > last && last < first)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && second < last && last > first)
		sa(stack_a);
	else if (first > second && second < last && last < first)
		ra(stack_a);
	else if (first < second && second > last && last < first)
		rra(stack_a);
}

void	sort_small_stack(t_stack **a, t_stack **b)
{
	while (stack_size(a) != 3)
		pb(a, b);
	sort_stack_of_size_3(a);
	print_stacks(*a, *b);
	while ((top_node(*a)->value < top_node(*b)->value) || (top_node(*a) != stack_min(*a) && *a != stack_max(*a)))
		ra(a);
	print_stacks(*a, *b);
	pa(a, b);
	if (*b)
	{
		while (!stack_is_sorted(*a))
			ra(a);
		while ((top_node(*a)->value < top_node(*b)->value) || (top_node(*a) != stack_min(*a) && *a != stack_max(*a)))
			ra(a);
		print_stacks(*a, *b);
		pa(a, b);
		print_stacks(*a, *b);
	}
	while (!stack_is_sorted(*a))
		ra(a);
}
