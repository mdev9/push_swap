/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:45:08 by marde-vr          #+#    #+#             */
/*   Updated: 2024/01/19 17:11:09 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack_node	*node;

	if (!stack->first)
		return ;
	node = stack->first;
	while (node->next && stack->first != node->next)
	{
		ft_printf("%d, ", node->value);
		node = node->next;
	}
	ft_printf("%d\n", node->value);
}

int	ft_error(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("Error\n");
	free(stack_a);
	free(stack_b);
	return (0);
}

void	push_swap(t_stack *a, t_stack *b)
{
	(void)(a);
	(void)(b);
	return ;
}

void	free_stack(t_stack *stack)
{
	t_stack_node	*node;
	t_stack_node	*tmp;
	t_stack_node	*first;

	if (stack->first)
	{
		first = stack->first;
		node = first->next;
		while (node->next && node != first)
		{
			tmp = node->next;
			free(node);
			node = tmp;
		}
		free(first);
	}
	free(stack);
}

int	main(int argc, char **argv)
{
	int		error;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = ft_calloc(1, sizeof(t_stack));
	stack_b = ft_calloc(1, sizeof(t_stack));
	if (!stack_a || !stack_b)
		return (ft_error(stack_a, stack_b));
	error = parse_argv(argc, argv, stack_a);
	if (error)
		return (ft_error(stack_a, stack_b));
	print_stack(stack_a);
	//push_swap(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
