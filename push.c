/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:21:58 by marde-vr          #+#    #+#             */
/*   Updated: 2024/02/01 18:31:46 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack, t_stack *first_1)
{
	t_stack	*first_2;

	if (*stack)
	{
		first_2 = *stack;
		while (first_2->next->next != *stack)
			first_2 = first_2->next;
		first_2 = first_2->next;
		first_1->next = *stack;
		first_2->next = first_1;
	}
	else
	{
		first_2 = first_1;
		*stack = first_2;
		first_2->next = *stack;
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first_b;
	t_stack	*tmp;
	int		size;

	size = stack_size(stack_b);
	if (!size)
		return ;
	tmp = *stack_b;
	while (tmp->next->next != *stack_b)
		tmp = tmp->next;
	first_b = tmp->next;
	tmp->next = *stack_b;
	push(stack_a, first_b);
	/*
	if (*stack_a)
	{
		first_a = *stack_a;
		while (first_a->next->next != *stack_a)
			first_a = first_a->next;
		first_a = first_a->next;
		first_b->next = *stack_a;
		first_a->next = first_b;
	}
	else
	{
		first_a = first_b;
		*stack_a = first_a;
		first_a->next = *stack_a;
	}*/
	if (size == 1)
		*stack_b = 0;
	ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first_a;
	t_stack	*tmp;
	int		size;

	size = stack_size(stack_a);
	if (!size)
		return ;
	tmp = *stack_a;
	while (tmp->next->next != *stack_a)
		tmp = tmp->next;
	first_a = tmp->next;
	tmp->next = *stack_a;
	push(stack_b, first_a);
	/*
	if (*stack_b)
	{
		first_b = top_node(*stack_b);
		first_a->next = *stack_b;
		first_b->next = first_a;
	}
	else
	{
		first_b = first_a;
		*stack_b = first_b;
		first_b->next = *stack_b;
	}*/
	if (size == 1)
		*stack_a = 0;
	ft_printf("pb\n");
}
