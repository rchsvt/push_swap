/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaguerd <yasser.aguerd@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 00:09:37 by yaaguerd          #+#    #+#             */
/*   Updated: 2026/05/16 00:36:37 by yaaguerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp1 = *a;
	tmp2 = tmp1->next;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	*a = tmp2;
	g_count.sa++;
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (!b || !*b || !(*b)->next)
		return ;
	tmp1 = *b;
	tmp2 = tmp1->next;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	*b = tmp2;
	g_count.sb++;
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (a && *a && (*a)->next)
	{
		tmp1 = *a;
		tmp2 = tmp1->next;
		tmp1->next = tmp2->next;
		tmp2->next = tmp1;
		*a = tmp2;
	}
	if (b && *b && (*b)->next)
	{
		tmp1 = *b;
		tmp2 = tmp1->next;
		tmp1->next = tmp2->next;
		tmp2->next = tmp1;
		*b = tmp2;
	}
	g_count.ss++;
	write(1, "ss\n", 3);
}
