/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaguerd <yasser.aguerd@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 00:10:01 by yaaguerd          #+#    #+#             */
/*   Updated: 2026/05/16 00:40:19 by yaaguerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	add_number(t_stack **a, char *str, char **split)
{
	long	nb;

	if (!ft_is_number(str))
	{
		free_split(split);
		ft_error_stack(a);
	}
	nb = ft_atol(str);
	if (nb > INT_MAX || nb < INT_MIN)
	{
		free_split(split);
		ft_error_stack(a);
	}
	ft_lstadd_back(a, ft_lstnew((int)nb));
}

void	init_stack(t_stack **a, char **argv)
{
	char	**split;
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			ft_error_stack(a);
		j = 0;
		while (split[j])
			add_number(a, split[j++], split);
		free_split(split);
		i++;
	}
	if (has_duplicate(*a))
		ft_error_stack(a);
}
