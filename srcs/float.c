/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvuorenl <rvuorenl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:48:44 by rvuorenl          #+#    #+#             */
/*   Updated: 2022/05/12 18:42:05 by rvuorenl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	float_calc_total(t_info *i)
{
	i->f_total = i->arg_len;
	if (i->prec > i->f_dec_len)
		i->f_total += i->prec;
	else
		i->f_total += i->f_dec_len;
	if (i->flags & HASH || i->prec > 0)
		i->f_total++;
}

void	print_float_flags(t_info *i)
{
	if (i->flags & SPACE && !(i->flags & NEGATIVE))
	{
		i->res += write(1, " ", 1);
		i->width--;
	}
	if (i->width > i->f_total && !(i->flags & MINUS) && !(i->flags & ZERO))
	{
		i->res += ft_putchar_multi(' ', i->width - i->f_total);
	}
	if (i->flags & NEGATIVE)
	{
		i->res += write(1, "-", 1);
	}
	else if (i->flags & PLUS)
		i->res += write(1, "+", 1);
	if (i->flags & ZERO && i->width > i->f_total)
	{
		i->res += ft_putchar_multi('0', i->width - i->f_total);
	}
}

void	print_float(t_info *i, va_list args)
{
	assign_float(i, args);
	print_float_flags(i);
	ft_putnbr_l(i->cur_arg);
	i->res += i->arg_len;
	if (i->flags & HASH || i->prec > 0)
		i->res += write(1, ".", 1);
	if (i->prec != 0)
	{
		if (i->f_dec_arg == 0)
			i->res += ft_putchar_multi('0', i->prec);
		else
		{
			if (i->prec > i->f_dec_len)
				i->res += ft_putchar_multi('0', i->prec - i->f_dec_len);
			ft_putnbr_l(i->f_dec_arg);
		}
		i->res += i->prec;
	}
	if (i->flags & MINUS && i->width > i->f_total)
		i->res += ft_putchar_multi(' ', i->width - i->f_total);
}
