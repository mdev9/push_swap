/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:45:08 by marde-vr          #+#    #+#             */
/*   Updated: 2024/02/01 18:20:51 by marde-vr         ###   ########.fr       */
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

void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;
	int	num;
	int	i;
	int	j;

	size = stack_size(a);
	i = 0;
	while (!stack_is_sorted(*a))
	{
		j = 0;
		while (j < size)
		{
			num = top_node(*a)->value;
			if ((num >> i) & 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		i++;
		while (*b)
		{
			pa(a, b);
		}
	}
}

void	push_swap(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(a);
	if (stack_is_sorted(*a))
		return ;
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_stack_of_size_3(a);
	else if (size == 4 || size == 5)
		sort_small_stack(a, b);
	else
		sort_stack(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = 0;
	stack_b = 0;
	if (parse_argv(argc, argv, &stack_a))
		return (ft_error(stack_a, stack_b));
	//ft_printf("a: ");
	//print_stack(stack_a);
	//ft_printf("stack sorted: %d\n", stack_is_sorted(stack_a));
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
