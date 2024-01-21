/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:22:04 by marde-vr          #+#    #+#             */
/*   Updated: 2024/01/21 22:07:20 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a)
{
	t_stack	*first;

	first = *stack_a;
	while (first->next != *stack_a)
		first = first->next;
	*stack_a = first;
	ft_printf("ra	stack_a: ");
	print_stack(*stack_a);
}

void	rb(t_stack **stack_b)
{
	t_stack	*first;

	first = *stack_b;
	while (first->next != *stack_b)
		first = first->next;
	*stack_b = first;
	ft_printf("rb	stack_b: ");
	print_stack(*stack_b);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
