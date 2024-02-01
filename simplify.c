/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:46:34 by marde-vr          #+#    #+#             */
/*   Updated: 2024/02/01 18:06:38 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tab[j] > tab[i])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	copy_stack_to_sorted_tab(t_stack **a, int *tab, int size)
{
	t_stack	*node;
	int		i;

	i = 0;
	node = *a;
	while (node->next != *a)
	{
		tab[i] = node->value;
		node = node->next;
		i++;
	}
	tab[i] = node->value;
	sort_tab(tab, size);
}

void	replace_stack_values(t_stack **a, int *tab, int size)
{
	t_stack	*node;
	int		i;
	int		j;

	i = 0;
	node = *a;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (node->value == tab[j])
			{
				node->value = j;
				break ;
			}
			j++;
		}
		node = node->next;
		i++;
	}
}

int	simplify_stack(t_stack **a)
{
	int	*tmp;
	int	size;

	size = stack_size(a);
	tmp = calloc(size, sizeof(int *));
	if (!tmp)
		return (1);
	copy_stack_to_sorted_tab(a, tmp, size);
	replace_stack_values(a, tmp, size);
	free(tmp);
	return (0);
}
