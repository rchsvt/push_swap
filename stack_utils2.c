/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaguerd <yasser.aguerd@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 00:09:25 by yaaguerd          #+#    #+#             */
/*   Updated: 2026/05/16 00:31:13 by yaaguerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack *a)
{
	int	max;

	max = a->value;
	while (a)
	{
		if (a->value > max)
			max = a->value;
		a = a->next;
	}
	return (max);
}

int	get_min(t_stack *a)
{
	int	min;

	min = a->value;
	while (a)
	{
		if (a->value < min)
			min = a->value;
		a = a->next;
	}
	return (min);
}

t_stack	*get_min_node(t_stack *a)
{
	t_stack	*min;

	min = a;
	while (a)
	{
		if (a->value < min->value)
			min = a;
		a = a->next;
	}
	return (min);
}

int	get_max_bits(t_stack *a)
{
	int	max;
	int	bits;

	max = ft_lstsize(a) - 1;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

int	get_position(t_stack *a, int index)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (a->index == index)
			return (pos);
		a = a->next;
		pos++;
	}
	return (-1);
}
