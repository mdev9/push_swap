/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:21:58 by marde-vr          #+#    #+#             */
/*   Updated: 2024/01/20 13:55:19 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stacks *stacks)
{
	t_stack *node1;
	t_stack *node2;

	node1 = stacks->a;
	while (node1->next != stacks->a)
		node1 = node1->next;
	node2 = stacks->b;
	while (node2->next != stacks->b)
		node2 = node2->next;
	node2->next = 
	node1->next = node2;

}

void	pb(t_stacks *stacks);
