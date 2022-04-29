/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvuorenl <rvuorenl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:10:08 by rvuorenl          #+#    #+#             */
/*   Updated: 2022/04/29 14:17:78 by rvuorenl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" // all includes

int	ft_atoi(const char *str)
{
	unsigned long	num;
	int				i;
	int				negative;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\f' || str[i] == '\v' || str[i] == '\r')
		i++;
	num = 0;
	negative = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i++] - '0');
		if (negative == 1 && num > 9223372036854775807)
			return (-1);
		if (negative == -1 && num >= 9223372036854775808u)
			return (0);
	}
	return (num * (negative));
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putchar_multi(char c, int i)
{
	int	res;

	res = 0;
	while (i-- > 0)
		res += write(1, &c, 1);
	return (res);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *s)
{
	if (s)
		write(1, s, ft_strlen(s));
}

void	ft_putnbr_l(unsigned long long n)
{
	if (n > 9)
		ft_putnbr_l(n / 10);
	ft_putchar(n % 10 + '0');
}

void	ft_putnbr(int n)
{
	long	copy;

	copy = n;
	if (copy < 0)
	{
		ft_putchar('-');
		copy *= -1;
	}
	if (copy > 9)
		ft_putnbr(copy / 10);
	ft_putchar(copy % 10 + '0');
}


void	exit_error(char *str)
{
	ft_putstr(str);
	exit(-1);
}



// 	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-
// 	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-
// 	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-
// 	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-


int	count_digits(long long num)
{
	int	res;

	if (num == 0)
		return (1);
	res = 0;
	// if (num < 0)	//needed?, negative flag adds to arg_len ??
		// res++;
	while (num != 0)
	{
		num /= 10;
		res++;
	}
	return (res);
}

void	neg_number(long long num, t_info *i)
{
	i->cur_arg = (unsigned long long) (num * -1);
	i->flags |= NEGATIVE;

	if (i->prec > 1)
		i->prec++;
	i->arg_len++;

	// printf(" >> len %d, arg %lld, w %d<< ", i->arg_len, i->cur_arg, i->width);
}

void	assign_number(t_info *i, va_list args)
{
	if (i->flags & LLONG)
		i->tmp = va_arg(args, long long);
	else if (i->flags & LONG)
		i->tmp = (long long) va_arg(args, long);
	else
		i->tmp = (long long) va_arg(args, int);
	i->arg_len = count_digits(i->tmp);
	if (i->tmp < 0)
		neg_number(i->tmp, i);
	else
		i->cur_arg = (unsigned long long) i->tmp;
	if (i->width < 0)
	{
		i->flags |= MINUS;
		i->width *= -1;
		if (i->flags & ZERO)
			i->flags ^= ZERO;
	}
}

// check for compilation error combinations	, flags done, spec todo
int	check_error_input(t_info *info, char specifier)
{
	int	i;

	if ((info->flags & PLUS) && (info->flags & SPACE))
		return (0);
	if ((info->flags & MINUS) && (info->flags & ZERO))
		return (0);
	i = 0;
	while (SPECS[i])
	{
		if (SPECS[i++] == specifier)
			return (1);
	}
	return (0);
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
	// info->
}

// OK
int	dot_ast_flag(const char *str, t_info *info, va_list args)
{
	int	i;

	i = 0;
	if (str[i++] == '.')
	{
		if (info->flags & ZERO)		// need zero for %%, also with prec. FIX needed in %d ?
			info->flags ^= ZERO;
		info->flags |= DOT;
		if (str[i] == '*')
			info->prec = va_arg(args, int);
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
		if (str[i] == '*')
			return (i);
		// i = count_digits((long long)info->prec) - 1;
		i = count_digits((long long)info->prec);
		return (i);
	}
	else
	{
		info->width = va_arg(args, int);
		if (info->width < 0)
		{
			info->width *= -1;
			info->flags |= MINUS;
			if (info->flags & ZERO)
				info->flags ^= ZERO;
		}
	}
	return (0);
}

//	OK
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

// 		% [flags]	[width]		[.precision]	[length]	specifier

void	check_len_flags(char c, t_info *info)
{
	if (c == 'l' || c == 'L')
	{
		if (info->flags & LONG)
			info->flags |= LLONG;
		info->flags |= LONG;
	}
	else if (c == 'h')
	{
		if (info->flags & SHORT)
			info->flags |= SSHORT;
		info->flags |= SHORT;
	}
}

void	plus_space_flag(const char *str, t_info *i)
{
	if (str[0] == '+')
		i->flags |= PLUS;
	else
		i->flags |= SPACE;
	if ((i->flags & PLUS) && (i->flags & SPACE))
		i->flags ^= SPACE;
}

void	check_flags(const char *str, t_info *info, va_list args)
{
	int i;

	i = -1;
	// printf(">>>flags start i = %d<<<", info->i);
	while (str[++i])
	{
		// printf(" i = %d ", i);
		if (str[i] == ' ' || str[i] == '+')
			plus_space_flag(&str[i], info);
		else if (ft_isdigit((int)str[i]) || str[i] == '-')
			i += digit_minus_flag(&str[i], info);
		else if (str[i] == '#')
			info->flags |= HASH;
		else if (str[i] == '.' || str[i] == '*')
		{
			i += dot_ast_flag(&str[i], info, args);
		// printf(" >>end i = %d<< ", i);

		}
		else if (str[i] == 'l' || str[i] == 'L' || str[i] == 'h')
			check_len_flags(str[i], info);
		else	// this point we have flags + wid + prec
		{
			info->i += i;
			// printf(">>> flags end i = %d<<<", info->i);
			// printbin_2(&info->flags);
			return ;
		}
	}
}

// void	print_padding(t_info *i)
// {
// 	// printf(">>>zero i = %d, len = %d, w = %d<<<", i->i, i->arg_len, i->width);
// 	// printf(" >> prec %d, len %d, w %d<< ", i->prec, i->arg_len, i->width);
// 	char	c;

// 	if (i->flags & ZERO)
// 		c = '0';
// 	else
// 		c = ' ';
// 	if (i->prec > i->arg_len)
// 		i->res += ft_putchar_multi(c, i->width - i->prec);
// 	else
// 		i->res += ft_putchar_multi(c, i->width - i->arg_len);

// 	if (i->prec > i->arg_len)
// 		i->res += ft_putchar_multi('0', i->prec - i->arg_len);

// 	// printf(">>>zero end i = %d, len = %d, w = %d<<<", i->i, i->arg_len, i->width);
// }

// if (i->width > i->prec && i->width > i->arg_len)
// void	print_minus_flag(t_info *i)
// {
// 	// printf(" >>len %d, w %d, prec %d<< ", i->arg_len, i->width, i->prec);

// 	// printf("  ##len %d, w %d, prec %d##  ", i->arg_len, i->width, i->prec);

// 	// if (i->flags & PLUS || i->flags & NEGATIVE)
// 	// if (i->flags & PLUS)
// 		// i->width++;

// 	if (i->prec > i->arg_len)
// 		i->res += ft_putchar_multi(' ', i->width - i->prec);
// 	else
// 		i->res += ft_putchar_multi(' ', i->width - i->arg_len);
// }

void	print_zero_flag(t_info *i)
{
	// printf(">>>zero i = %d, len = %d, w = %d<<<", i->i, i->arg_len, i->width);
	// printf(" >> prec %d, len %d, w %d<< ", i->prec, i->arg_len, i->width);

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

	// printf(">>>zero end i = %d, len = %d, w = %d<<<", i->i, i->arg_len, i->width);
}

// if ((i->flags & PLUS) || (i->flags & NEGATIVE))
void	print_prefix_flag(t_info *i)
{
	if (i->flags & NEGATIVE)
	{
		i->res += write(1, "-", 1);
		//
		// if (!(i->flags & MINUS))
		// 	i->width--;

		// if (i->flags & ZERO)
		// 	i->width++;

		// if (!(i->flags & ZERO))
		// {
		// 	i->arg_len--;
		// 	i->prec--;
		// }
		//
	}
	else
	{
		i->res += write(1, "+", 1);
		i->width--;
	}


}

// if ((i->cur_arg == 0) && (i->flags & DOT) && (i->prec == 0))
int	print_zero_number(t_info *i)
{
	if (i->flags & PLUS)
	{
		i->width--;
		if (i->flags & MINUS)
		{
			i->res += write(1, "+", 1);
			i->res += ft_putchar_multi(' ', i->width);
		}
		else
		{
			i->res += ft_putchar_multi(' ', i->width);
			i->res += write(1, "+", 1);
		}
	}
	else if (i->flags & SPACE)
	{
		if (i->width == 0)
			i->width++;
		i->res += ft_putchar_multi(' ', i->width);
	}
	else
		i->res += ft_putchar_multi(' ', i->width);
	return (0);
}

// if ((i->flags & SPACE))
void	print_space_flag(t_info *i)
{
	if (i->flags & NEGATIVE)
	{
		if (i->flags & ZERO)
		{
			// i->width -= i->arg_len;
			return ;
		}
		// if (i->flags & MINUS || i->flags & ZERO)
		if (i->flags & MINUS)
			return ;
		if (i->arg_len >= i->width || i->prec >= i->width)
			return ;
	}
	i->res += write(1, " ", 1);
	i->width--;
}

// if ((i->width > i->arg_len) && (i->width > i->prec) && !(i->flags & MINUS))
void	print_width(t_info *i)
{
	int	res;

	if (i->flags & ZERO)
		return ;
	if (i->flags & PLUS && !(i->flags & NEGATIVE))
		i->width--;

	if (i->prec > i->arg_len)
		res = ft_putchar_multi(' ', i->width - i->prec);
	else
		res = ft_putchar_multi(' ', i->width - i->arg_len);
	i->width -= res;
	i->res += res;
}

// if (((i->flags & ZERO) && (i->width > i->arg_len)) || i->prec > i->arg_len)
void	print_prec_flag(t_info *i)
{
	int	res;

	if (i->flags & ZERO)
	{
		res = ft_putchar_multi('0', i->width - i->arg_len);
		i->width -= res;	// no need for width anymore?
	}
	else
	{
		res = ft_putchar_multi('0', i->prec - i->arg_len);
		i->width -= i->prec;
		i->prec = 0;
		i->arg_len = 0;
		// i->prec -= res;		// no need for prec anymore?
	}
	i->res += res;
}

// void	print_width(t_info *info)
// {
// 	if ((i->flags & PLUS) && !(i->flags & NEGATIVE))
// 		i->width--;
// 	if (i->width > i->arg_len && i->width > i->prec)
// 	{
// 		if (i->prec > i->arg_len)
// 			i->res += ft_putchar_multi(' ', i->width - i->prec)
// 		else
// 			i->res += ft_putchar_multi(' ', i->width - i->arg_len)
// 	}
// }

int	print_number(t_info *i, va_list args)
{
	// printf(">>%d<<\n", i->width);
	// printbin_2(&i->flags);
	assign_number(i, args);

	// printf(" >>w = %d, len = %d, prec = %d<< ", i->width, i->arg_len, i->prec);

	if ((i->cur_arg == 0) && (i->flags & DOT) && (i->prec == 0))
		return (print_zero_number(i));

	// printf(" >>str  %d<< ", i->width);
	// printf(" >> S w = %d, prec = %d<< ", i->width, i->prec);
	// printf("&&& w = %d, len = %d&&&", i->width, i->arg_len);

	if ((i->flags & SPACE))
		print_space_flag(i);

	// printf(" >>af spc  %d<< ", i->width);
	// printf(" >> SP w = %d, prec = %d<< ", i->width,  i->prec);
	if ((i->width > i->arg_len) && (i->width > i->prec) && !(i->flags & MINUS))
		print_width(i);

	// printf(" >>af wid %d<< ", i->width);
	// printf(" >> W w = %d, prec = %d<< ", i->width, i->prec);

	if ((i->flags & PLUS) || (i->flags & NEGATIVE))
		print_prefix_flag(i);	// if neg, len--, prec--, wid-- ?

	// printf(" >>af pre %d<< ", i->width);
	// printf(" >> PR w = %d, prec = %d<< ", i->width, i->prec);

	if (((i->flags & ZERO) && (i->width > i->arg_len)) || i->prec > i->arg_len)
		print_prec_flag(i);

	// printf(" >>af prec %d<< ", i->width);
	// printf(" >> PC w = %d, prec = %d<< ", i->width, i->prec);

	ft_putnbr_l(i->cur_arg);


	i->width -= i->arg_len;
	// if (i->flags & DOT)
	// {
	// 	if (i->flags & NEGATIVE)
	// 		i->width -= i->arg_len + 1;
	// 	else
	// 		i->width -= i->arg_len;
	// }


	// printf(" >>af num %d<< ", i->width);
	// printf(" >> N w = %d, prec = %d<< ", i->width, i->prec);

	// if (i->flags & MINUS && i->width > 0)
	// 	i->res += ft_putchar_multi(' ', i->width);

	if (i->flags & MINUS)
	{
		if (i->width > 0)
			i->res += ft_putchar_multi(' ', i->width);
		// if (i->flags & DOT)
		// 	i->res += ft_putchar_multi(' ', i->width - i->prec);
		// // if (i->width > i->arg_len)
		// else if (i->width > 0)
		// 	i->res += ft_putchar_multi(' ', i->width);

		//
		// if (i->flags & DOT)
		// if (i->flags & DOT && i->prec > i->arg_len)
		// {
		// 	if (i->prec > i->arg_len)
		// 		i->width -= i->prec;
		// 	else
		// 		i->width -= i->arg_len;
		// }
		//
	// printf(" >>w = %d<< ", i->width);
	// printf(" >>w = %d, len = %d, prec = %d<< ", i->width, i->arg_len, i->prec);
		// if (i->width > i->prec && i->width > i->arg_len)
		// if (i->width > i->arg_len)
		// 	i->res += ft_putchar_multi(' ', i->width - i->arg_len);
			// print_minus_flag(i);
	}
	return (i->res);	// no need?
}

/*
			42		-42		0
printf("|%05d| |%05d| |%05d| \n", x, y, z);
w 5, len 2	i4	i5
w 5, len 3	11	12
w 5, len 1	18	19
     6        14	22 %n
|00042| |-0042| |00000|
|   042| |  -042| |    00|
*/

