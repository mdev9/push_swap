/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:45:08 by marde-vr          #+#    #+#             */
/*   Updated: 2024/01/28 12:40:50 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*top_node(t_stack *stack)
{
	t_stack	*top_node;

	if (!stack)
		return (NULL);
	top_node = stack;
	while (top_node->next != stack)
		top_node = top_node->next;
	return (top_node);
}

t_stack	*stack_min(t_stack *stack)
{
	t_stack	*node;

	node = stack;
	while (node->next->value < node->value)
		node = node->next;
	return (node);
}

t_stack	*stack_max(t_stack *stack)
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
		print_stack(*stack_a);
		ra(stack_a);
	}
	else if (first > second && second > last && last < first)
	{
		sa(stack_a);
		print_stack(*stack_a);
		rra(stack_a);
	}
	else if (first > second && second < last && last > first)
		sa(stack_a);
	else if (first > second && second < last && last < first)
		ra(stack_a);
	else if (first < second && second > last && last < first)
		rra(stack_a);
}

/*
int	calc_rotations(t_stack *stack, int value)
{
	t_stack	*node;
	int		i;

	i = 0;
	node = stack;
	while (node->value != value)
	{
		node = node->next;
		i++;
	}
	return (stack_size(&stack) - i);
}

int	total_cost(int a, int b)
{
	int	cost;

	cost = 1;
	if (a > b)
		cost += a - b;
	else if (a < b)
		cost += a + b;
	return (cost);
}

int	calculate_cost(int node_i, t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*node;
	int		min;
	int		max;
	int		i;

	i = 0;
	node = stack_a;
	while (i < node_i)
	{
		node = node->next;
		i++;
	}
	min = stack_min(stack_b)->value;
	max = stack_max(stack_b)->value;
	if (node->value > max || node->value < min)
		return (total_cost(calc_rotations(stack_a, node->value),
				calc_rotations(stack_b, max)));
	return (1);
}

t_stack	*first(t_stack *stack)
{
	t_stack	*first;

	first = stack;
	while (first->next != stack)
		first = first->next;
	return (first);
}

void	empty_b(t_stack **a, t_stack **b)
{
	int	first_a;
	int	first_b;

	
	first_a = first(*a)->value;
	first_b = first(*b)->value;
	while (stack_size(b))
	{
		while (first_a < first_b && first_b )
		{
			rra(a);
			first_a = first(*a)->value;
			first_b = first(*b)->value;
			ft_printf("first_a: %d, first_b: %d\n", first_a, first_b);
			print_stacks(*a, *b);
		}
		pa(a, b);
		print_stacks(*a, *b);
		//pa(a, b);
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	lowest_cost;
	int	curr_cost;
	int	i;

	pb(a, b);
	print_stacks(*a, *b);
	pb(a, b);
	print_stacks(*a, *b);
	lowest_cost = calculate_cost(stack_size(a), *a, *b);
	while (stack_size(a) > 3)
	{
		i = stack_size(a);
		while (i > 0)
		{
			curr_cost = calculate_cost(i, *a, *b);
			ft_printf("i: %d, cost: %d\n", i, curr_cost);
			if (curr_cost < lowest_cost)
				lowest_cost = curr_cost;
			if (curr_cost == 1)
				break ;
			i--;
		}
		//push_to_b(node, a, b);
	}
	if (!stack_is_sorted(*a))
	{
		if (stack_size(a) == 2)
			sa(a);
		else
			sort_stack_of_size_3(a);
		print_stacks(*a, *b);
	}
	empty_b(a, b);
}
*/

void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;
	int	max_num;
	int	max_bits;
	int	i;
	int	j;
	int	num;

	size = stack_size(a);
	max_num = size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		++max_bits;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			num = top_node(*a)->value;
			if (((num >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			print_stacks(*a, *b);
			j++;
		}
		i++;
	}
	while (*b)
	{
		pa(a, b);
		print_stacks(*a, *b);
	}
}

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
	else
		sort_stack(a, b);
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
	print_stack(stack_a);
	ft_printf("stack sorted: %d\n", stack_is_sorted(stack_a));
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
