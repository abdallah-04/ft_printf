#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
#include "libft/libft.h"
#include <stdio.h>

int	ft_printf(const char *format, ...);
int	print_char(int c);
int	print_str(char *str);
int	int_len(int num);
int	print_hex(int num, char format);



#endif