int	write_non_percent(const char *str, t_info *info)
{
	int	i;

	i = 0;
	while (str[info->i] != '%' && str[info->i] != '\0')
	{
		info->i++;
		i++;
	}
	if (i > 0)
		write(1, &str[info->i - i], i);
	return (i);
}

void	write_percent(t_info *info)
{
	info->res += write(1, "%", 1);
	info->i++;
}

int	print_char(t_info *info, va_list args)
{
	// printf(">>> char beg i = %d<<<", info->i);
	// assign_number(info, args);
	long long	cur_arg;
	if (info->flags & LLONG)
		cur_arg = va_arg(args, long long);
	else if (info->flags & LONG)
		cur_arg = (long long)va_arg(args, long);
	else
		cur_arg = (long long)va_arg(args, int);
	while (info->width > 1 && !(info->flags & MINUS))
	{
		info->res += write(1, " ", 1);
		info->width--;
	}
	info->res += write(1, &cur_arg, 1);
	if (info->width > 1)
		info->width--;
	if (info->flags & MINUS)
	{
		while(info->width-- > 0)
			info->res += write(1, " ", 1);
	}
	// info->i++;
	// printf(">>> char end i = %d<<<", info->i);
	return (1);
}

void	assign_octal(t_info *info, va_list args)
{
	unsigned long long	tmp;
	int					i;

	// if (info->flags & LLONG)
	if (info->flags & LONG)
		info->cur_arg = va_arg(args, unsigned long long);
	else	// needed to be something still ??
		info->cur_arg = (unsigned long long) va_arg(args, unsigned int);
	i = 1;
	tmp = 0;
	if (info->cur_arg > 7)
	{
		while (info->cur_arg != 0)
		{
			tmp += (info->cur_arg % 8) * i;
			i *= 10;
			info->cur_arg /= 8;
		}
	}
	else
		tmp = info->cur_arg;
	info->arg_len = count_digits(tmp);
	info->cur_arg = tmp;
	// printf(" >> arg %lld, len %d<< ", info->cur_arg, info->arg_len);


}

