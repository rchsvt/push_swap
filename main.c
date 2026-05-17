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

static int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

static void	sort_mode(t_stack **a, t_stack **b,
	double disorder, char *mode)
{
	int	size;

	size = get_stack_size(*a);
	if (size <= 5)
		sort_five(a, b);
	else if (!ft_strncmp(mode, "--simple", 9))
		sort_five(a, b);
	else if (!ft_strncmp(mode, "--medium", 9))
		chunk_sort(a, b);
	else if (!ft_strncmp(mode, "--complex", 10))
		radix_sort(a, b);
	else if (disorder < 0.5)
		chunk_sort(a, b);
	else
		radix_sort(a, b);
}

static int	is_mode(char *arg)
{
	if (!arg)
		return (0);
	if (!ft_strncmp(arg, "--simple", 9))
		return (1);
	if (!ft_strncmp(arg, "--medium", 9))
		return (1);
	if (!ft_strncmp(arg, "--complex", 10))
		return (1);
	if (!ft_strncmp(arg, "--adaptive", 11))
		return (1);
	return (0);
}

static char	*get_mode(int argc, char **argv, int *start)
{
	char	*mode;

	mode = "--adaptive";
	if (*start < argc && !ft_strncmp(argv[*start], "--bench", 8))
		(*start)++;
	if (*start < argc && is_mode(argv[*start]))
	{
		mode = argv[*start];
		(*start)++;
	}
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
	mode = get_mode(argc, argv, &start);
	if (start >= argc)
		return (0);
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
