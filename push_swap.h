/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavast <rchavast@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-05-18 16:17:43 by rchavast          #+#    #+#             */
/*   Updated: 2026-05-18 16:17:43 by rchavast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
} t_stack;

/* main */
int		parse_args(t_stack **a, int ac, char **av);

/* parsing */
int		parse_number(char *str, int *nbr);
int		has_duplicate(t_stack *a, int value);

/* split */
char	**ps_split(char *s);
void	free_split(char **tab);

/* stack utils */
t_stack	*stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new);
t_stack	*stack_last(t_stack *stack);
int		stack_size(t_stack *stack);
int		is_sorted(t_stack *stack);
void	free_stack(t_stack **stack);

/* index */
void	assign_index(t_stack *stack);
int		get_max_bits(t_stack *stack);
int		get_min_index_pos(t_stack *stack);

/* operations */
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/* sort */
void	sort_stack(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);
void	radix_sort(t_stack **a, t_stack **b);

/* utils */
int		ps_isspace(char c);
int		ps_isdigit(char c);
size_t	ps_strlen(char *s);
void	ps_putstr_fd(char *s, int fd);
void	error_exit(t_stack **a);

#endif
