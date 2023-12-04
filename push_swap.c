/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:45:08 by marde-vr          #+#    #+#             */
/*   Updated: 2023/12/02 23:15:57 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

#include <stdio.h> // REMOVE THIS

void	push_swap(t_stack *a)
{
	(void)(a);
	return ;
}

t_stack	*stack_init(int stack_len, int *tab)
{
	t_stack			*stack_a;
	t_stack_node	*current;
	int				i;

	stack_a = new_stack();
	stack_a->bottom = new_node(tab[0]);
	printf("%d ", tab[0]);
	i = 1;
	current = stack_a->bottom;
	while (i < stack_len)
	{
		printf("%d ", tab[i]);
		current->next = new_node(tab[i]);
		i++;
	}
	stack_a->top = current;
	return (stack_a);
}


int *split_argv(int argc, char**argv)
{
    int *tab;

    tab = ft_split(argv, " ");

    return ()
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	int		*tab;

	tab = split_argv(argc, argv);
	stack = stack_init(argc, tab);
	push_swap(stack);
	return (0);
}
