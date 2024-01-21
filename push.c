/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:21:58 by marde-vr          #+#    #+#             */
/*   Updated: 2024/01/21 20:56:39 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b);

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *first_a;
	t_stack	*first_b;
	t_stack	*tmp;

	if (stack_size(stack_a) == 0)
		return ;
	tmp = *stack_a;
	while (tmp->next->next != *stack_a)
		tmp = tmp->next;
	first_a = tmp->next;
	tmp->next = *stack_a;
	if (*stack_b)
	{
		first_b = *stack_b;
		while (first_b->next->next != *stack_b)
			first_b = first_b->next;
		first_a->next = *stack_b;
		first_b->next = first_a;
	}
	else
	{
		first_b = first_a;
		*stack_b = first_b;
		first_b->next = *stack_b;
	}
	tmp = *stack_a;
	if (tmp->value == first_b->value)
		*stack_a = 0;
}
