/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvuorenl <rvuorenl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:17:35 by rvuorenl          #+#    #+#             */
/*   Updated: 2022/05/12 12:02:56 by rvuorenl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_char(t_info *info, va_list args)
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
		while (info->width-- > 0)
			info->res += write(1, " ", 1);
	}
}
