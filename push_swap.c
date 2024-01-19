/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:45:08 by marde-vr          #+#    #+#             */
/*   Updated: 2024/01/19 19:25:56 by marde-vr         ###   ########.fr       */
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
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = 0;
	stack_b = ft_calloc(1, sizeof(t_stack));
	if (!stack_b)
		return (ft_error(stack_a, stack_b));
	if (parse_argv(argc, argv, stack_a))
		return (ft_error(stack_a, stack_b));
	print_stack(stack_a);
	//push_swap(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
