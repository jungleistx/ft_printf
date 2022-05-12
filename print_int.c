/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvuorenl <rvuorenl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:02:23 by rvuorenl          #+#    #+#             */
/*   Updated: 2022/05/10 17:03:32 by rvuorenl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_number(t_info *i, va_list args)
{
	assign_dic(i, args);
	if ((i->cur_arg == 0) && (i->flags & DOT) && (i->prec == 0))
		return (print_zero_number(i));
	if ((i->flags & SPACE))
		print_space_flag(i);
	if ((i->width > i->arg_len) && (i->width > i->prec) && !(i->flags & MINUS))
		print_width(i);
	if ((i->flags & PLUS) || (i->flags & NEGATIVE))
		print_prefix_flag(i);
	if (((i->flags & ZERO) && (i->width > i->arg_len)) || i->prec > i->arg_len)
		print_prec_flag(i);
	ft_putnbr_l(i->cur_arg);
	i->res += i->arg_len;
	i->width -= i->arg_len;
	if (i->flags & MINUS)
	{
		if (i->width > 0)
			i->res += ft_putchar_multi(' ', i->width);
	}
	return (i->res);
}

