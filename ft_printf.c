/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <amufleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 09:29:54 by amufleh           #+#    #+#             */
/*   Updated: 2025/08/31 18:08:18 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format(char format, void *arg)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += print_char((int) arg);
	else if (format == 's')
		count += print_str((char *) arg);
	else if (format == 'i' || format == 'd')
		count += print_int((int) arg);
	else if (format == 'x' || format == 'X')
		count += print_hex((unsigned int) arg, format);
	else if (format == 'p')
		count += print_ptr((unsigned long) arg);
	else if (format == 'u')
		count += print_ptr((unsigned int) arg);
	else if (format == '%')
		count += print_char('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start (args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += check_format(format[i], va_arg(args, void *));
		}
		else
			count += print_char(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
