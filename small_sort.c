/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaguerd <yasser.aguerd@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 00:09:33 by yaaguerd          #+#    #+#             */
/*   Updated: 2026/05/16 00:36:31 by yaaguerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int	max;

	max = get_max(*a);
	if ((*a)->value == max)
		ra(a);
	else if ((*a)->next->value == max)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	min;

	while (ft_lstsize(*a) > 3)
	{
		min = get_min(*a);
		if ((*a)->value == min)
			pb(a, b);
		else
			ra(a);
	}
	sort_three(a);
	pa(a, b);
	pa(a, b);
}

static void	push_chunk(t_stack **a, t_stack **b, int *i, int chunk)
{
	if ((*a)->index <= *i)
	{
		pb(a, b);
		rb(b);
		(*i)++;
	}
	else if ((*a)->index <= *i + chunk)
	{
		pb(a, b);
		(*i)++;
	}
	else
		ra(a);
}

void	chunk_sort(t_stack **a, t_stack **b)
{
	int	chunk;
	int	i;

	if (ft_lstsize(*a) <= 100)
		chunk = 15;
	else
		chunk = 30;
	i = 0;
	while (*a)
		push_chunk(a, b, &i, chunk);
	while (*b)
	{
		move_to_top(b, get_max_index(*b));
		pa(a, b);
	}
}