// void	zero_octal(t_info *info)
// {

// }

void	check_octal_flags(t_info *info)
{
	if ((info->width > info->arg_len) && (info->width > info->prec))
	{
		// if (info->flags & ZERO)
		// 	zero_octal(info);
		// else
		// {
			if (info->prec > info->arg_len)
				info->res += ft_putchar_multi('0', 1); // tmp fix for gcc

		// }
	}
		info->res += ft_putchar_multi(' ', info->width - info->arg_len);


}

/*
if prec = 0 & !HASH & !ZERO & width < 1
return 0
arg		prints
08		8x0
*/

int	print_zero_octal(t_info *i)
{
	if (!(i->flags & HASH) && i->width < 1 && i->prec == 0 && !(i->flags & ZERO))
		return (0);

	// if (i->flags & HASH || i->flags & ZERO)
	// 	i->width--;

	// if (i->prec == 0 && )
	// 	i->arg_len = 0;
	if (i->prec == 0 && !(i->flags & HASH) && !(i->flags & ZERO))
		i->arg_len = 0;

	if (!(i->flags & MINUS && i->width > 0) && i->width > i->prec)
	{
		if (i->flags & ZERO)
			i->res += ft_putchar_multi('0', i->width - i->arg_len);
		else if (i->flags & DOT && i->width > i->prec && i->prec > 0)
			i->res += ft_putchar_multi(' ', i->width - i->prec);
		else
			i->res += ft_putchar_multi(' ', i->width - i->arg_len);
	}
	if (i->flags & DOT)
		i->res += ft_putchar_multi('0', i->prec - 1);

	if (i->flags & HASH || i->flags & ZERO || i->prec > 0)
		i->res += write(1, "0", 1);

	// #6.0 	1 too much _ 	|      0|		|     0|
	// #4.8		extra w _		|    00000000|	|00000000|
	// 8		1 e _
	// #8		1 e _

	if (i->flags & MINUS && i->width > 1 && i->width > i->prec)
	{
		if (i->flags & DOT && i->prec > 0)
			i->res += ft_putchar_multi(' ', i->width - i->prec);
		else
			i->res += ft_putchar_multi(' ', i->width - i->arg_len);	//
	}
	return (0);
}

