/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:21:53 by marde-vr          #+#    #+#             */
/*   Updated: 2024/01/21 18:40:05 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_big_stack(t_stack **stack) {
  t_stack *first;
  t_stack *second;
  t_stack *last;
  t_stack *tmp;

  tmp = *stack;
  while (tmp->next->next->next != *stack) {
    tmp = tmp->next;
  }
  last = *stack;
  second = tmp->next;
  first = tmp->next->next;
  first->next = last->next;
  second->next = last;
  last->next = first;
  *stack = first;
}

void swap(t_stack **stack) {
  t_stack *first;
  t_stack *second;
  int size;

  size = stack_size(stack);
  if (size < 2)
    return;
  else if (size == 2) {
    second = *stack;
    first = second->next;
    first->next = second;
    *stack = first;
  } else {
    swap_big_stack(stack);
  }
}

void sa(t_stack **stack_a) { swap(stack_a); }

void sb(t_stack **stack_b) { swap(stack_b); }

void ss(t_stack **stack_a, t_stack **stack_b) {
  sa(stack_a);
  sb(stack_b);
}
