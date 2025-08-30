#include <stdarg.h>
#include <stdio.h>
#include <ft_printf.h>
int sum(int count, ...)
{
    va_list args;
    va_start(args,count);
    int sum =0;
    for(int i=0;i<count;i++)
    {
       int x = va_arg(args,int);
       sum +=x;
    }
    va_end(args);
    return (sum);
}
int main()
{
    printf("%d",sum(5,1,2,3,4,5));
}
static int check_format(char *input, void *arg)
{
    int count;
    
    count = 0;
    return (count);
}
int ft_printf(const char *format, ...)
{
    va_list args;
    va_start(args,format);
    int	count;
    int i = 0;

    count = 0;
    i = 0;
    while(*format)
    {
        if (*format == '%')
        {
            format++;
            count += check_format(format, va_arg(args, void *));
        }
        else
            count += print_str(*format);
        format++;
    }
    va_end(args);
    return (count);
}