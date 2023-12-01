/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:45:08 by marde-vr          #+#    #+#             */
/*   Updated: 2023/11/28 17:22:36 by marde-vr         ###   ########.fr       */
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

int	*expand_tab(int *tab_dest, char **tab_src)
{
	int	i;
	int	j;
	int	tab_dest_len;
	int	tab_src_len;
	int	*tab;

	tab_dest_len = tab_dest[0];
	tab_src_len = ft_atoi(tab_src[0]);
	tab = malloc(tab_src_len + tab_dest_len * sizeof(int));
	if (!tab)
		return (NULL);
	ft_memcpy(tab, tab_dest, tab_dest_len);
	i = tab_dest_len;
	j = 1;
	while (/*i <= tab_src_len + tab_dest_len*/ j <= tab_dest_len)
	{
		tab[i] = ft_atoi(tab_src[j]);
		i++;
		j++;
	}
	free(tab_dest);
	free(tab_src);
	return (tab);
}

int	*split_argv(int argc, char **argv)
{
	int	*tab;
	int	i;

	tab = malloc(sizeof(int) * argc);
	if (!tab)
		return (NULL);
	tab[0] = argc - 1;
	i = 1;
	while (i < argc)
	{
		expand_tab(tab, ft_split(argv[i], ' '));
		i++;
	}
	return (tab);
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
