#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"
#include <unistd.h>

int ft_putchar(int c)
{
        write(1,&c,1);
        return (1);
}

int ft_putstr(char *str)
{
        int i;
        i = 0;
        if (!str)
                return(ft_putstr("(null)"));
        while (str[i])
                write(1,&str[i++],1);
        return (i);
}

int ft_putnbr(int nbr)
{
        int i;
        i = 0;
        if (nbr == -2147483648)
        {
                ft_putstr("-2147483648");
                i = 11;
        }
        else if (nbr < 0)
        {
                i += ft_putchar('-');
                i += ft_putnbr(-nbr);
        }
        else if (nbr >= 10)
        {
                i += ft_putnbr(nbr / 10);
                i += ft_putchar(nbr % 10 + 48);
        }
        else
                i += ft_putchar(nbr + 48);
        return (i);
}

int ft_putunnbr(unsigned int nbr)
{
        unsigned int i;
        i = 0;
        if (nbr >= 10)
        {
                i += ft_putunnbr(nbr / 10);
                i += ft_putchar(nbr % 10 + 48);
        }
        else
                i += ft_putchar(nbr + 48);
        return (i);
}

int ft_puthex(unsigned int nbr, char flag)
{
        int i;

        i = 0;
        if (nbr >= 16)
                i += ft_puthex(nbr / 16, flag);
        if (flag == 'X')
                i += ft_putchar("0123456789ABCDEF"[nbr % 16]);
        else
                i += ft_putchar("0123456789abcdef"[nbr % 16]);
        return (i);
}

int ft_putaddr(unsigned long nbr)
{
        int i;

        i = 0;
        if (nbr >= 16)
                i += ft_putaddr(nbr / 16);
        i += ft_putchar("0123456789abcdef"[nbr % 16]);
        return (i);
}

int ft_flag_hundler(va_list argp, char flag)
{
        int count;

        count = 0;
        /*if (flag == '%')
                count += ft_putchar('%');
        else */if (flag == 'c')
                count += ft_putchar(va_arg(argp, int));
        else if (flag == 's')
                count += ft_putstr(va_arg(argp, char *));
        else if (flag == 'd' || flag == 'i')
                count += ft_putnbr(va_arg(argp, int));
        else if (flag == 'u')
                count += ft_putunnbr(va_arg(argp, unsigned int));
        else if (flag == 'x' || flag == 'X')
                count += ft_puthex(va_arg(argp, unsigned int), flag);
        else if (flag == 'p')
        {
                count += ft_putstr("0x");
                count += ft_putaddr(va_arg(argp, unsigned long));
        }
        return (count);
}
/*int ft_check(int f)
{
        if (f == '%' && f == 'c' || f == 's' || f == 'd' || f == 'i' || f == 'u' || f == 'x' || f == 'X' || f == 'p')
                return (1);
        return (0);
}
*/
int ft_printf(const char *s, ...)
{
        va_list argp;
        int i;
        int x;

        x = 0;
        i = 0;
        if (!s)
                return (0);
        va_start(argp, s);
        while(s[i])
        {
                if (s[i] == '%')
                {
                        if (s[++i] != '%')
                                x += ft_flag_hundler(argp, s[i]);
                        else
                                x += ft_putchar(s[i]);
                }
                else
                        x += ft_putchar(s[i]);
                i++;
        }
        va_end(argp);
        return (x);
}
/*
int main()
{
        int x;
        x = 9;
        printf("%p",0);
        puts("");
        ft_printf("%p",0);
        //printf("%d\n",printf("%p\n",&x));
        //printf("expact:%d\n",printf("%%%%\n"));
        //printf("result:%d\n",ft_printf("%%%%\n"));
}
*/
