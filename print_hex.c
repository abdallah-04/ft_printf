/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <amufleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 12:15:36 by amufleh           #+#    #+#             */
/*   Updated: 2025/08/31 13:44:51 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hex_conversion(int num, char * str)
{
	int	x;

	x = 0;
	if (num > 16)
	{
		hex_conversion(num/16, str);
	}
	if (num <= 16)
	{
		hex_conversion(num/16, str);
		write(1,&str[num - 1],1);
	}
	x = num % 16;
	write(1,&str[x],1);
}
int	print_hex(int num, char format)
{
	char *hex_latter;
	char *ans;
	int	indx;
	int	count;

	count = 0;
	if (format == 'X')
		hex_latter = ft_strdup("0123456789ABCDEF");
	else
		hex_latter = ft_strdup("0123456789abcdef");
	hex_conversion(num, hex_latter);

	return (count);
}
C