int	print_octal(t_info *i, va_list args)
{
	// OK
	assign_octal(i, args);	// add hash w-- && pre-- ?
	// check_octal_flags(i);

	if (i->cur_arg == 0)
		return (print_zero_octal(i));

	if (i->flags & HASH)
	{
		i->width--;
		i->prec--;
	}

	if (!(i->flags & MINUS))
	{
		if (i->width > 0 && i->flags & ZERO)
			i->res += ft_putchar_multi('0', i->width - i->arg_len);
		else if (i->width > 0 && i->flags & DOT && i->prec > i->arg_len)
			i->res += ft_putchar_multi(' ', i->width - i->prec);
		else if (i->width > 0)
		{
			i->res += ft_putchar_multi(' ', i->width - i->arg_len);
			if (i->cur_arg == 0)
				i->res += write(1, " ", 1);
		}


		if (i->flags & HASH)
			i->res += write(1, "0", 1);
		if (i->prec > i->arg_len)
			i->res += ft_putchar_multi('0', i->prec - i->arg_len);
		if (i->cur_arg > 0 || (i->cur_arg == 0 && i->flags & ZERO && !(i->flags & HASH)))
		{
			ft_putnbr_l(i->cur_arg);
			i->res += i->arg_len;
		}
		// if (i->width > i->prec && i->width > i->arg_len)
		// {
		// 	if (i->prec > i->arg_len)
		// 		i->res += ft_putchar_multi(' ', i->width - i->prec);
		// 	else
		// 		i->res += ft_putchar_multi(' ', i->width - i->arg_len);
		// }
	}
	else
	{
		if (i->flags & HASH)
			i->res += write(1, "0", 1);
		if (i->prec > i->arg_len)
			i->res += ft_putchar_multi('0', i->prec - i->arg_len);
		if (i->cur_arg > 0)
		{
			ft_putnbr_l(i->cur_arg);
			i->res += i->arg_len;
		}
		if (i->width > i->prec && i->width > i->arg_len)
		{
			if (i->prec > i->arg_len)
				i->res += ft_putchar_multi(' ', i->width - i->prec);
			else
				i->res += ft_putchar_multi(' ', i->width - i->arg_len);

		}
	}

	/*
	all
		if hash && prec - len > 1, write 0
	if minus,
		if hash write 0, width--
		write arg, if prec write 0
		write width
	!minus
		write width
		if hash write 0 width--
		write arg, if prec write 0 arg
	*/

	return (1234);
}



