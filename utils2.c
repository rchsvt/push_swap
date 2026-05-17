/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaguerd <yasser.aguerd@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 00:35:56 by yaaguerd          #+#    #+#             */
/*   Updated: 2026/05/16 00:36:07 by yaaguerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	total_ops(void)
{
	return (
		g_count.sa
		+ g_count.sb
		+ g_count.ss
		+ g_count.pa
		+ g_count.pb
		+ g_count.ra
		+ g_count.rb
		+ g_count.rr
		+ g_count.rra
		+ g_count.rrb
		+ g_count.rrr
	);
}

void	print_bench(double disorder, char *mode)
{
	ft_printf_fd(2,
		"\n[bench] disorder: %d%%\n",
		(int)(disorder * 100));
	ft_printf_fd(2,
		"[bench] strategy: %s\n",
		mode);
	ft_printf_fd(2,
		"[bench] total_ops: %d\n",
		total_ops());
	ft_printf_fd(2,
		"[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		g_count.sa,
		g_count.sb,
		g_count.ss,
		g_count.pa,
		g_count.pb);
	ft_printf_fd(2,
		"[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		g_count.ra,
		g_count.rb,
		g_count.rr,
		g_count.rra,
		g_count.rrb,
		g_count.rrr);
}
