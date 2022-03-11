/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvuorenl <rvuorenl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:18:13 by rvuorenl          #+#    #+#             */
/*   Updated: 2022/03/11 15:27:37 by rvuorenl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>    // write
# include <stdlib.h>    // malloc free exit

# include <stdio.h> // delete

// # include "./libft/libft.h"

typedef struct  s_print
{
    uint16_t    flags;
}t_print;

int	ft_printf(const char *str, ...);

#endif