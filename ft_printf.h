#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int ft_printf(const char *s, ...);
int ft_putchar(int c);
int ft_putstr(char *str);
int ft_putnbr(int nb);
int ft_putunnbr(unsigned int nbr);
int ft_puthex(unsigned int nbr, char flag);
int ft_putaddr(unsigned long nbr);

#endif
