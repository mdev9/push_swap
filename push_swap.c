/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:45:08 by marde-vr          #+#    #+#             */
/*   Updated: 2024/01/17 15:39:13 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void print_stack(t_stack *stack)
{
	t_stack_node *node;

	node = stack->first;
	while (node->next && stack->first != node->next)
	{
		ft_printf("%d", node->value);
		node = node->next;
	}
}

void	push_swap(t_stack *a, t_stack *b)
{
	(void)(a);
	(void)(b);
	return ;
}

int	main(int argc, char **argv)
{
	int error;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = ft_calloc(1, sizeof(t_stack));
	stack_b = ft_calloc(1, sizeof(t_stack));
	if (!stack_a || !stack_b)
		return (ft_error(1));
	error = parse_argv(argc, argv, stack_a);
	if (error)
		return (ft_error(error));
	print_stack(stack_a);
	//push_swap(stack_a, stack_b);
	return (0);
}
