/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:49:01 by marde-vr          #+#    #+#             */
/*   Updated: 2024/01/18 20:04:10 by marde-vr         ###   ########.fr       */
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
			tmp->prev = tmp;
			tmp->value = tab[i];
			a->first = tmp;
			a->last = tmp;
		}
		else
		{
			a->last->next = ft_calloc(1, sizeof(t_stack_node));
			a->last->next->prev = a->last;
			a->last->next->value = tab[i];
			a->last = a->last->next;
		}
	}
	return (0);
}

int	add_arg_to_stack(char *arg, t_stack *a)
{
	char	**char_tab;
	int		*int_tab;
	int		error;

	char_tab = ft_split(arg, ' ');
	if (!char_tab)
		return (1);
	if (!*char_tab)
		return (0);
	int_tab = ft_calloc(1, sizeof(int *));
	error = convert_to_int(char_tab, int_tab);
	if (error)
		return (error);
	error = fill_stack(int_tab, a);
	if (error)
		return (error);
	return (0);
}

int	parse_argv(int argc, char **argv, t_stack *a)
{
	int	i;
	int	error;

	i = argc - 1;
	while (i > 0)
	{
		error = add_arg_to_stack(argv[i], a);
		if (error)
			return (error);
		i--;
	}
	//check if there are any duplicates in stack
	//todo
	return (0);
}
