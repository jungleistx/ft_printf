/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvuorenl <rvuorenl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:05:53 by rvuorenl          #+#    #+#             */
/*   Updated: 2022/05/10 17:06:28 by rvuorenl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(t_info *info, va_list args)
{
	long long	cur_arg;
	if (info->flags & LLONG)
		cur_arg = va_arg(args, long long);
	else if (info->flags & LONG)
		cur_arg = (long long)va_arg(args, long);
	else
		cur_arg = (long long)va_arg(args, int);
	while (info->width > 1 && !(info->flags & MINUS))
	{
		if (info->flags & ZERO)
			info->res += write(1, "0", 1);
		else
			info->res += write(1, " ", 1);
		info->width--;
	}
	info->res += write(1, &cur_arg, 1);
	if (info->width > 1)
		info->width--;
	if (info->flags & MINUS)
	{
		while(info->width-- > 0)
			info->res += write(1, " ", 1);
	}
	return (1);
}
