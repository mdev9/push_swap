/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:45:08 by marde-vr          #+#    #+#             */
/*   Updated: 2024/01/22 21:38:56 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*top_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != stack)
		stack = stack->next;
	return (stack);
}

t_stack	*stack_min(t_stack *stack)
{
	t_stack *node;

	node = stack;
	while (node->next->value < node->value)
		node = node->next;
	return (node);
}

t_stack	*stack_max(t_stack *stack)
{
	t_stack *node;

	node = stack;
	while (node->next->value > node->value)
		node = node->next;
	return (node);
}

void	sort_stack_of_size_3(t_stack **stack_a)
{
	t_stack *a;
	int first;
	int second;
	int last;

	a = *stack_a;
	first = a->next->next->value;
	second = a->next->value;
	last = a->value;
	if (first < second && second > last && last > first)
	{
		sa(&a);
		ra(&a);
	}
	else if (first > second && second > last && last < first)
	{
		sa(&a);
		rra(&a);
	}
	else if (first > second && second < last && last > first)
		sa(&a);
	else if (first > second && second < last && last < first)
		ra(&a);
	else if (first < second && second > last && last < first)
		rra(&a);
}

/*
int	calculate_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *first_a;
	t_stack *min;
	t_stack *max;

	first_a = top_node(stack_a);
	min = stack_min(stack_b);
	max = stack_max(stack_b);
	if (first_a->value > max->value || first_a->value < min->value)
		return (1);
	return (1);
}

void	push_node(t_stack *node, t_stack **stack_a, t_stack **stack_b)
{
	t_stack *top
}

void	sort_stack(t_stack **a, t_stack **b)
{
	t_stack	*node;
	int lowest_cost;
	int	curr_cost;

	pb(a, b);
	pb(a, b);
	lowest_cost = calculate_cost(node, *b);
	while (stack_size(a) == 3)
	{
		node = *a;
		while (node->next != *a)
		{
			node = node->next;
			curr_cost = calculate_cost(node, *b);
			if (curr_cost < lowest_cost || curr_cost == 1)
				push_node(node, a, b);
		}
	}
	sort_stack_of_size_3(a);
}*/

void	push_swap(t_stack **a, t_stack **b)
{
	if (stack_is_sorted(*a))
		return ;
	if (stack_size(a) == 2)
	{
		sa(a);
		return ;
	}
	if (stack_size(a) == 3)
	{
		sort_stack_of_size_3(a);
		return ;
	}
	//else
	//	sort_stack(a, b);
	(void)b;
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = 0;
	stack_b = 0;
	if (parse_argv(argc, argv, &stack_a))
		return (ft_error(stack_a, stack_b));
	ft_printf("a: ");
	print_stack(stack_a);
	ft_printf("stack sorted: %d\n", stack_is_sorted(stack_a));
	push_swap(&stack_a, &stack_b);
	ft_printf("stack sorted: %d\n", stack_is_sorted(stack_a));
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
