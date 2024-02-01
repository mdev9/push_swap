/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:49:01 by marde-vr          #+#    #+#             */
/*   Updated: 2024/02/01 17:36:32 by marde-vr         ###   ########.fr       */
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

int	create_node_from_str(char *str, t_stack **a)
{
	t_stack	*node;
	int		nb;

	if (check_if_str_is_valid(str))
		return (1);
	nb = ft_atoi(str);
	if (nb > 2147483647 || nb < -2147483648)
		return (1);
	if (!*a)
	{
		new_node(nb, a);
		if (!a)
			return (1);
	}
	else
	{
		node = *a;
		while (node->next)
			node = node->next;
		new_node(nb, &node->next);
		if (!node->next)
			return (1);
	}
	return (0);
}

int	fill_stack(char **char_tab, t_stack **a)
{
	int		i;

	if (!char_tab)
		return (1);
	i = 0;
	while (char_tab[i])
		i++;
	i--;
	while (i >= 0)
	{
		if (create_node_from_str(char_tab[i], a))
			return (1);
		i--;
	}
	return (0);
}

int	add_arg_to_stack(char *arg, t_stack **a)
{
	char	**char_tab;
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
	if (fill_stack(char_tab, a))
		return (free_tabs(char_tab, 1));
	return (free_tabs(char_tab, 0));
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