// |30071|
// |7|
// |10|
// |11|
// printf("\n|%o|\n", 12345);
// 	printf("|%o|\n", 7);
// 	printf("|%o|\n", 8);
// 	printf("|%o|\n", 9);

int	print_percent(t_info *i, va_list args)	// ERROR, ZERO OFF WHEN PREC FLAG!: %03.5%
{
	(void)args;
	i->width--;
	if (!(i->flags & MINUS) && i->width > 0)
	{
		if (i->flags & ZERO)
			i->res += ft_putchar_multi('0', i->width);
		else
			i->res += ft_putchar_multi(' ', i->width);
	}
	i->res += write(1, "%", 1);
	if (i->flags & MINUS && i->width > 0)
		i->res += ft_putchar_multi(' ', i->width);
	return (123);	// check value
}
void	assign_dic(t_info *i, va_list args)
{
	long long	temp;

	if (i->flags & LLONG)
		temp = va_arg(args, long long);
	else if (i->flags & LONG)
		temp = (long long) va_arg(args, long);
	// else if (i->flags & SSHORT)
	// 	temp = (long long) va_arg(args, int);
	// else if (i->flags & SHORT)
	// 	temp = (long long) va_arg(args, int);
	else
		temp = (long long) va_arg(args, int);

	if (temp < 0)
	{
		i->flags |= NEGATIVE;
		i->cur_arg = temp * -1;
	}
	else
		i->cur_arg = (unsigned long long)temp;

	// i->arg_len = count_digits(i->cur_arg);
}

