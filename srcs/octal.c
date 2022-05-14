/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvuorenl <rvuorenl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:19:16 by rvuorenl          #+#    #+#             */
/*   Updated: 2022/05/14 14:22:16 by rvuorenl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_zero_octal(t_info *i)
{
	if (!(i->flags & HASH) && i->width < 1 && i->prec == 0)
		return ;
	if (i->prec == 0 && !(i->flags & HASH))
		i->arg_len = 0;
	print_zero_octal_flags(i);
	if (i->flags & DOT)
		i->res += ft_putchar_multi('0', i->prec - 1);
	if (i->flags & HASH || i->prec > 0)
		i->res += write(1, "0", 1);
	if (i->flags & MINUS && i->width > 1 && i->width > i->prec)
	{
		if (i->flags & DOT && i->prec > 0)
			i->res += ft_putchar_multi(' ', i->width - i->prec);
		else
			i->res += ft_putchar_multi(' ', i->width - i->arg_len);
	}
}

void	convert_octal(unsigned long long num, t_info *i)
{
	if (num >= 8)
	{
		convert_octal(num / 8, i);
		convert_octal(num % 8, i);
	}
	else
	{
		i->cur_arg = i->cur_arg * 10 + num;
	}
}

void	print_octal_non_minus(t_info *i)
{
	if (i->width > 0 && i->flags & ZERO && !(i->flags & DOT))
		i->res += ft_putchar_multi('0', i->width - i->arg_len);
	else if (i->width > 0 && i->flags & DOT && i->prec > i->arg_len)
		i->res += ft_putchar_multi(' ', i->width - i->prec);
	else if (i->width > 0)
	{
		i->res += ft_putchar_multi(' ', i->width - i->arg_len);
		if (i->cur_arg == 0)
			i->res += write(1, " ", 1);
	}
	if (i->flags & HASH)
		i->res += write(1, "0", 1);
	if (i->prec > i->arg_len)
		i->res += ft_putchar_multi('0', i->prec - i->arg_len);
	if (i->cur_arg > 0 || (i->cur_arg == 0 && i->flags & ZERO
			&& !(i->flags & HASH)))
	{
		ft_putnbr_l(i->cur_arg);
		i->res += i->arg_len;
	}
}

void	print_octal_minus(t_info *i)
{
	if (i->flags & HASH)
		i->res += write(1, "0", 1);
	if (i->prec > i->arg_len)
		i->res += ft_putchar_multi('0', i->prec - i->arg_len);
	if (i->cur_arg > 0)
	{
		ft_putnbr_l(i->cur_arg);
		i->res += i->arg_len;
	}
	if (i->width > i->prec && i->width > i->arg_len)
	{
		if (i->prec > i->arg_len)
			i->res += ft_putchar_multi(' ', i->width - i->prec);
		else
			i->res += ft_putchar_multi(' ', i->width - i->arg_len);
	}
}

void	count_octal(t_info *i, unsigned long long tmp)			// NEW, ADD SOMEWHERE
{
	while (tmp >= 0)
	{
		if (tmp < 8)
		{
			i->arg_len++;
			return ;
		}
		tmp /= 8;
		i->arg_len++;
	}
}

void	test_octal(t_info *i, unsigned long long a)
{
	if (a > 8)
		test_octal(i, a / 8);
	// if (i->prec > 0)
	// {
		ft_putchar(a % 8 + '0');
	// 	i->prec--;
	// }
}

// prec 10

void	print_octal(t_info *i, va_list args)
{
	assign_oux(i, args);
	count_octal(i, i->cur_arg);
	if (i->width > i->prec && i->width > i->arg_len && !(i->flags & MINUS))
	{
		if (i->prec > i->arg_len)
			i->res += ft_putchar_multi(' ', i->width - i->prec);
		else
			i->res += ft_putchar_multi(' ', i->width - i->arg_len);
	}
	if (i->flags & HASH)
	{
		i->res++;
		putchar(0);
		i->prec--;
	}
	if (i->prec > i->arg_len)
		i->res += ft_putchar_multi('0', i->prec - i->arg_len);

	test_octal(i, i->cur_arg);

	if (i->prec < i->arg_len && i->flags & DOT)
		i->res += i->prec;
	else
		i->res += i->arg_len;

	if (i->flags & MINUS && i->width > i->prec && i->width > i->arg_len)
	{
		if (i->prec > i->arg_len)
			i->res += ft_putchar_multi(' ', i->width - i->prec);
		else
			i->res += ft_putchar_multi(' ', i->width - i->arg_len);
	}

	// printf(" >conv %llu, len = %d< ", i->cur_arg, i->arg_len);
	// // i->arg_len = count_digits(i->cur_arg);
	// if (i->cur_arg == 0)
	// 	return (print_zero_octal(i));
	// if (i->flags & HASH)
	// {
	// 	i->width--;
	// 	i->prec--;
	// }
	// if (!(i->flags & MINUS))
	// 	print_octal_non_minus(i);
	// else
	// 	print_octal_minus(i);
}
// 18446744073709551615	after assign
// 18446744073709551615	ULL MAX		len 20
// 18446744073709551615	= 1777...
// 1777777777777777777777 			len 22

// 1234591109996472368948161602020263671875