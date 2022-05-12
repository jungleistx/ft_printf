/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvuorenl <rvuorenl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:18:13 by rvuorenl          #+#    #+#             */
/*   Updated: 2022/05/12 19:41:00 by rvuorenl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
//delete
# include <stdio.h>
# include <limits.h>
# include <float.h>
// add	z, b?, P(what)?, m(what)?
# define SPECS "%dicoxXuUspnf"
# define RED "\033[0;31m"
# define NOCO "\033[0m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[4;33m"
# define BLUE "\033[0;34m"
//check necessary
typedef struct s_info
{
	uint16_t			flags;
	int					res;
	int					width;
	int					prec;
	int					arg_len;
	int					f_dec_len;
	long double			f_arg;
	unsigned long long	f_dec_arg;
	char				hex;
	int					i;
	int					f_total;
	unsigned long long	cur_arg;
	long long			tmp;
	int					min_len;
	int					tmpres;
}t_info;

typedef enum e_spec
{
	H,
	HH,
	L,
	LL
}t_spec;

typedef enum e_flags
{
	SPACE = 1,
	PLUS = 2,
	MINUS = 4,
	ZERO = 8,
	HASH = 16,
	DOT = 32,
	LONG = 64,
	LLONG = 128,
	SHORT = 256,
	SSHORT = 512,
	NEGATIVE = 1024
}t_flags;

typedef void				(*t_func_pointer) (t_info *, va_list);

int				ft_printf(const char *str, ...);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);
void			ft_putchar(char c);
void			print_zero_unsig(t_info *i);
char			*assign_str(t_info *i, va_list args);
void			print_zero_octal(t_info *i);
void			convert_octal(unsigned long long num, t_info *i);
void			print_octal_non_minus(t_info *i);
void			print_octal_minus(t_info *i);
void			print_prefix_flag(t_info *i);
void			print_zero_number(t_info *i);
void			print_prec_flag(t_info *i);
void			print_width(t_info *i);
void			print_zero_hex(t_info *i);
void			count_hex(t_info *i, unsigned long long tmp);
void			print_hex(unsigned long long i, char letter);
void			print_hex_zero_width(t_info *i);
void			print_hex_width(t_info *i);
void			print_hex_minus(t_info *i);
int				count_digits(unsigned long long num);
int				ft_putchar_multi(char c, int i);
void			ft_putnbr_l(unsigned long long n);
void			reset_info(t_info *info, int reset);
int				write_non_percent(const char *str, t_info *info);
void			check_flags(const char *str, t_info *info, va_list args);
void			check_specifier(const char *str, t_info *info, va_list args);
void			float_calc_total(t_info *i);
void			print_float_flags(t_info *i);
int				dot_flag(t_info *i, char *str, int i);
int				ast_precision_flag(t_info *i, va_list args);
int				dot_ast_flag(const char *str, t_info *info, va_list args);
void			special_flags(t_info *i);
void			check_len_flags(char c, t_info *info);
int				digit_minus_flag(const char *str, t_info *info);
void			plus_space_flag(const char *str, t_info *i);
void			assign_dic(t_info *i, va_list args);
void			assign_oux(t_info *i, va_list args);
void			float_rounding(t_info *i);
void			assign_float_to_ints(long double frac, t_info *i, int prec);
void			assign_float(t_info *i, va_list args);
void			print_percent(t_info *i, va_list args);
void			print_number(t_info *i, va_list args);
void			print_char(t_info *info, va_list args);
void			print_octal(t_info *i, va_list args);
void			print_hex_flags(t_info *i, va_list args);
void			print_unsigned(t_info *i, va_list args);
void			print_unsigned_long(t_info *i, va_list args);
void			print_str(t_info *i, va_list args);
void			print_address(t_info *i, va_list args);
void			calc_printed(t_info *i, va_list args);
void			print_float(t_info *i, va_list args);

static const t_func_pointer	g_disp_table[13] = {
	print_percent,
	print_number,
	print_number,
	print_char,
	print_octal,
	print_hex_flags,
	print_hex_flags,
	print_unsigned,
	print_unsigned_long,
	print_str,
	print_address,
	calc_printed,
	print_float
};

#endif
