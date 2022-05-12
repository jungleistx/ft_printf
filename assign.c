/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvuorenl <rvuorenl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:43:54 by rvuorenl          #+#    #+#             */
/*   Updated: 2022/05/10 16:44:31 by rvuorenl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	assign_dic(t_info *i, va_list args)
{
	long long	temp;

	if (i->flags & LLONG)
		temp = va_arg(args, long long);
	else if (i->flags & LONG)
		temp = (long long) va_arg(args, long);
	else if (i->flags & SSHORT)
		temp = (long long) (signed char) va_arg(args, int);
	else if (i->flags & SHORT)
		temp = (long long) (short) va_arg(args, int);
	else
		temp = (long long) va_arg(args, int);
	if (temp < 0)
	{
		i->flags |= NEGATIVE;
		i->cur_arg = temp * -1;
	}
	else
		i->cur_arg = (unsigned long long)temp;

	i->arg_len = count_digits(i->cur_arg);
}
