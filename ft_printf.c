/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <amufleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 09:29:54 by amufleh           #+#    #+#             */
/*   Updated: 2025/08/31 12:55:53 by amufleh          ###   ########.fr       */
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
		count += print_hex((int) arg, format);
	// else if (format == 's')
	// 	count += print_str((char *) arg);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int	count;
	int	i;
	va_list	args;

	va_start(args,format);
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
