/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaguerd <yasser.aguerd@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 00:09:58 by yaaguerd          #+#    #+#             */
/*   Updated: 2026/05/16 01:13:30 by yaaguerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_mode(t_stack **a, t_stack **b,
	double disorder, char *mode)
{
	if (!ft_strncmp(mode, "--simple", 9))
		sort_five(a, b);
	else if (!ft_strncmp(mode, "--medium", 9))
		chunk_sort(a, b);
	else if (!ft_strncmp(mode, "--complex", 10))
		radix_sort(a, b);
	else if (disorder < 0.2)
		sort_five(a, b);
	else if (disorder < 0.5)
		chunk_sort(a, b);
	else
		radix_sort(a, b);
}

static char	*get_mode(char **argv, int *start)
{
	char	*mode;

	mode = "--adaptive";
	if (!ft_strncmp(argv[*start], "--bench", 8))
		(*start)++;
	if (!ft_strncmp(argv[*start], "--simple", 9))
		mode = "--simple";
	else if (!ft_strncmp(argv[*start], "--medium", 9))
		mode = "--medium";
	else if (!ft_strncmp(argv[*start], "--complex", 10))
		mode = "--complex";
	else if (!ft_strncmp(argv[*start], "--adaptive", 11))
		mode = "--adaptive";
	if (argv[*start][0] == '-')
		(*start)++;
	return (mode);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	double	disorder;
	char	*mode;
	int		start;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	start = 1;
	mode = get_mode(argv, &start);
	init_stack(&a, argv + start - 1);
	if (is_sorted(a))
		return (free_stack(&a), 0);
	assign_index(a);
	disorder = compute_disorder(a);
	sort_mode(&a, &b, disorder, mode);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