void	assign_ouxX(t_info *i, va_list args)
{
	if (i->flags & LLONG)
		i->cur_arg = va_arg(args, unsigned long long);
	else if (i->flags & LONG)
		i->cur_arg = (unsigned long long) va_arg(args, unsigned long);
	// else if (i->flags & SSHORT)
	// 	i->cur_arg = (unsigned long long) va_arg(args, int);
	// else if (i->flags & SHORT)
	// 	i->cur_arg = (unsigned long long) va_arg(args, int);
	else
		i->cur_arg = (unsigned long long) va_arg(args, unsigned int);

	// i->arg_len = count_digits(i->cur_arg);	// change to ULL
}

void	count_hex(t_info *i, unsigned long long tmp)
{
	while (tmp >= 0)
	{
		if (tmp < 16)
		{
			i->arg_len++;
			return ;
		}
		tmp /= 16;
		i->arg_len++;
	}
}

int	print_zero_hex(t_info *i)
{
	if (i->prec == 0)
		i->res += ft_putchar_multi(' ', i->width);
	else if (i->prec >= i->width)
		i->res += ft_putchar_multi('0', i->prec);
	else
	{
		if (!(i->flags & MINUS && i->width > 1))
		{
			if (i->flags & DOT)
				i->res += ft_putchar_multi(' ', i->width - i->prec);
			else
			{
				if (i->flags & ZERO)
					i->res += ft_putchar_multi('0', i->width - 1);
				else
					i->res += ft_putchar_multi(' ', i->width - 1);
			}
		}
		if (i->prec > 0)
			i->res += ft_putchar_multi('0', i->prec - 1);
		i->res += write(1, "0", 1);
		if (i->flags & MINUS && i->width > 1)
		{
			if (i->flags & DOT)
				i->res += ft_putchar_multi(' ', i->width - i->prec);
			else
				i->res += ft_putchar_multi(' ', i->width - 1);
		}
	}
	return (0);
}

void	print_hex(unsigned long long i, char letter)
{
	if (i > 15)
	{
		print_hex(i / 16, letter);
		if (i % 16 > 9)
			ft_putchar(i % 16 - 10 + letter);
		else
			ft_putchar(i % 16 + '0');
	}
	else
	{
		if (i > 9)
			ft_putchar(i % 10 + letter);
		else
			ft_putchar(i + '0');
	}
}

int	print_hex_flags(t_info *i, va_list args)
{
	assign_ouxX(i, args);
	count_hex(i, i->cur_arg);
	if (i->cur_arg == 0)
		return (print_zero_hex(i));

	if (i->flags & HASH)
		i->width -= 2;

	if (!(i->flags & MINUS) && i->width > i->arg_len && i->width > i->prec)
	{
		if (i->width > i->prec && i->width > i->arg_len)
		{
			if (i->flags & DOT && i->prec > i->arg_len)
				i->res += ft_putchar_multi(' ', i->width - i->prec);
			else if (i->flags & ZERO)
				i->res += ft_putchar_multi('0', i->width - i->arg_len);
			else
				i->res += ft_putchar_multi(' ', i->width - i->arg_len);
		}
	}

	if (i->flags & HASH)
	{
		i->res += 2;
		ft_putchar('0');
		ft_putchar(i->hex);
	}
	i->hex -= 23;
	if (i->prec > i->arg_len)
		i->res += ft_putchar_multi('0', i->prec - i->arg_len);
	print_hex(i->cur_arg, i->hex);
	i->res += i->arg_len;
	if (i->flags & MINUS && i->width > i->arg_len && i->width > i->prec)
	{
		if (i->prec > i->arg_len)
			i->res += ft_putchar_multi(' ', i->width - i->prec);
		else
			i->res += ft_putchar_multi(' ', i->width - i->arg_len);
	}
	return (123);
}

int	print_zero_unsig(t_info *i)
{
	if (i->width > 0)
		i->res += ft_putchar_multi(' ', i->width);

	// if (!(i->flags & MINUS) && i->width > 0)
	// 	i->res += ft_putchar_multi(' ', i->width);
	// else if (i->flags & MINUS && i->width > 0)
	// 	i->res += ft_putchar_multi(' ', i->width);

	return (0);
}

