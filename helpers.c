/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvuorenl <rvuorenl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:39:01 by rvuorenl          #+#    #+#             */
/*   Updated: 2022/05/10 16:41:04 by rvuorenl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_multi(char c, int i)
{
	int	res;

	res = 0;
	while (i-- > 0)
		res += write(1, &c, 1);
	return (res);
}

void	ft_putnbr_l(unsigned long long n)
{
	if (n > 9)
		ft_putnbr_l(n / 10);
	ft_putchar(n % 10 + '0');
}

void	exit_error(char *str)
{
	ft_putstr(str);
	exit(-1);
}

int	count_digits(unsigned long long num)
{
	int	res;

	if (num == 0)
		return (1);
	res = 0;
	while (num != 0)
	{
		num /= 10;
		res++;
	}
	return (res);
}

void	reset_info(t_info *info, int reset)
{
	if (reset == 0)
	{
		info->i = 0;
		info->res = 0;
	}
	info->flags = 0;
	info->tmpres = 0;
	info->f_dec_len = 0;
	info->f_dec_arg = 0;
	info->arg_len = 0;
	info->width = 0;
	info->prec = 1;
	info->hex = 65;
	info->f_arg = 0;
	info->cur_arg = 0;
	info->f_total = 0;
}
