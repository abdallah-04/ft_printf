/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <amufleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:47:18 by amufleh           #+#    #+#             */
/*   Updated: 2025/09/02 19:18:31 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ptr_len(unsigned long num)
{
	int	count;

	count = 1;
	while (num >= 16)
	{
		num /= 16;
		count++;
	}
	return (count);
}

static void	hex_conversion2(unsigned long num, const char *str)
{
	int	indx;

	indx = 0;
	if (num >= 16)
	{
		hex_conversion2 (num / 16, str);
	}
	indx = num % 16;
	write(1, &str[indx], 1);
}

static int	print_hex2(unsigned long num, char format)
{
	const char	*hex_char;
	int			count;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (format == 'X')
		hex_char = "0123456789ABCDEF";
	else
		hex_char = "0123456789abcdef";
	count = hex_len(num);
	hex_conversion2(num, hex_char);
	return (0);
}

int	print_ptr(unsigned long ptr)
{
	int	count;

	if (!ptr)
		return (print_str ("(nil)"));
	count = ptr_len (ptr);
	write(1, "0x", 2);
	print_hex2(ptr, 'x');
	return (count + 2);
}
