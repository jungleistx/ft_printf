/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvuorenl <rvuorenl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:41:40 by rvuorenl          #+#    #+#             */
/*   Updated: 2022/05/10 17:01:59 by rvuorenl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	neg_number(long long num, t_info *i)
{
	i->cur_arg = (unsigned long long)(num * -1);
	i->flags |= NEGATIVE;
	if (i->prec > 1)
		i->prec++;
	i->arg_len++;
}

int	print_zero_number(t_info *i)
{
	if (i->flags & PLUS)
	{
		i->width--;
		if (i->flags & MINUS)
		{
			i->res += write(1, "+", 1);
			i->res += ft_putchar_multi(' ', i->width);
		}
		else
		{
			i->res += ft_putchar_multi(' ', i->width);
			i->res += write(1, "+", 1);
		}
	}
	else if (i->flags & SPACE)
	{
		if (i->width == 0)
			i->width++;
		i->res += ft_putchar_multi(' ', i->width);
	}
	else
		i->res += ft_putchar_multi(' ', i->width);
	return (0);
}

void	print_space_flag(t_info *i)
{
	if (i->flags & NEGATIVE)
		return ;
	i->res += write(1, " ", 1);
	i->width--;
}

void	print_width(t_info *i)
{
	if (i->flags & ZERO && !(i->flags & DOT))
		return ;
	if (i->flags & NEGATIVE || i->flags & PLUS)
		i->width--;
	if (i->flags & DOT && i->prec > i->arg_len && !(i->flags & ZERO))
	{
		i->res += ft_putchar_multi(' ', i->width - i->prec);
		i->width = 0;
	}
	else if (i->arg_len >= i->prec)
	{
		i->res += ft_putchar_multi(' ', i->width - i->arg_len);
		i->width = 0;
	}
	if (i->flags & ZERO && i->prec > i->arg_len)
	{
		i->res += ft_putchar_multi(' ', i->width - i->prec);
		i->width = 0;
	}
}

void	print_prec_flag(t_info *i)
{
	int	res;

	if (i->flags & ZERO && i->width > i->prec && i->width > i->arg_len)
	{
		if (i->prec > i->arg_len)
			res = ft_putchar_multi('0', i->width - i->prec);
		else
			res = ft_putchar_multi('0', i->width - i->arg_len);
	}
	else
	{
		res = ft_putchar_multi('0', i->prec - i->arg_len);
		i->prec = 0;
	}
	i->width -= res;
	i->res += res;
}
