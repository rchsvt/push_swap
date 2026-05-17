/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaguerd <yasser.aguerd@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 00:09:18 by yaaguerd          #+#    #+#             */
/*   Updated: 2026/05/16 00:33:10 by yaaguerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

void	assign_index(t_stack *a)
{
	t_stack	*current;
	t_stack	*smallest;
	int		index;

	index = 0;
	while (index < ft_lstsize(a))
	{
		smallest = NULL;
		current = a;
		while (current)
		{
			if (current->index == -1
				&& (!smallest
					|| current->value < smallest->value))
				smallest = current;
			current = current->next;
		}
		if (smallest)
			smallest->index = index++;
	}
}

void	print_stack(t_stack *a)
{
	while (a)
	{
		ft_printf_fd(1, "%d -> %d\n", a->value, a->index);
		a = a->next;
	}
}

double	compute_disorder(t_stack *a)
{
	t_stack	*i;
	t_stack	*j;
	double	mistakes;
	double	total;

	mistakes = 0;
	total = 0;
	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total == 0)
		return (0);
	return (mistakes / total);
}
