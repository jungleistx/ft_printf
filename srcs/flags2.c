/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvuorenl <rvuorenl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:24:23 by rvuorenl          #+#    #+#             */
/*   Updated: 2022/05/12 20:45:27 by rvuorenl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	dot_flag(t_info *info, const char *str, int i, va_list args)
{
	info->flags |= DOT;
	if (str[++i] == '*')
	{
		return (ast_precision_flag(info, args));
	}
	else
	{
		if (!ft_isdigit((int)str[i]) && str[i] != '-')
		{
			info->prec = 0;
			return (0);
		}
		info->prec = ft_atoi(&str[i]);
	}
	if (info->prec < 0)
	{
		info->flags ^= DOT;
		info->prec = 1;
		return (0);
	}
	return (count_digits((long long)info->prec));
}

int	ast_precision_flag(t_info *i, va_list args)
{
	i->prec = va_arg(args, int);
	if (i->prec < 0)
	{
		i->flags ^= DOT;
		i->prec = 1;
	}
	return (1);
}

int	dot_ast_flag(const char *str, t_info *info, va_list args)
{
	int	i;

	i = 0;
	if (str[i] == '.')
		return (dot_flag(info, &str[i], i, args));
	else
	{
		info->width = va_arg(args, int);
		if (info->width < 0)
		{
			info->width *= -1;
			if (!(info->flags & MINUS))
				info->flags |= MINUS;
			if (info->flags & ZERO)
				info->flags ^= ZERO;
		}
		return (0);
	}
	return (0);
}
