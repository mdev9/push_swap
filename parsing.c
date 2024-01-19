/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:49:01 by marde-vr          #+#    #+#             */
/*   Updated: 2024/01/19 17:45:26 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	check_if_str_is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) || str[i] == '-'))
			return (1);
		i++;
	}
	return (0);
}

int	convert_to_int(char **char_tab, int *int_tab)
{
	int			i;
	int			j;
	long long	nb;

	if (!char_tab || !int_tab)
		return (1);
	i = 0;
	while (char_tab[i])
		i++;
	i--;
	j = 0;
	while (i >= 0)
	{
		if (check_if_str_is_valid(char_tab[i]))
			return (1);
		nb = ft_atoi(char_tab[i]);
		if (nb > 2147483647 || nb < -2147483648)
			return (1);
		int_tab[j] = nb;
		i--;
		j++;
	}
	return (0);
}

int	fill_stack(int *tab, t_stack *a)
{
	int				i;
	t_stack_node	*tmp;

	if (!tab || !a)
		return (1);
	i = -1;
	while (tab[++i])
	{
		if (!a->first)
		{
			tmp = ft_calloc(1, sizeof(t_stack_node));
			if (!tmp)
				return (1);
			tmp->prev = tmp;
			tmp->value = tab[i];
			a->first = tmp;
			a->last = tmp;
		}
		else
		{
			a->last->next = ft_calloc(1, sizeof(t_stack_node));
			if (!a->last->next)
				return (1);
			a->last->next->prev = a->last;
			a->last->next->value = tab[i];
			a->last = a->last->next;
		}
	}
	return (0);
}

int	free_tabs(char **char_tab, int *int_tab, int error)
{
	int	i;

	i = 0;
	while (char_tab[i])
	{
		free(char_tab[i]);
		i++;
	}
	free(char_tab);
	free(int_tab);
	return (error);
}

int	add_arg_to_stack(char *arg, t_stack *a)
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

int	check_for_duplicates(t_stack *stack)
{
	t_stack_node	*node1;
	t_stack_node	*node2;

	node1 = stack->first;
	while (node1->next)
	{
		node2 = node1->next;
		while (node2->next)
		{
			if (node1->value == node2->value)
				return (1);
			node2 = node2->next;
		}
		if (node1->value == node2->value)
			return (1);
		node1 = node1->next;
	}
	return (0);
}

int	parse_argv(int argc, char **argv, t_stack *a)
{
	int				i;
	t_stack_node	*node;

	i = argc - 1;
	while (i > 0)
	{
		if (add_arg_to_stack(argv[i], a))
			return (1);
		i--;
	}
	if (a->first)
	{
		if (check_for_duplicates(a))
			return (1);
		node = a->first;
		while (node->next)
			node = node->next;
		node->next = a->first;
	}
	return (0);
}
