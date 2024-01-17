/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:49:01 by marde-vr          #+#    #+#             */
/*   Updated: 2024/01/17 15:52:13 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int convert_to_int(char **char_tab, int *int_tab)
{
	if (!char_tab || !int_tab)
		return (1);	
	//check if arguments are bigger than an integer
	//check if there are any duplicates

	int i = 0;
	int j = 0;
	while (char_tab[i])
	{
		j = 0;
		while (char_tab[i][j])
		{
			//check if arguments are all integers
			if (ft_isdigit(char_tab[i][j]) || char_tab[i][j] == '-')
				return (ft_error(2));
			j++;
		}
		int_tab[i] = ft_atoi(char_tab[i]);
	}

	return (0);
}

int	fill_stack(int *tab, t_stack *a)
{
	if (!tab || !a)
		return (1);
	int i = 0;
	while (tab[i])
	{
		a->last->next = ft_calloc(1, sizeof(t_stack_node));
		a->last->next->prev = a->last;
		a->last->next->value = tab[i];
	}
	return (0);
}

int add_arg_to_stack(char *arg, t_stack *a)
{
	char	**char_tab;
	int		*int_tab;
	int		error;
	
	char_tab = ft_split(arg, ' ');
	if (!char_tab || !*char_tab)
		return (1);
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
	int		i;
	int		error;

	i = argc - 1;
	while (i > 1)
	{
		error = add_arg_to_stack(argv[i], a);
		if (error)
			return (error);
		i++;
	}
	return (0);
}
