/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvuorenl <rvuorenl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:46:39 by rvuorenl          #+#    #+#             */
/*   Updated: 2022/05/12 12:09:25 by rvuorenl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	calc_printed(t_info *i, va_list args)
{
	long long	*lptr;
	signed char	*cptr;
	int			*iptr;

	iptr = NULL;
	cptr = NULL;
	lptr = NULL;
	if (i->flags & LLONG)
	{
		lptr = va_arg(args, long long *);
		*lptr = (long long)i->res;
	}
	if (i->flags & SSHORT)
	{
		cptr = va_arg(args, signed char *);
		*cptr = (signed char)i->res;
	}
	else
	{
		iptr = va_arg(args, int *);
		*iptr = i->res;
	}
}
