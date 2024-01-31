/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:45:08 by marde-vr          #+#    #+#             */
/*   Updated: 2024/01/31 11:12:00 by marde-vr         ###   ########.fr       */
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

int	simplify_stack(t_stack **a)
{
	t_stack	*node;
	int		*tmp;
	int		size;
	int		i;
	int		j;

	size = stack_size(a);
	tmp = calloc(size, sizeof(int *));
	if (!tmp)
		return (1);
	i = 0;
	node = *a;
	while (node->next != *a)
	{
		tmp[i] = node->value;
		node = node->next;
		i++;
	}
	i = 0;
	node = *a;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (node->value == tmp[j])
			{
				node->value = j;
				break ;
			}
			j++;
		}
		node = node->next;
		i++;
	}
	free(tmp);
	return (0);
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
	{
		sort_stack(a, b);
	}
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
	if (simplify_stack(&stack_a))
		return (1);
	print_stack(stack_a);
	push_swap(&stack_a, &stack_b);
	print_stack(stack_a);
	ft_printf("stack sorted: %d\n", stack_is_sorted(stack_a));
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
