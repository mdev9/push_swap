/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:16:37 by marde-vr          #+#    #+#             */
/*   Updated: 2024/01/19 17:40:49 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*next;
	struct s_stack_node *prev;
}	t_stack_node;

typedef struct s_stack
{
	t_stack_node	*first;
	t_stack_node	*last;
}	t_stack;

int				parse_argv(int argc, char **argv, t_stack *a);
int				ft_error(t_stack *stack_a, t_stack *stack_b);

#endif