int	print_unsigned(t_info *i, va_list args)
{
	assign_ouxX(i, args);
	i->arg_len = count_digits(i->cur_arg);

	if (i->prec == 0 && i->cur_arg == 0)
		return (print_zero_unsig(i));

	if (!(i->flags & MINUS) && (i->width > i->arg_len && i->width > i->prec))
	{
		if (i->flags & DOT && i->prec > i->arg_len)
			i->res += ft_putchar_multi(' ', i->width - i->prec);
		else if (i->flags & ZERO)
			i->res += ft_putchar_multi('0', i->width - i->arg_len);
		else
			i->res += ft_putchar_multi(' ', i->width - i->arg_len);

	}
	if (i->prec > i->arg_len)
		i->res += ft_putchar_multi('0', i->prec - i->arg_len);
	// if (i->prec > 0)
	// {
		i->res += i->arg_len;
		ft_putnbr_l(i->cur_arg);
	// }
	if (i->flags & MINUS && i->width > i->arg_len && i->width > i->prec)
	{
		if (i->prec > i->arg_len)
			i->res += ft_putchar_multi(' ', i->width - i->prec);
		else
			i->res += ft_putchar_multi(' ', i->width - i->arg_len);
	}
	return (123);
}

int	print_str(t_info *i, va_list args)
{
	char	*str;
	int		len;

	len = 0;
	str = va_arg(args, char*);
	if (!str)
		return (0);
	if (i->flags & DOT)
		i->arg_len = i->prec;
	else
		i->arg_len = (int)ft_strlen(str);

	if (!(i->flags & MINUS) && i->width > i->arg_len && i->width > i->prec)
	{
		if (i->prec >= i->arg_len)
			i->res += ft_putchar_multi(' ', i->width - i->prec);
		else
			i->res += ft_putchar_multi(' ', i->width - i->arg_len);

	}
	if (i->flags & DOT)
	{
		while (i->prec-- > 0)
		{
			ft_putchar(str[len++]);
		}
		i->res += len;
		// i->width -= len;
	}
	else
	{
		ft_putstr(str);
		// i->res += (int)ft_strlen(str);
		i->res += i->arg_len;
	}

	if (i->flags & MINUS && i->width > i->arg_len)
		i->res += ft_putchar_multi(' ', i->width - i->arg_len);

	// if (i->flags & MINUS && i->width > i->arg_len && i->width > i->prec)
	// {
	// 	if (i->prec > i->arg_len)
	// 		i->res += ft_putchar_multi(' ', i->width - i->prec);
	// 	else
	// 		i->res += ft_putchar_multi(' ', i->width - i->arg_len);
	// }

	/*
	prec = max text	(str[prec] = '\0')
	*/
	return (123);
}

int	print_address(t_info *i, va_list args)
{
	void	*ptr;
	// unsigned long long	adr;

	ptr = va_arg(args, void *);
	if (!ptr)
		return (0);
	// adr = (unsigned long long)ptr;
	i->cur_arg = (unsigned long long)ptr;
	count_hex(i, i->cur_arg);
	i->width -= 2;

	if (!(i->flags & MINUS) && i->width > i->arg_len)
		i->res += ft_putchar_multi(' ', i->width - i->arg_len);

	i->res += 2;
	ft_putchar('0');
	ft_putchar('x');

	// printf(" >> adr = %llu<< ", adr);
	print_hex(i->cur_arg, 'a');

	if (i->flags & MINUS && i->width > i->arg_len)
		i->res += ft_putchar_multi(' ', i->width - i->arg_len);

	return (123);
}

int	calc_printed(t_info *i, va_list args)	// %n
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
	return (0);
}

// void	assing_float_frac(long double value, int prec, t_info *i)
// {
// 	if (!(i->flags & DOT))
// 		prec = 6;
// 	while (prec > 0)
// 	{
// 		value *= 10;
// 		prec--;
// 	}
// 	i->f_dec_arg = (int)value;
// 	printf("new frac = %llu\n", i->f_dec_arg);
// }

void	assing_float_to_ints(long double num, long double frac, t_info *i)
{
	int					x;
	unsigned long long	tmp;
	int					prec;

	x = 1;
	tmp = (unsigned long long)num;
	while (tmp != 0)
	{
		i->cur_arg += x * (tmp % 10);
		tmp /= 10;
		x *= 10;
	}
	i->arg_len = count_digits(i->cur_arg);	// len of before .
	frac -= (long double)i->cur_arg;	// 123.4 - 123 = 0.4

	prec = i->prec;
	if (!(i->flags & DOT))
		prec = 6;
	while (prec-- > 0)
		frac *= 10;
	i->f_dec_arg = (unsigned long long)frac;
	i->f_dec_len = count_digits(i->f_dec_arg);
	printf("new frac = %llu\tnum = %llu\n", i->f_dec_arg, i->cur_arg);
	printf("frac len = %d\tnum len = %d\n", i->f_dec_len, i->arg_len);

}


