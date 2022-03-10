/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvuorenl <rvuorenl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:10:08 by rvuorenl          #+#    #+#             */
/*   Updated: 2022/03/10 16:14:28 by rvuorenl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdarg.h>
// #include <stdio.h>
#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *s)
{
	if (s)
		write(1, s, ft_strlen(s));
}

void	ft_putnbr(int n)
{
	long	copy;

	copy = n;
	if (copy < 0)
	{
		ft_putchar('-');
		copy *= -1;
	}
	if (copy > 9)
		ft_putnbr(copy / 10);
	ft_putchar(copy % 10 + '0');
}

int	count_digits(int num)
{
	int	res;

	res = 0:
	// if (num < 0)		NEEDED? does it count - as a digit to padding
		// res++;
	while (num > 0)
	{
		num /= 10;
		res++;
	}
	return (res);
}

int	specifiers(char *s, )

int	ft_printf(const char *str, ...)
{
	int		n;
	int		i;
	va_list	args;

	va_start(args, str);

	i = 0;
	while (str[i])
	{
		n = 0;
		if (str[i] != '%' || str[i] != '\0')
		{
			i++;
			n++;
		}
		if (n > 0)
			write(1, &str[i - n], n);
		if (str[i] == '%')
		{
			if (str[++i] == 'd')
				ft_putnbr(va_arg(args, int));
			else if (str[i] == )
			i++;
		}
	}
	return (0);
}

int main(void)
{
	int x = 42;

	ft_printf("random %d\nanother%d %d\n", x, x + x, x * 5);
	ft_printf("\n%d * %d = %d\n", 14, 4, 14*4);

}

/*
You are allowed to use the following functions:
◦ write
◦ malloc
◦ free
◦ exit
◦ The functions of man 3 stdarg
(
	va_start
	va_arg
	va_end
	va_copy
)
*/
