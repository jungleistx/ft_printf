/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvuorenl <rvuorenl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:40:10 by rvuorenl          #+#    #+#             */
/*   Updated: 2022/05/12 12:08:16 by rvuorenl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*assign_str(t_info *i, va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		i->res += write(1, "(null)", 6);
		return (NULL);
	}
	if (ft_strlen(str) == 0)
	{
		i->arg_len = 0;
		i->prec = 0;
	}
	else
	{
		if (i->flags & DOT)
			i->arg_len = i->prec;
		else
			i->arg_len = (int)ft_strlen(str);
	}
	return (str);
}

void	print_str(t_info *i, va_list args)
{
	int		len;
	char	*str;

	len = 0;
	str = assign_str(i, args);
	if (!str)
		return ;
	if (!(i->flags & MINUS) && i->width > i->arg_len && i->width > i->prec)
	{
		if (i->flags & ZERO)
		{
			if (i->arg_len >= i->prec)
				i->res += ft_putchar_multi('0', i->width - i->arg_len);
			else
				i->res += ft_putchar_multi('0', i->width - i->prec);
		}
		else if (i->prec >= i->arg_len && i->flags & DOT)
			i->res += ft_putchar_multi(' ', i->width - i->prec);
		else
			i->res += ft_putchar_multi(' ', i->width - i->arg_len);
	}
	i->res += write(1, str, i->arg_len);
	if (i->flags & MINUS && i->width > i->arg_len)
		i->res += ft_putchar_multi(' ', i->width - i->arg_len);
}
