/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:45:08 by marde-vr          #+#    #+#             */
/*   Updated: 2024/01/22 10:48:26 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*top_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != *stack)
		stack = stack->next;
	return (stack);
}

void	push_swap(t_stack *a, t_stack *b)
{
	t_stack	*node;
	int lowest_cost;
	int	curr_cost;

	if (stack_size(a) < 6)
		return ;
	pb(a, b);
	pb(a, b);
	node = *a;
	lowest_cost = calculate_cost(node, b);
	while (stack_size(a) != 3 && node->next != *a)
	{
		node = node->next;
		curr_cost = calculate_cost(node, b);
		if (curr_cost < lowest_cost || curr_cost == 1)
			push_node(node, a, b);
	}

	/*
	while (*a != 0)
	{
		first_a = top_node(a);
		first_b = top_node(b);
		if (first_a->value > first_b->value || first_a < *b->value)
		{
			pb(a, b);
			if (first_a->value < *b->value)
				rb(b);

		}
	}*/
	return ;
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = 0;
	stack_b = 0;
	if (parse_argv(argc, argv, &stack_a))
		return (ft_error(stack_a, stack_b));
	ft_printf("stack_a: ");
	print_stack(stack_a);
	// push_swap(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
