/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:21:23 by marde-vr          #+#    #+#             */
/*   Updated: 2024/01/21 22:25:37 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_duplicates(t_stack *stack)
{
	t_stack	*node1;
	t_stack	*node2;

	if (!stack)
		return (0);
	node1 = stack;
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
