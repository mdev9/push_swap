/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:22:24 by marde-vr          #+#    #+#             */
/*   Updated: 2024/01/24 10:15:08 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a)
{
	*stack_a = (*stack_a)->next;
	ft_printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	*stack_b = (*stack_b)->next;
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*last;

	last = *stack_a;
	*stack_a = last->next;
	last = *stack_b;
	*stack_b = last->next;
	ft_printf("rrr\n");
}
