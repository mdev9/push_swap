/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:49:01 by marde-vr          #+#    #+#             */
/*   Updated: 2024/01/21 22:26:43 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	new_node(int value, t_stack **new)
{
	t_stack	*node;

	*new = ft_calloc(1, sizeof(t_stack));
	if (!new)
		return (1);
	node = *new;
	node->value = value;
	return (0);
}

int	fill_stack(int *tab, t_stack **a)
{
	int		i;
	t_stack	*node;

	if (!tab)
		return (1);
	i = -1;
	while (tab[++i])
	{
		if (!*a)
		{
			new_node(tab[i], a);
			if (!a)
				return (1);
		}
		else
		{
			node = *a;
			while (node->next)
				node = node->next;
			new_node(tab[i], &node->next);
			if (!node->next)
				return (1);
		}
	}
	return (0);
}

int	add_arg_to_stack(char *arg, t_stack **a)
{
	char	**char_tab;
	int		*int_tab;
	int		size;

	char_tab = ft_split(arg, ' ');
	size = 0;
	while (char_tab[size])
		size++;
	if (!char_tab)
		return (1);
	if (!*char_tab)
	{
		free(char_tab);
		return (0);
	}
	int_tab = ft_calloc(size + 1, sizeof(int *));
	if (!int_tab)
		return (free_tabs(char_tab, int_tab, 1));
	if (convert_to_int(char_tab, int_tab))
		return (free_tabs(char_tab, int_tab, 1));
	if (fill_stack(int_tab, a))
		return (free_tabs(char_tab, int_tab, 1));
	return (free_tabs(char_tab, int_tab, 0));
}

int	parse_argv(int argc, char **argv, t_stack **a)
{
	int		i;
	t_stack	*node;

	i = argc - 1;
	while (i > 0)
	{
		if (add_arg_to_stack(argv[i], a))
			return (1);
		i--;
	}
	if (*a)
	{
		if (check_for_duplicates(*a))
			return (1);
		node = *a;
		while (node->next)
			node = node->next;
		node->next = *a;
	}
	return (0);
}
