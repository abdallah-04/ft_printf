/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <amufleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 08:46:46 by amufleh           #+#    #+#             */
/*   Updated: 2025/09/01 09:45:44 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cheak_format(char format, void * arg)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += print_char((int) arg);
	else if (format == 's')
		count += print_str((char *) arg);
	else if (format == 'i' || format == 'd')
		count += print_int((int) arg);
	else if (format == 'x' ||  format == 'X')
		count += print_hex((unsigned long) arg, format);
	else if (format == 'p')
		count += print_ptr((unsigned long) arg);
	else if(format == '%')
		count += print_char('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int	count;
	int	i;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += cheak_format(format[i], va_arg(args, void *));
		}
		else
		{
			count += print_char(format[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}
