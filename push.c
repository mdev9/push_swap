/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:21:58 by marde-vr          #+#    #+#             */
/*   Updated: 2024/01/21 19:30:28 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *first_a;
	t_stack *first_b;
	t_stack	*tmp;

	if (stack_size(stack_b) == 0)
		return ;
	first_a = *stack_a;
	while (first_a->next != *stack_a)
		first_a = first_a->next;
	tmp = *stack_b;
	while (tmp->next->next != *stack_b)
		tmp = tmp->next;
	first_b = tmp->next;
	tmp->next = *stack_b;
	first_a = first_b;
	first_a->next = *stack_a;
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *first_a;
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	if (stack_size(stack_a) == 0)
		return ;
	tmp_a = *stack_a;
	while (tmp_a->next->next != *stack_a)
		tmp_a = tmp_a->next;
	first_a = tmp_a->next;
	tmp_a->next = *stack_a;
	if (*stack_b)
	{
		tmp_b = *stack_b;
		while (tmp_b->next->next != *stack_b)
			tmp_b = tmp_b->next;
		tmp_b->next = first_a;
	}
	else
	{
		tmp_b = first_a;
		*stack_b = tmp_b;
	}
	tmp_b->next = *stack_b;
}
