/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvuorenl <rvuorenl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:43:59 by rvuorenl          #+#    #+#             */
/*   Updated: 2022/05/13 14:47:45 by rvuorenl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_zero_octal_flags(t_info *i)
{
	if (!(i->flags & MINUS && i->width > 0) && i->width > i->prec)
	{
		if (i->flags & ZERO && i->prec != 0 && i->arg_len > i->prec)
			i->res += ft_putchar_multi('0', i->width - i->arg_len);
		else if (i->flags & DOT && i->width > i->prec && i->prec > 0)
			i->res += ft_putchar_multi(' ', i->width - i->prec);
		else if (i->flags & ZERO && i->prec != 0)
			i->res += ft_putchar_multi('0', i->width - i->arg_len);
		else
			i->res += ft_putchar_multi(' ', i->width - i->arg_len);
	}
}
