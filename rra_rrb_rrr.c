/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaguerd <yasser.aguerd@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 00:09:39 by yaaguerd          #+#    #+#             */
/*   Updated: 2026/05/16 00:26:01 by yaaguerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*last;
	t_stack	*before_last;

	if (!a || !*a || !(*a)->next)
		return ;
	before_last = *a;
	while (before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = *a;
	*a = last;
	g_count.rra++;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	t_stack	*last;
	t_stack	*before_last;

	if (!b || !*b || !(*b)->next)
		return ;
	before_last = *b;
	while (before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = *b;
	*b = last;
	g_count.rrb++;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	t_stack	*last;
	t_stack	*before_last;

	if (a && *a && (*a)->next)
	{
		before_last = *a;
		while (before_last->next->next)
			before_last = before_last->next;
		last = before_last->next;
		before_last->next = NULL;
		last->next = *a;
		*a = last;
	}
	if (b && *b && (*b)->next)
	{
		before_last = *b;
		while (before_last->next->next)
			before_last = before_last->next;
		last = before_last->next;
		before_last->next = NULL;
		last->next = *b;
		*b = last;
	}
	g_count.rrr++;
	write(1, "rrr\n", 4);
}
