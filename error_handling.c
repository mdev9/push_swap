/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:43:37 by marde-vr          #+#    #+#             */
/*   Updated: 2024/01/17 13:48:22 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_error(int error_code)
{
	char *msg = "";

	if (error_code == 1)
		msg = "A malloc has failed";
	if (error_code == 2)
		msg = "Some arguments aren't integers";
	if (error_code == 3)
		msg = "Some arguments are bigger than an integer";
	if (error_code == 4)
		msg = "Some arguments are duplicates";
	ft_printf("Error\n%s\n", msg);
	return (0);
}
