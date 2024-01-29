/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:45:08 by marde-vr          #+#    #+#             */
/*   Updated: 2024/01/29 16:33:21 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*top_node(t_stack *stack)
{
	t_stack	*top_node;

	if (!stack)
		return (0);
	top_node = stack;
	while (top_node->next != stack)
		top_node = top_node->next;
	return (top_node);
}

t_stack	*stack_min(t_stack *stack)
{
	t_stack	*node;

	if (!stack)
		return (0);
	node = stack;
	while (node->next->value < node->value)
		node = node->next;
	return (node);
}

t_stack	*stack_max(t_stack *stack)
{
	t_stack	*node;

	if (!stack)
		return (0);
	node = stack;
	while (node->next->value > node->value)
		node = node->next;
	return (node);
}

void	sort_stack_of_size_3(t_stack **a)
{
	int	first;
	int	second;
	int	last;

	first = (*a)->next->next->value;
	second = (*a)->next->value;
	last = (*a)->value;
	if (first < second && second > last && last > first)
	{
		sa(a);
		print_stack(*a);
		ra(a);
	}
	else if (first > second && second > last && last < first)
	{
		sa(a);
		print_stack(*a);
		rra(a);
	}
	else if (first > second && second < last && last > first)
		sa(a);
	else if (first > second && second < last && last < first)
		ra(a);
	else if (first < second && second > last && last < first)
		rra(a);
}

int	rotations_to_top_count(int number, t_stack *stack)
{
	int		count;
	t_stack	*current;

	count = 0;
	current = stack;
	while (current && ((current->value < number
				&& current->next->value > number)
			|| (current->value > current->next->value
				&& (number > current->value || number < current->next->value))))
	{
		current = current->next;
		count++;
	} //change this bs
	return (count);
}

int	calculate_cost(int number, t_stack *a, t_stack *b)
{
	int	rotations_to_top_b;
	int	rotations_to_top_a;
	int	rr_count;

	rotations_to_top_b = rotations_to_top_count(number, b); // change those 2 lines
	rotations_to_top_a = rotations_to_top_count(number, a);
	rr_count = 0;
	ft_printf("cost to rotate %d to top of b is: %d\n", number, rotations_to_top_b);
	ft_printf("cost to rotate %d to top of a is: %d\n", number, rotations_to_top_a);
	while (rotations_to_top_a > 0 && rotations_to_top_b > 0)
	{
		rr_count++;
		rotations_to_top_a--;
		rotations_to_top_b--;
	}
	ft_printf("simultaneous rr's: %d, new ra: %d, new rb: %d\n", rr_count, rotations_to_top_a, rotations_to_top_b);
	return (rr_count + rotations_to_top_a + rotations_to_top_b + 1);
}

int	find_cheapest_number(t_stack **a, t_stack **b)
{
	int		cheapest_number;
	int		cheapest_cost;
	t_stack	*current;
	int		current_cost;

	cheapest_number = (*a)->value;
	cheapest_cost = calculate_cost((*a)->value, *a, *b);
	ft_printf("cost to push %d: %d\n\n", (*a)->value, cheapest_cost);
	current = (*a)->next;
	while (current != *a)
	{
		current_cost = calculate_cost(current->value, *a, *b);
		ft_printf("cost to push %d: %d\n\n", current->value, current_cost);
		if (current_cost < cheapest_cost)
		{
			cheapest_number = current->value;
			cheapest_cost = current_cost;
		}
		current = current->next;
	}
	ft_printf("cheapest number is %d with cost of %d\n", cheapest_number,
		cheapest_cost);
	return (cheapest_number);
}

void	push_cheapest_number(t_stack **a, t_stack **b)
{
	int	cheapest_number;

	cheapest_number = find_cheapest_number(a, b);
	while (*a && (*a)->value != cheapest_number && *b
		&& (*b)->value > cheapest_number)
	{
		rr(a, b);
		print_stacks(*a, *b);
	}
	while (*a && (*a)->value != cheapest_number)
	{
		ra(a);
		print_stacks(*a, *b);
	}
	while (*b && (*b)->value > cheapest_number)
	{
		rb(b);
		print_stacks(*a, *b);
	}
	pb(a, b);
	print_stacks(*a, *b);
}

void	push_back_to_a(t_stack **a, t_stack **b)
{
	int	rotations_needed;
	int	number;

	rotations_needed = 0;
	while (*b)
	{
		number = (*b)->value;
		rotations_needed = rotations_to_top_count(number, *a);
		while (rotations_needed > 0)
		{
			ra(a);
			print_stacks(*a, *b);
			rotations_needed--;
		}
		pa(a, b);
		print_stacks(*a, *b);
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	a_size;

	pb(a, b);
	print_stacks(*a, *b);
	pb(a, b);
	print_stacks(*a, *b);
	a_size = stack_size(a);
	while (a_size > 3)
	{
		push_cheapest_number(a, b);
		a_size--;
	}
	sort_stack_of_size_3(a);
	push_back_to_a(a, b);
	// bring minimim number of the stack at top;
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

// Todo:
//
// Fix algorithm
// Fix 0
