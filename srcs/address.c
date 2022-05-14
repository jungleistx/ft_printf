/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvuorenl <rvuorenl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:45:33 by rvuorenl          #+#    #+#             */
/*   Updated: 2022/05/14 12:52:56 by rvuorenl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_address(t_info *i, va_list args)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	if (!ptr)
		return ;
	i->cur_arg = (unsigned long long)ptr;
	count_hex(i, i->cur_arg);
	i->width -= 2;
	if (!(i->flags & MINUS) && i->width > i->arg_len)
		i->res += ft_putchar_multi(' ', i->width - i->arg_len);
	i->res += 2;
	ft_putchar('0');
	ft_putchar('x');
	print_hex(i->cur_arg, 'a');
	i->res += i->arg_len;
	if (i->flags & MINUS && i->width > i->arg_len)
		i->res += ft_putchar_multi(' ', i->width - i->arg_len);
}