void	assign_float(t_info *i, va_list args)
{
	if (i->flags & LONG)
		i->f_arg = va_arg(args, long double);
	else
		i->f_arg = (long double) va_arg(args, double);
	if (i->f_arg < 0)
	{
		i->f_arg *= -1;
		i->flags |= NEGATIVE;
	}
		// printf("num = '%.20Lf'\n", i->f_arg);
	assing_float_to_ints(i->f_arg, i->f_arg, i);
}

int	print_float(t_info *i, va_list args)
{
	assign_float(i, args);

	// if (!(i->flags & DOT))
	// 	i->prec = 6;


	return (123);
}

int	check_specifier(const char *str, t_info *info, va_list args)
{
	// printbin_2(&info->flags);
	// printf(">>> specs i = %d<<<", info->i);


	int	i;

	// special case for str[0] == 'n' ?
	i = 0;
	// # define SPECS "%dicouxXnspf"	// zu same as l (sizeof)
	while (SPECS[i])
	{
		if (SPECS[i] == str[0])
		{
			if (SPECS[i] == 'x' || SPECS[i] == 'X')
				info->hex = SPECS[i];
			info->res += g_disp_table[i](info, args);	// no need for i->res +=
			info->i++;
			return (1);
		}
		i++;
	}
	return (0);
}



int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_info	info;

	reset_info(&info, 0);
	va_start(args, str);
	while (str[info.i])
	{
		if (str[info.i] != '%')
			info.res += write_non_percent(str, &info);
		// if (str[info.i] == '%')
		else
		{
			info.i++;
			check_flags(&str[info.i], &info, args);
			if (!check_specifier(&str[info.i], &info, args))
				exit_error("error, specifier not found!\n");

			// if (str[++info.i] == '%')
			// 	print_percent(&info, args);
			// else
			// {
			// 	// printf(">>> bef flags i = %d<<<", info.i);
			// 	check_flags(&str[info.i], &info, args);
			// 	// printf(">>> aft flags i = %d<<<", info.i);
			// 	if (!check_specifier(&str[info.i], &info, args))
			// 		exit_error("error, specifier not found!\n");
			// 		// exit_error("error\n");
			// 	// printf("print >>>i %d\t'%c'<<<", info.i, str[info.i]);
			// }

			reset_info(&info, 1);
		}
	}
	va_end(args);
	return (info.res);
}




int main(void)
{
	// sizes();
	// maxes();

	// //	--- d ---
	// test_d();
	// spacet();
	// widt();
	// plust();
	// prect();
	// zerot();
	// minust();

	// percent();
	// chart();
	// octals();
	// hext();
	// unsigt();
	// strt();
	// adrt();
	// printed();

	// floatt();
	printf("num = 6985.123459876\n");
	ft_printf("%f", 6985.123459876);
	printf("\n\n\n");
	printf("print\t%.10f\n", 6985.123459876);
	ft_printf("  %.10f", 6985.123459876);
	// printf("num = 100.525\n");
	// ft_printf("%f", 100.525);
	// printf("num = 6985123.12345987610101789123\n");
	// ft_printf("%f", 6985123.12345987610101789123);
	// printf("num = 1234567891.4\n");
	// ft_printf("%f", 1234567891.4);
	// printf("num = 7.1234567891234567\n");
	// ft_printf("%f", 7.1234567891234567);

	printf("\n");
}


/*
c
	no precision
	no space
	no 0
	no +
	yes
	-
	width
*/

/*
You are allowed to use the following functions:
◦ write
◦ malloc
◦ free
◦ exit
◦ The functions of man 3 stdarg
(
	va_start
	va_arg
	va_end
	va_copy
)
You have to recode the libc’s printf function.
• Your function will be called ft_printf and will be prototyped similarly to printf.
• You won’t do the buffer management in the printf function.
• You have to manage the following conversions: csp
• You have to manage the following conversions: diouxX with the following flags: hh,
h, l and ll.
• You have to manage the following conversion: f with the following flags: l and L.
• You must manage %%
• You must manage the flags #0-+ and space
• You must manage the minimum field-width
• You must manage the precision
*/
