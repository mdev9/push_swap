/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:45:08 by marde-vr          #+#    #+#             */
/*   Updated: 2024/01/21 20:32:38 by marde-vr         ###   ########.fr       */
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

void	push_swap(t_stack *a, t_stack *b)
{
	(void)(a);
	(void)(b);
	return ;
}

int	stack_size(t_stack **stack)
{
	int		size;
	t_stack *node;

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

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = 0;
	stack_b = 0;
	if (parse_argv(argc, argv, &stack_a))
		return (ft_error(stack_a, stack_b));
	ft_printf("stack_a: ");
	print_stack(stack_a);
	//pa(&stack_a, &stack_b);
	ft_printf("pb\n");
	//ft_printf("pb\n");
	//pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	ft_printf("stack_a: ");
	print_stack(stack_a);
	ft_printf("stack_b: ");
	print_stack(stack_b);
	//push_swap(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
