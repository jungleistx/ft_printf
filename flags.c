/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvuorenl <rvuorenl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:42:32 by rvuorenl          #+#    #+#             */
/*   Updated: 2022/05/10 16:53:44 by rvuorenl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	dot_flag(t_info *i, char *str, int i)
{
	info->flags |= DOT;
	if (str[i] == '*')
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

int	dot_ast_flag(const char *str, t_info *info, va_list args)
{
	int	i;

	i = 0;
	if (str[i++] == '.')
		return (dot_flag(info, &str[i], i));
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

int	digit_minus_flag(const char *str, t_info *info)
{
	int	i;

	i = 0;
	if (str[i] == '0')
		info->flags |= ZERO;
	else if (str[i] == '-')
		info->flags |= MINUS;
	else
	{
		info->width = ft_atoi(&str[i]);
		i = count_digits((long long)info->width);
		i--;
	}
	if ((info->flags & MINUS) && (info->flags & ZERO))
		info->flags ^= ZERO;
	if (info->width < 0)
	{
		info->width *= -1;
		info->flags |= MINUS;
		if (info->flags & ZERO)
			info->flags ^= ZERO;
	}
	return (i);
}

void	check_len_flags(char c, t_info *info)
{
	if (c == 'l' || c == 'L')
	{
		if (info->flags & LONG && !(info->flags & LLONG))
			info->flags |= LLONG;
		else if (!(info->flags & LONG))
			info->flags |= LONG;
	}
	else if (c == 'h')
	{
		if (info->flags & SHORT && !(info->flags & SSHORT))
			info->flags |= SSHORT;
		else if (!(info->flags & SHORT))
			info->flags |= SHORT;
	}
}
