/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvuorenl <rvuorenl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:54:07 by rvuorenl          #+#    #+#             */
/*   Updated: 2022/05/10 16:59:02 by rvuorenl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	plus_space_flag(const char *str, t_info *i)
{
	if (str[0] == '+')
		i->flags |= PLUS;
	else
		i->flags |= SPACE;
	if ((i->flags & PLUS) && (i->flags & SPACE))
		i->flags ^= SPACE;
}

void	special_flags(t_info *i)
{
	if (i->flags & LONG && !(i->flags & LLONG))
		i->flags |= LLONG;
	else if (!(i->flags & LONG))
		i->flags |= LONG;
}

void	check_flags(const char *str, t_info *info, va_list args)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == ' ' || str[i] == '+')
			plus_space_flag(&str[i], info);
		else if (ft_isdigit((int)str[i]) || str[i] == '-')
			i += digit_minus_flag(&str[i], info);
		else if (str[i] == '#')
			info->flags |= HASH;
		else if (str[i] == '.' || str[i] == '*')
			i += dot_ast_flag(&str[i], info, args);
		else if (str[i] == 'l' || str[i] == 'L' || str[i] == 'h')
			check_len_flags(str[i], info);
		else if (str[i] == 'j' || str[i] == 't' || str[i] == 'z'
			|| str[i] == 'q')
			special_flags(info);
		else
		{
			info->i += i;
			return ;
		}
	}
}

void	print_zero_flag(t_info *i)
{
	char	c;

	if (i->flags & ZERO)
		c = '0';
	else
		c = ' ';
	if (i->width > i->arg_len && i->width > i->prec)
	{
		if (i->prec > i->arg_len)
			i->res += ft_putchar_multi(c, i->width - i->prec);
		else
			i->res += ft_putchar_multi(c, i->width - i->arg_len);
	}
	if (i->prec > i->arg_len)
		i->res += ft_putchar_multi('0', i->prec - i->arg_len);
}

void	print_prefix_flag(t_info *i)
{
	if (i->flags & NEGATIVE)
		i->res += write(1, "-", 1);
	else
		i->res += write(1, "+", 1);
		i->width--;
}
