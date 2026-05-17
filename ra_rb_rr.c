/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaguerd <yasser.aguerd@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 00:09:46 by yaaguerd          #+#    #+#             */
/*   Updated: 2026/05/16 00:39:53 by yaaguerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	*a = first->next;
	first->next = NULL;
	last = ft_lstlast(*a);
	last->next = first;
	g_count.ra++;
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	*b = first->next;
	first->next = NULL;
	last = ft_lstlast(*b);
	last->next = first;
	g_count.rb++;
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	if (a && *a && (*a)->next)
	{
		first = *a;
		*a = first->next;
		first->next = NULL;
		last = ft_lstlast(*a);
		last->next = first;
	}
	if (b && *b && (*b)->next)
	{
		first = *b;
		*b = first->next;
		first->next = NULL;
		last = ft_lstlast(*b);
		last->next = first;
	}
	g_count.rr++;
	write(1, "rr\n", 3);
}
