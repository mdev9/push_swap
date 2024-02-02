/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:16:37 by marde-vr          #+#    #+#             */
/*   Updated: 2024/02/02 10:57:32 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

int		parse_argv(int argc, char **argv, t_stack **a);
int		ft_error(t_stack *stack_a, t_stack *stack_b);
int		check_for_duplicates(t_stack *stack);
int		stack_size(t_stack **stack);
int		stack_is_sorted(t_stack *stack);
int		free_tab(char **char_tab, int error);
t_stack	*top_node(t_stack *stack);
void	free_stack(t_stack *stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
int		check_if_str_is_valid(char *str);
void	sort_small_stack(t_stack **a, t_stack **b);
void	sort_stack_of_size_3(t_stack **stack_a);
int		simplify_stack(t_stack **a);

#endif
