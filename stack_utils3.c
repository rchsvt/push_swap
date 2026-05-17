/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaguerd <yasser.aguerd@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 00:36:01 by yaaguerd          #+#    #+#             */
/*   Updated: 2026/05/16 00:36:03 by yaaguerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_top(t_stack **a, int index)
{
	int	pos;
	int	size;

	pos = get_position(*a, index);
	size = ft_lstsize(*a);
	if (pos <= size / 2)
	{
		while ((*a)->index != index)
			ra(a);
	}
	else
	{
		while ((*a)->index != index)
			rra(a);
	}
}

int	get_max_index(t_stack *a)
{
	int	max;

	max = a->index;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	return (max);
}
