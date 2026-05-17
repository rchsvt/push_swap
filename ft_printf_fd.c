/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaguerd <yasser.aguerd@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 00:10:06 by yaaguerd          #+#    #+#             */
/*   Updated: 2026/05/16 00:40:30 by yaaguerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar_fd_count(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

static int	ft_putstr_fd_count(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
		i += ft_putchar_fd_count(s[i], fd);
	return (i);
}

static int	ft_putnbr_fd_count(int n, int fd)
{
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += ft_putchar_fd_count('-', fd);
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_putnbr_fd_count(nb / 10, fd);
	count += ft_putchar_fd_count((nb % 10) + '0', fd);
	return (count);
}

static int	ft_format_fd(int fd, char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_fd_count(va_arg(args, int), fd));
	if (c == 's')
		return (ft_putstr_fd_count(va_arg(args, char *), fd));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_fd_count(va_arg(args, int), fd));
	if (c == '%')
		return (ft_putchar_fd_count('%', fd));
	return (0);
}

int	ft_printf_fd(int fd, const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			count += ft_format_fd(fd, format[++i], args);
		else
			count += ft_putchar_fd_count(format[i], fd);
		i++;
	}
	va_end(args);
	return (count);
}
