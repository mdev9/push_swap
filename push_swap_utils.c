/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:29:04 by marde-vr          #+#    #+#             */
/*   Updated: 2024/01/22 21:36:34 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack	*node;

	if (!stack)
		return ;
	node = stack;
	while (node->next && stack != node->next)
	{
		ft_printf("%d, ", node->value);
		node = node->next;
	}
	ft_printf("%d\n", node->value);
}

int	stack_size(t_stack **stack)
{
	int		size;
	t_stack	*node;

	if (!*stack)
		return (0);
	node = *stack;
	size = 1;
	while (node->next != *stack)
	{
		size++;
		node = node->next;
	}
	return (size);
}

void	free_stack(t_stack *stack)
{
	t_stack	*node;
	t_stack	*tmp;

	if (!stack)
		return ;
	if (!stack->next)
		free(stack);
	else
	{
		node = stack->next;
		while (node->next && node != stack)
		{
			tmp = node->next;
			free(node);
			node = tmp;
		}
		if (node != stack)
			free(node);
		free(stack);
	}
}

int	ft_error(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("Error\n");
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

int	stack_is_sorted(t_stack *stack)
{
	t_stack *node;

	node = stack;
	while (node->next != stack)
	{
		if (node->next->value > node->value)
			return (0);
		node = node->next;
	}
	return (1);
}
