/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:21:23 by marde-vr          #+#    #+#             */
/*   Updated: 2024/02/02 15:34:09 by marde-vr         ###   ########.fr       */
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

int	free_tab(char **char_tab, int error)
{
	int	i;

	i = 0;
	while (char_tab[i])
	{
		free(char_tab[i]);
		i++;
	}
	free(char_tab);
	return (error);
}

int	check_if_str_is_valid(char *str)
{
	int	i;
	int	passed_first_digit;
	int	previous_is_digit;

	i = -1;
	passed_first_digit = 0;
	previous_is_digit = 0;
	while (str[++i])
	{
		if (!(ft_isdigit(str[i]) || str[i] == '-' || str[i] == '+'))
			return (1);
		if (ft_isdigit(str[i]) && !passed_first_digit)
			passed_first_digit = 1;
		if (passed_first_digit && (str[i] == '-' || str[i] == '+'))
			return (1);
		if (str[i] == ' ')
			passed_first_digit = 0;
		if ((str[i] == '-' || str[i] == '+') && previous_is_digit)
			return (1);
		if (str[i] == '-' || str[i] == '+')
			previous_is_digit = 1;
		else
			previous_is_digit = 0;
	}
	return (0);
}
