/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:22:24 by marde-vr          #+#    #+#             */
/*   Updated: 2024/01/21 22:04:35 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a)
{
	t_stack	*last;

	last = *stack_a;
	*stack_a = last->next;
	ft_printf("rra	stack_a: ");
	print_stack(*stack_a);
}

void	rrb(t_stack **stack_b)
{
	t_stack	*last;

	last = *stack_b;
	*stack_b = last->next;
	ft_printf("rrb	stack_b: ");
	print_stack(*stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
