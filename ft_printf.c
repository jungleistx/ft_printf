/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvuorenl <rvuorenl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:10:08 by rvuorenl          #+#    #+#             */
/*   Updated: 2022/05/12 10:37:22 by rvuorenl         ###   ########.fr       */
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


int	count_digits(unsigned long long num)
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
	info->hex = 0;
	info->f_arg = 0;
	info->cur_arg = 0;
	info->f_total = 0;
	// info->
}

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
	if (str[i++] == '.')
	{
		// ft_printf("b");
		// if (info->flags & ZERO)		// need zero for %%, also with prec. FIX needed in %d ?
		// 	info->flags ^= ZERO;	//	also needed for %f
		info->flags |= DOT;
		if (str[i] == '*')
		{
			return (ast_precision_flag(info, args));
			// info->prec = va_arg(args, int);
			// ft_printf(" >>PREC %d, w = %d<< ", info->prec, info->width);
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
			// ft_printf(" >>PREC %d<< ", info->prec);
			return (0);
		}
		// if (str[i] == '*')
		// {
		// 	ft_printf("c");
		// 	return (i);
		// }
		// i = count_digits((long long)info->prec) - 1;
		// i = count_digits((long long)info->prec);
		// return (i);
		return (count_digits((long long)info->prec));
	}
	else
	{
		// ft_printf("a");
		info->width = va_arg(args, int);
		// ft_printf(" >>W = %d<< ", info->width);
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
	// if (c == 'l' || c == 'L')
	// {
	// 	if (info->flags & LONG)
	// 		info->flags |= LLONG;
	// 	info->flags |= LONG;
	// }
	// else if (c == 'h')
	// {
	// 	if (info->flags & SHORT)
	// 		info->flags |= SSHORT;
	// 	info->flags |= SHORT;
	// }
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
		// printf(" >>star i = %d<< ", i);

		}
		else if (str[i] == 'l' || str[i] == 'L' || str[i] == 'h')
			check_len_flags(str[i], info);
		else if (str[i] == 'j' || str[i] == 't' || str[i] == 'z' || str[i] == 'q')
			special_flags(info);
		else	// this point we have flags + wid + prec
		{
			info->i += i;
			// printf(" end i = %d ", i);
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
		// printf(" >>prefix res = %d<< ", i->res);
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
		// i->width--;
	}
		i->width--;
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
		return ;
		// if (i->flags & ZERO)
		// {
		// 	// i->width -= i->arg_len;
		// 	return ;
		// }
		// // if (i->flags & MINUS || i->flags & ZERO)
		// if (i->flags & MINUS)
		// 	return ;
		// if (i->arg_len >= i->width || i->prec >= i->width)
		// 	return ;
	}
	i->res += write(1, " ", 1);
	i->width--;
}

// if ((i->width > i->arg_len) && (i->width > i->prec) && !(i->flags & MINUS))
void	print_width(t_info *i)
{
	// int	res;

	if (i->flags & ZERO && !(i->flags & DOT))
		return ;
	if (i->flags & NEGATIVE || i->flags & PLUS)
		i->width--;

	if (i->flags & DOT && i->prec > i->arg_len && !(i->flags & ZERO))
	{
		i->res += ft_putchar_multi(' ', i->width - i->prec);
		// i->width -= i->prec;
		i->width = 0;		// ADDED
	}
	else if (i->arg_len >= i->prec)
	{
		i->res += ft_putchar_multi(' ', i->width - i->arg_len);
		// i->width -= i->arg_len;
		i->width = 0;		// ADDED

	}
	if (i->flags & ZERO && i->prec > i->arg_len)
	{
		i->res += ft_putchar_multi(' ', i->width - i->prec);
		i->width = 0;		// ADDED

	}

	// if (i->flags & DOT && i->width > i->prec && i->width > i->arg_len)
	// {
	// 	if (i->flags & ZERO)
	// 	{
	// 		write(1, "aa", 2);
	// 		if (i->prec > i->arg_len)
	// 			i->res += ft_putchar_multi('0', i->width - i->prec);
	// 		else
	// 			i->res += ft_putchar_multi('0', i->width - i->arg_len);
	// 	}
	// 	else
	// 	{
	// 		if (i->prec > i->arg_len)
	// 			i->res += ft_putchar_multi(' ', i->width - i->prec);
	// 		else
	// 			i->res += ft_putchar_multi(' ', i->width - i->arg_len);
	// 	}

	// }
	// UPDATE
	// if ((i->flags & PLUS || i->flags & NEGATIVE) && !(i->flags & DOT))
	// 	return ;

	// if (i->flags & ZERO)
	// {
	// 	if (i->flags & DOT && i->width > i->prec && i->width > i->arg_len)
	// 	{
	// 		if (i->prec > i->arg_len)
	// 		{
	// 			i->res += ft_putchar_multi('0', i->width - i->prec);
	// 			i->width -= i->prec;
	// 		}
	// 		else
	// 		{
	// 			i->res += ft_putchar_multi('0', i->width - i->arg_len);
	// 			i->width -= i->arg_len;
	// 		}
	// 	}
	// 	else
	// 	{
	// 		i->res += ft_putchar_multi('0', i->width - i->arg_len);
	// 		i->width -= i->arg_len;
	// 	}
	// }
	// DELETE

	// if (i->flags & ZERO && !(i->flags & NEGATIVE) && !(i->flags & PLUS))
	// {
	// 	if (i->width > i->prec && i->flags & DOT)
	// 	{
	// 		i->res += ft_putchar_multi(' ', i->width - i->prec);
	// 		// i->width -= i->prec;
	// 	}
	// 	else
	// 	{
	// 		i->res += ft_putchar_multi('0', i->width - i->arg_len);
	// 		i->width -= i->arg_len;
	// 	}

	// 	return ;
	// }


	// if (i->flags & PLUS && !(i->flags & NEGATIVE))

	// UPDATE
	// if (i->flags & PLUS || i->flags & NEGATIVE)
	// 	i->width--;

	// if (i->prec > i->arg_len)
	// 	res = ft_putchar_multi(' ', i->width - i->prec);
	// else
	// 	res = ft_putchar_multi(' ', i->width - i->arg_len);
	// i->width -= res;
	// i->res += res;
	//
}

// if (((i->flags & ZERO) && (i->width > i->arg_len)) || i->prec > i->arg_len)
void	print_prec_flag(t_info *i)
{
	int	res;

	if (i->flags & ZERO && i->width > i->prec && i->width > i->arg_len)
	{
		if (i->prec > i->arg_len)
			res = ft_putchar_multi('0', i->width - i->prec);
		else
			res = ft_putchar_multi('0', i->width - i->arg_len);
		// i->width -= res;	// needed in MINUS
	}
	else
	{
		res = ft_putchar_multi('0', i->prec - i->arg_len);
		// i->width -= i->prec;
		i->prec = 0;
		// i->arg_len = 0;
		// i->prec -= res;		// no need for prec anymore?
	}
	i->width -= res;
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
	// assign_number(i, args);

	assign_dic(i, args);		// ?			CONT
	// i->arg_len = count_digits(i->cur_arg);


	//
	// printf(" >> STR w = %d, len = %d, prec = %d, arg = %llu<< ", i->width, i->arg_len, i->prec, i->cur_arg);
	//
	//

	// printf("assign res = %d\n", i->res);
	if ((i->cur_arg == 0) && (i->flags & DOT) && (i->prec == 0))
		return (print_zero_number(i));

	// printf(" >>str  %d<< ", i->width);
	// printf(" >> S w = %d, prec = %d<< ", i->width, i->prec);
	// printf("&&& w = %d, len = %d&&&", i->width, i->arg_len);

	// ft_printf("a");
	if ((i->flags & SPACE))
		print_space_flag(i);

	// printf("\nspace res = %d, len = %d\n", i->res, i->arg_len);
	// printf(" >>af spc  %d<< ", i->width);
	// printf(" >> SP w = %d, prec = %d, len = %d<< ", i->width,  i->prec, i->arg_len);
	// ft_printf("b");
	if ((i->width > i->arg_len) && (i->width > i->prec) && !(i->flags & MINUS))
		print_width(i);


	// printf(" >> WID w = %d, prec = %d, len = %d<< ", i->width,  i->prec, i->arg_len);
	// printf(" >>af wid %d<< ", i->width);
	// printf(" >> W w = %d, prec = %d<< ", i->width, i->prec);

	// ft_printf("c");
	if ((i->flags & PLUS) || (i->flags & NEGATIVE))
		print_prefix_flag(i);	// if neg, len--, prec--, wid-- ?

	// printf("prefi res = %d\n", i->res);
	// printf(" >>af pre %d<< ", i->width);
	// printf(" >> PR w = %d, prec = %d<< ", i->width, i->prec);

	// ft_printf("d");
	// printf("befprec res = %d\n", i->res);
	// printf("\nbef res = %d, len = %d\n", i->res, i->arg_len);
	// printf(" >>PREF prec = %d, len = %d, widt = %d<< ", i->prec, i->arg_len, i->width);
	if (((i->flags & ZERO) && (i->width > i->arg_len)) || i->prec > i->arg_len)
		print_prec_flag(i);
	// printf(" >>PREC prec = %d, len = %d, widt = %d<< ", i->prec, i->arg_len, i->width);

	// printf("prec res = %d\n", i->res);
	// printf("\nprec res = %d, len = %d\n", i->res, i->arg_len);
	// ft_printf("e");
	// printf(" >>af prec %d<< ", i->width);
	// printf(" >> PC w = %d, prec = %d<< ", i->width, i->prec);
	// ft_printf("x");
	ft_putnbr_l(i->cur_arg);
	// ft_printf("f");


	// printf(" >>NBR = %d, len = %d, widt = %d<< ", i->prec, i->arg_len, i->width);

	// if (i->flags & NEGATIVE)
	// 	i->res += i->arg_len - 1;
	// else
		i->res += i->arg_len;

	// printf("\nputnbr res = %d, len = %d\n", i->res, i->arg_len);

	i->width -= i->arg_len;
	// if (i->flags & DOT)
	// {
	// 	if (i->flags & NEGATIVE)
	// 		i->width -= i->arg_len + 1;
	// 	else
	// 		i->width -= i->arg_len;
	// }

	// printf(" >>WID = %d, len = %d, widt = %d<< ", i->prec, i->arg_len, i->width);

	// printf(" >>af num %d<< ", i->width);
	// printf(" >> N w = %d, prec = %d<< ", i->width, i->prec);

	// if (i->flags & MINUS && i->width > 0)
	// 	i->res += ft_putchar_multi(' ', i->width);


	// printf(" >>MIN= %d, len = %d, widt = %d<< ", i->prec, i->arg_len, i->width);
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
	// printf(" >>end res = %d<< ", i->res);
	return (0);
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



	// FINAL FIX
	// v1
	// long long	cur_arg;
	// if (info->flags & LLONG)
	// 	cur_arg = va_arg(args, long long);
	// else if (info->flags & LONG)
	// 	cur_arg = (long long)va_arg(args, long);
	// else
	// 	cur_arg = (long long)va_arg(args, int);

	// v2
	// assign_dic(info, args);
	// fix argumenst to info->cur_arg instead of &cur_arg
	// FINAL FIX

	while (info->width > 1 && !(info->flags & MINUS))
	{
		if (info->flags & ZERO)
			info->res += write(1, "0", 1);
		else
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
	return (0);
}

void	assign_octal(t_info *info)
{
	unsigned long long	tmp;
	int					i;

	// if (info->flags & LLONG)
	// if (info->flags & LONG)
	// 	info->cur_arg = va_arg(args, unsigned long long);
	// else	// needed to be something still ??
	// 	info->cur_arg = (unsigned long long) va_arg(args, unsigned int);
	i = 1;
	tmp = 0;
	// 2147483648
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

void	assign_ouxX(t_info *i, va_list args)
{
	if (i->flags & LLONG)
		i->cur_arg = va_arg(args, unsigned long long);
	else if (i->flags & LONG)
		i->cur_arg = (unsigned long long) va_arg(args, unsigned long);
	else if (i->flags & SSHORT)
		i->cur_arg = (unsigned long long) (unsigned char) va_arg(args, unsigned int);
	else if (i->flags & SHORT)
		i->cur_arg = (unsigned long long) (unsigned short) va_arg(args, unsigned int);
	else
	{
		// ft_printf("X");
		i->cur_arg = (unsigned long long) va_arg(args, unsigned int);
	}
	// printf(" >%llu< ", i->cur_arg);

	// i->arg_len = count_digits(i->cur_arg);	// change to ULL
	// printf(" >>%llu<< ",i->cur_arg);
}

void	convert_octal(unsigned long long num, t_info *i)
{
	if (num >= 8)
	{
		convert_octal(num / 8, i);
		convert_octal(num % 8, i);
	}
	else
	{
		i->cur_arg = i->cur_arg * 10 + num;
	}
}

int	print_octal(t_info *i, va_list args)
{
	// OK
	assign_ouxX(i, args);
	// printf(" >>%llu<< ", i->cur_arg);	//	4294967294

	unsigned long long tmp;
	tmp = i->cur_arg;
	i->cur_arg = 0;
	convert_octal(tmp, i);

	// printf(" >>%llu<< ", i->cur_arg);
	i->arg_len = count_digits(i->cur_arg);
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

	return (0);
}

int	print_percent(t_info *i, va_list args)
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
	return (0);
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
	// printf(" >>len = %d, w = %d, arg = %llu<< ", i->arg_len, i->width, i->cur_arg);
	if (i->cur_arg == 0)
		return (print_zero_hex(i));
	if (i->flags & HASH)
		i->width -= 2;
	if (i->flags & ZERO && !(i->flags & MINUS))
	{
		if (!(i->flags & DOT))
			i->res += ft_putchar_multi(' ', i->width - i->arg_len);
		else if (i->prec > i->arg_len)
			i->res += ft_putchar_multi(' ', i->width - i->prec);
		else
			i->res += ft_putchar_multi(' ', i->width - i->arg_len);
		i->width = 0;
	}
	if (!(i->flags & ZERO) && i->width > i->prec && i->width > i->prec && !(i->flags & MINUS))
	{
		if (i->prec > i->arg_len)
		{
			i->res += ft_putchar_multi(' ', i->width - i->prec);
			i->width -= i->prec;
		}
		else
		{
			i->res += ft_putchar_multi(' ', i->width - i->arg_len);
			i->width -= i->arg_len;
		}
	}
	if (i->flags & HASH)
	{
		i->res += 2;
		ft_putchar('0');
		ft_putchar(i->hex);
	}
	// i->hex -= 23;

	if (!(i->flags & MINUS) && i->width > i->arg_len && i->width > i->prec)
	{
		// if (i->width > i->prec && i->width > i->arg_len)
		// {
			// if (i->flags & DOT && i->prec > i->arg_len)
			// 	i->res += ft_putchar_multi(' ', i->width - i->prec);
			// if (i->flags & ZERO && !(i->flags & DOT))
			if (i->flags & ZERO)
			{
				// ft_printf("a");
				i->res += ft_putchar_multi('0', i->width - i->arg_len);
			}
			// else
			// 	i->res += ft_putchar_multi(' ', i->width - i->arg_len);
		// }
	}

	if (i->prec > i->arg_len)
		i->res += ft_putchar_multi('0', i->prec - i->arg_len);

	print_hex(i->cur_arg, i->hex - 23);
	i->res += i->arg_len;
	if (i->flags & MINUS && i->width > i->arg_len && i->width > i->prec)
	{
		if (i->prec > i->arg_len)
			i->res += ft_putchar_multi(' ', i->width - i->prec);
		else
			i->res += ft_putchar_multi(' ', i->width - i->arg_len);
	}
	return (0);
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

	// printf(" >> len = %d, arg = %llu<< ", i->arg_len, i->cur_arg);

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
	return (0);
}

int	print_unsigned_long(t_info *i, va_list args)
{
	if ((i->flags & LONG) && !(i->flags & LLONG))
		i->flags |= LLONG;
	else if (!(i->flags & LONG))
		i->flags |= LONG;
	return (print_unsigned(i, args));
}

char	*assign_str(t_info *i, va_list args)
{
	char	*str;

	str = va_arg(args, char*);
	if (!str)
	{
		i->res += write(1, "(null)", 6);
		return (NULL);
	}
	if (ft_strlen(str) == 0)
	{
		i->arg_len = 0;
		i->prec = 0;
	}
	else
	{
		if (i->flags & DOT)
			i->arg_len = i->prec;
		else
			i->arg_len = (int)ft_strlen(str);
	}
	return (str);
}

int	print_str(t_info *i, va_list args)
{
	int		len;
	char	*str;

	len = 0;
	str = assign_str(i, args);
	if (!str)
		return (0);

	// if (i->flags & DOT)
	// 	i->arg_len = i->prec;
	// else
	// 	i->arg_len = (int)ft_strlen(str);

	if (!(i->flags & MINUS) && i->width > i->arg_len && i->width > i->prec)
	{
		if (i->flags & ZERO)
		{
			if (i->arg_len >= i->prec)
				i->res += ft_putchar_multi('0', i->width - i->arg_len);
			else
				i->res += ft_putchar_multi('0', i->width - i->prec);
		}
		else if (i->prec >= i->arg_len && i->flags & DOT)
			i->res += ft_putchar_multi(' ', i->width - i->prec);
		else
			i->res += ft_putchar_multi(' ', i->width - i->arg_len);
	}

	i->res += write(1, str, i->arg_len);

	// if (i->flags & DOT)
	// {
	// 	while (i->prec-- > 0)
	// 	{
	// 		ft_putchar(str[len++]);
	// 	}
	// 	i->res += len;
	// 	// i->width -= len;
	// }
	// else
	// {
	// 	ft_putstr(str);
	// 	// i->res += (int)ft_strlen(str);
	// 	i->res += i->arg_len;
	// }

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
	return (0);
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

	return (0);
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

void		float_calc_total(t_info *i)
{
	i->f_total = i->arg_len;
	if (i->prec > i->f_dec_len)
		i->f_total += i->prec;	// can be 0 if rounded, then prec
	else
		i->f_total += i->f_dec_len;
	if (i->flags & HASH || i->prec > 0)
		i->f_total++;
	// if (i->flags & PLUS || i->flags & NEGATIVE)	//	already in assing
	// 	i->f_total++;
}

// float_rounding(i);
void	float_rounding(t_info *i)
{
	// printf(" >>%llu<< ", i->f_dec_arg);

	if (i->f_dec_arg % 10 >= 5)
	{
		i->f_dec_arg += 10;
		// i->cur_arg++;

		// printf(" >>new %llu, prec = %d << ", i->f_dec_arg, i->prec);
		// if (count_digits(i->f_dec_arg) != i->prec + 1)	// rounded to next num	, TEST!
		if (count_digits(i->f_dec_arg) > i->prec + 1)	// rounded to next num	, TEST!
		{
			i->cur_arg++;

			if (i->cur_arg % 2 == 1 && i->f_dec_arg % 10 == 5)
			// if (i->cur_arg % 2 == 1)
				i->cur_arg--;
			i->f_dec_arg = 0;
		}
	}


	// if (i->f_dec_arg % 10 > 5)
	// {
	// 	i->cur_arg++;
	// 	i->f_dec_arg = 0;
	// }
	// // if (i->f_dec_arg % 10 >= 5)
	// else if (i->f_dec_arg % 10 == 5)
	// {
	// 	i->f_dec_arg += 10;
	// 	// printf(" >>new %llu, prec = %d << ", i->f_dec_arg, i->prec);
	// 	// if (count_digits(i->f_dec_arg) != i->prec + 1)	// rounded to next num	, TEST!
	// 	if (count_digits(i->f_dec_arg) > i->prec + 1)	// rounded to next num	, TEST!
	// 	{
	// 		i->cur_arg++;
	// 		i->f_dec_arg = 0;

	// 		// if (i->cur_arg % 2 == 1 && i->f_dec_arg % 10 == 5)
	// 		if (i->cur_arg % 2 == 1)
	// 			i->cur_arg--;
	// 	}
	// }




	// printf(" >>bef %llu<< ", i->f_dec_arg);
	i->f_dec_arg /= 10;		// return back to normal
	// printf(" >>last %llu<< ", i->f_dec_arg);
}

/*	rounding:
	if num if even
		round is down
	else up
*/

void	assign_float_to_ints(long double frac, t_info *i, int prec)
{
	i->cur_arg = (unsigned long long)frac;	// take whole num
	i->arg_len = count_digits(i->cur_arg);	// len of before .
	if (i->flags & NEGATIVE || i->flags & PLUS)	//	prefix
		i->arg_len++;

	frac -= (long double)i->cur_arg;	// 123.4 - 123 = 0.4

	// if (!(i->flags & DOT))
		// prec = 6;

	prec++;	//	take extra num for rounding

	while (prec-- > 0)
		frac *= 10;
	i->f_dec_arg = (unsigned long long)frac;

	// now f_dec has 1 extra num

	float_rounding(i);


	i->f_dec_len = count_digits(i->f_dec_arg);	// needed if len < prec, print 0

	float_calc_total(i);
	// printf("new frac = %llu\tnum = %llu\n", i->f_dec_arg, i->cur_arg);
	// printf("frac len = %d\tnum len = %d\n", i->f_dec_len, i->arg_len);

}

void	assign_float(t_info *i, va_list args)
{
	if (i->flags & LONG)
		i->f_arg = va_arg(args, long double);
	else
		i->f_arg = (long double) va_arg(args, double);

	// printf(" >> START %Lf<< ", i->f_arg);
	if (1 / i->f_arg < 0)
	{
		i->f_arg *= -1;
		i->flags |= NEGATIVE;
	}
	if (!(i->flags & DOT))
		i->prec = 6;
		// printf("num = '%.20Lf'\n", i->f_arg);
	assign_float_to_ints(i->f_arg, i, i->prec);
}

int	print_float(t_info *i, va_list args)
{
	assign_float(i, args);


	// if (i->width > i->arg_len + i->f_dec_len + 1 && !(i->flags & MINUS))
	// {
	// 	if (i->flags & ZERO)
	// 		i->res += ft_putchar_multi('0', i->width - (i->arg_len + i->f_dec_len + 1));
	// 	else
	// 		i->res += ft_putchar_multi(' ', i->width - (i->arg_len + i->f_dec_len + 1));
	// }

	/*
		width 	0 / ' '
		prefix	+ / -
		num
		dot
		prec
		minus	' '
	*/

	if (i->flags & SPACE && !(i->flags & NEGATIVE))
	{
		i->res += write(1, " ", 1);
		i->width--;
	}

	if (i->width > i->f_total && !(i->flags & MINUS) && !(i->flags & ZERO))
	{
		i->res += ft_putchar_multi(' ', i->width - i->f_total);
	}
		// ft_printf("a");

	// printf(" >>cur = %llu, w = %d, len = %d, farg = %llu, flen = %d<< ", i->cur_arg, i->width,
		// i->arg_len, i->f_dec_arg, i->f_dec_len);

	if (i->flags & NEGATIVE)
	{
		i->res += write(1, "-", 1);
	}
	else if (i->flags & PLUS)
		i->res += write(1, "+", 1);

		// ft_printf("b");
	if (i->flags & ZERO && i->width > i->f_total)
	{
		i->res += ft_putchar_multi('0', i->width - i->f_total);
	}

	ft_putnbr_l(i->cur_arg);
	i->res += i->arg_len;



	if (i->flags & HASH || i->prec > 0)
		i->res += write(1, ".", 1);
	if (i->prec != 0)
	{
		if (i->f_dec_arg == 0)
			i->res += ft_putchar_multi('0', i->prec);
		else
		{
			if (i->prec > i->f_dec_len)
				i->res += ft_putchar_multi('0', i->prec - i->f_dec_len);
			ft_putnbr_l(i->f_dec_arg);
		}
		i->res += i->prec;
	}
	if (i->flags & MINUS && i->width > i->f_total)
		i->res += ft_putchar_multi(' ', i->width - i->f_total);

	// if (i->flags & NEGATIVE || i->flags & PLUS)
	// 	print_prefix_flag(i);

	// if (i->f_dec_len + 1 > i->width)
	// {
	// 	if (i->flags & MINUS)
	// 		i->flags ^= MINUS;
	// 	i->width = 1;
	// }
	// if (i->flags & HASH)
	// 	i->arg_len--;	//	. counts as width in arg len

	// if (i->flags & HASH || i->prec != 0)
	// 	i->res += write(1, ".", 1);

	// if (i->prec != 0)
	// {
	// 	ft_putnbr_l(i->f_dec_arg);
	// 	i->res += i->f_dec_len;
	// }

	// if (i->flags & MINUS && i->width )

	return (0);
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
			// info->res += g_disp_table[i](info, args);	// no need for i->res +=
			g_disp_table[i](info, args);	// no need for i->res +=
			info->i++;
			return (1);
		}
		i++;
	}
	// info->res += write(1, &str[0], 1);
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
			// if (!check_specifier(&str[info.i], &info, args))
			// 	exit_error("error, specifier not found!\n");
			check_specifier(&str[info.i], &info, args);
			// check_specifier(&str[info.i], &info, args);
			// info.i++;

			// info.res += 100;


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











































/*
%o intmin minmax
-2147483648
INT_MAX	Maximum value for a variable of type int.	2147483647
*/

// int main(void)
// {
// // printf("%.18Lf\n", 191231232.99999999l);
// // ft_printf("%.18Lf\n", 191231232.99999999l);
// // printf("%.19Lf\n", 191231232.99999999l);
// // ft_printf("%.19Lf\n", 191231232.99999999l);
// // printf("%.20Lf\n", 191231232.99999999l);
// // ft_printf("%.20Lf\n", 191231232.99999999l);
// //     printf("%.30Lf\n", 191231232.99999999l);
// //     ft_printf("%.30Lf\n", 191231232.99999999l);
// //     printf("%.40Lf\n", 191231232.99999999l);
// //     ft_printf("%.40Lf\n", 191231232.99999999l);
// //     printf("%.50Lf\n", 191231232.99999999l);
// //     ft_printf("%.50Lf\n", 191231232.99999999l);
// 	printf("%.0f\n", 0.5);
// 	ft_printf("%.0f\n\n", 0.5);
// 	printf("%.0f\n", 1.5);
// 	ft_printf("%.0f\n\n", 1.5);
// 	printf("%.0f\n", 2.5);
// 	ft_printf("%.0f\n\n", 2.5);
// 	printf("%.0f\n", 3.5);
// 	ft_printf("%.0f\n\n", 3.5);
// 	printf("%.0f\n", 4.5);
// 	ft_printf("%.0f\n\n", 4.5);
// 	printf("%.0f\n", 5.5);
// 	ft_printf("%.0f\n\n", 5.5);
// 	printf("%.1f\n", 5.09);
// 	ft_printf("%.1f\n\n", 5.09);
// 	// printf("%.5f\t%.3f\n", 5.12, 5.999541);
// 	// ft_printf("%.5f\t%.3f\n", 5.12, 5.999541);
//     // printf("|%.Lf|\n", -0.0l);
//     // ft_printf("|%.Lf|\n", -0.0l);
//     // printf("|%.3Lf|\n", -0.0l);
//     // ft_printf("|%.3Lf|\n", -0.0l);
//     // printf("|%.3Lf|\n", 0.0l);
//     // ft_printf("|%.3Lf|\n", 0.0l);

// // printf("|%.2f|\n", 4.9999435999f);
// // ft_printf("|%.2f|\n", 4.9999435999f);
// printf("|%.2f|\n", -4.9999435999f);
// ft_printf("|%.2f|\n", -4.9999435999f);
// // printf("|%.2Lf|\n", 4.9999435999l);
// // ft_printf("|%.2Lf|\n", 4.9999435999l);
//     // printf("|%.1Lf|\n", 4.99999999l);
//     // ft_printf("|%.1Lf|\n", 4.99999999l);
//     // printf("|%.4Lf|\n", 4.99999999l);
//     // ft_printf("|%.4Lf|\n", 4.99999999l);
// // printf("|%.2Lf|\n", -4.9999435999l);
// // ft_printf("|%.2Lf|\n", -4.9999435999l);
//     // printf("|%.1Lf|\n", -4.99999999l);
//     // ft_printf("|%.1Lf|\n", -4.99999999l);
//     // printf("|%.4Lf|\n", -4.99999999l);
//     // ft_printf("|%.4Lf|\n", -4.99999999l);



// 	// int a = -2147483648, b = 2147483647;
// 	// // int a = -2, b = 21474846;
// 	// // int a = -2, b = 21473607;
// 	// ft_printf("|%o|\n", a);
// 	// printf("|%o|\n", a);
// 	// ft_printf("|%o|\n", b);
// 	// printf("|%o|\n", b);
// 	// ft_printf("|%o|\n", 1001);
// 	// printf("|%o|\n", 1001);

// 	// printf("|%030.3x|\n", 432134);
// 	// ft_printf("|%030.3x|\n", 432134);
// 	// printf("|%#030.3x|\n", 432134);
// 	// ft_printf("|%#030.3x|\n", 432134);

// // printf("\n\n\n");
// // printf("|%.3f|\n", 0.0005f);
// // ft_printf("|%.3f|\n", 0.0005f);
//     // printf("|%.10f|\n", 0.0005f);
//     // ft_printf("|%.10f|\n", 0.0005f);
//     // printf("|%.12f|\n", 0.0005f);
//     // ft_printf("|%.12f|\n", 0.0005f);
// // printf("|%.3f|\n", -0.0005f);
// // ft_printf("|%.3f|\n", -0.0005f);
//     // printf("|%.10f|\n", -0.0005f);
//     // ft_printf("|%.10f|\n", -0.0005f);
//     // printf("|%.12f|\n", -0.0005f);
//     // ft_printf("|%.12f|\n", -0.0005f);
// // printf("|%.10Lf|\n", 0.0005l);
// // ft_printf("|%.10Lf|\n", 0.0005l);
// //     printf("|%.12Lf|\n", 0.0005l);
// //     ft_printf("|%.12Lf|\n", 0.0005l);
// 	// printf("\n");
// // printf("|%.10Lf|\n", -0.0005l);
// // ft_printf("|%.10Lf|\n", -0.0005l);
//     printf("\n");
// 	// printf("|%.12Lf|\n", -0.0005l);
//     // ft_printf("|%.12Lf|\n", -0.0005l);
// // printf("|%+.5f|\n", 0.000001f);
// // ft_printf("|%+.5f|\n", 0.000001f);
// // printf("|%+2.f|\n", 99.9f);
// // ft_printf("|%+2.f|\n", 99.9f);
// // printf("|%-.10f|\n", 42.73819123f);
// // ft_printf("|%-.10f|\n", 42.73819123f);
// // printf("|% -14.12f|\n", 0.0005f);
// // ft_printf("|% -14.12f|\n", 0.0005f);

// //	undefined
// // printf("%0-12s\n", NULL);
// // ft_printf("%0-12s\n", NULL);
// // printf("%0-12\n", "moi");
// // ft_printf("%0-12\n", "moi");
// // printf("%0-12%\n", "moi");
// // ft_printf("%0-12%\n", "moi");
// // printf("%.d\n", -5, 123);
// // ft_printf("%.d\n", -5, 123);
// // printf("%.d\n", -5, -10, 123);
// // ft_printf("%.d\n", -5, -10, 123);
// // printf("%.hhhhhhhhhhhllhlhlhlhd\n", -5, -10, 123l);
// // ft_printf("%.hhhhhhhhhhhllhlhlhlhd\n", -5, -10, 123l);
// // printf("%.*hhhhhhhhhzzjjjlhlhlhd\n", -5, -10, 123l);
// // ft_printf("%.*hhhhhhhhhzzjjjlhlhlhd\n", -5, -10, 123l);
// // printf("|%0-12s|\n", NULL);
// // ft_printf("|%0-12s|\n", NULL);

// // printf("|%0-12|\n", "moi");
// // ft_printf("|%0-12|\n", "moi");
// // printf("|%0-12|\n", "moi");
// // ft_printf("|%0-12|\n", "moi");
// // printf("|%.d|\n", -5, 123);
// // ft_printf("|%.d|\n", -5, 123);`

// // printf("|%.d|\n", -5, -10, 123);
// // ft_printf("|%.d|\n", -5, -10, 123);

// // printf("|%.hhhhhhhhhhhllhlhlhlhd|\n", -5, -10, 123l);
// // ft_printf("|%.hhhhhhhhhhhllhlhlhlhd|\n", -5, -10, 123l);

// // printf("|%.*hhhhhhhhhzzjjjlhlhlhd|\n", -5, -10, 123l);
// // ft_printf("|%.*hhhhhhhhhzzjjjlhlhlhd|\n", -5, -10, 123l);
//     // printf("|%.*d|\n", -5, 123);
//     // ft_printf("|%.*d|\n", -5, 123);
//     // printf("|%*.*d|\n", -5, -10, 123);
//     // ft_printf("|%*.*d|\n", -5, -10, 123);
//     // printf("|%*.*hhhhhhhhhhhllhlhlhlhd|\n", -5, -10, 123l);
//     // ft_printf("|%*.*hhhhhhhhhhhllhlhlhlhd|\n", -5, -10, 123l);
//     // printf("|%*.*hhhhhhhhhzzjjjlhlhlhd|\n", -5, -11, 123l);
//     // ft_printf("|%*.*hhhhhhhhhzzjjjlhlhlhd|\n", -5, -11, 123l);
//     // printf("|%*.*d|\n", -5, -11, 123l);
//     // ft_printf("|%*.*d|\n", -5, -11, 123l);
// 	//	01 2=* 3=. 4=* 5=d
// 	//	0*	1.	2*	3d
//     // printf("|%*.*hhhhhhhhhzzjjjlhlhlhd|\n", 5, 10, 123l);
//     // ft_printf("|%*.*hhhhhhhhhzzjjjlhlhlhd|\n", 5, 10, 123l);
// }

// 	int a = 0, b = 0;
//   a = ft_printf("|% |\n");
//   b = printf("|% |\n");
// //   1. (    1) --> <--
// //   2. (    0) --><--
// printf("a = %d, b = %d\n", a, b);

// 	a = 0, b = 0;
//   a = ft_printf("|% h|\n");
//   b = printf("|% h|\n");
// //   1. (    2) --> h<--
// //   2. (    0) --><--
// printf("a = %d, b = %d\n", a, b);

// 	a = 0, b = 0;
//   a = ft_printf("|%lhl|\n", 9223372036854775807);
//   b = printf("|%lhl|\n", 9223372036854775807);
// //   1. (    3) -->lhl<--
// //   2. (    0) --><--
// printf("a = %d, b = %d\n", a, b);

// 	a = 0, b = 0;
//   a = ft_printf("|%lhlz|\n", 9223372036854775807);
//   b = printf("|%lhlz|\n", 9223372036854775807);
// //   1. (    4) -->lhlz<--
// //   2. (    0) --><--
// printf("a = %d, b = %d\n", a, b);

// 	a = 0, b = 0;
//   a = ft_printf("|%zj|\n", 9223372036854775807);
//   b = printf("|%zj|\n", 9223372036854775807);
// //   1. (    2) -->zj<--
// //   2. (    0) --><--
// printf("a = %d, b = %d\n", a, b);

// 	a = 0, b = 0;
//   a = ft_printf("  |%lhh|\n", 2147483647);
//   b = printf("  |%lhh|\n", 2147483647);
// //   1. (    3) -->lhh<--
// //   2. (    0) --><--
// printf("a = %d, b = %d\n", a, b);

// }


// // # 0002
//   ft_printf("|% |\n");
//   printf("|% |\n");
// //   1. (    1) --> <--
// //   2. (    0) --><--

// // # 0003
//   ft_printf("|% h|\n");
//   printf("|% h|\n");
// //   1. (    2) --> h<--
// //   2. (    0) --><--

// // // # 0015 (int)
//   ft_printf("|%jx|\n", 4294967295);
//   printf("|%jx|\n", 4294967295);
// //   1. (    2) -->jx<--
// //   2. (    8) -->ffffffff<--

// // # 0016 (int)
//   ft_printf("|%jx|\n", 4294967296);
//   printf("|%jx|\n", 4294967296);
// //   1. (    2) -->jx<--
// //   2. (    9) -->100000000<--

// // # 0017 (int)
//   ft_printf("|%jx|\n", -4294967296);
//   printf("|%jx|\n", -4294967296);
// //   1. (    2) -->jx<--
// //   2. (   16) -->ffffffff00000000<--

// // # 0018 (int)
//   ft_printf("|%jx|\n", -4294967297);
//   printf("|%jx|\n", -4294967297);
// //   1. (    2) -->jx<--
// //   2. (   16) -->fffffffeffffffff<--

// // # 0020 (char *)
//   ft_printf("|%010s| is a string\n", "this");
//   printf("|%010s| is a string\n", "this");
// //   1. (   22) -->      this is a string<--
// //   2. (   22) -->000000this is a string<--

// // # 0022 (char)
//   ft_printf("|%05c|\n", 42);
//   printf("|%05c|\n", 42);
// //   1. (    5) -->    *<--
// //   2. (    5) -->0000*<--

// // # 0034 (intmax_t)
//   ft_printf("|%jd|\n", 9223372036854775807);
//   printf("|%jd|\n", 9223372036854775807);
// //   1. (    2) -->jd<--
// //   2. (   19) -->9223372036854775807<--

// // # 0035 (intmax_t)
//   ft_printf("|%jd|\n", -9223372036854775808);
//   printf("|%jd|\n", -9223372036854775808);
// //   1. (    2) -->jd<--
// //   2. (   20) -->-9223372036854775808<--

// // # 0036 (ssize_t)
//   ft_printf("|%zd|\n", 4294967295);
//   printf("|%zd|\n", 4294967295);
// //   1. (    2) -->zd<--
// //   2. (   10) -->4294967295<--

// // # 0037 (ssize_t)
//   ft_printf("|%zd|\n", 4294967296);
//   printf("|%zd|\n", 4294967296);
// //   1. (    2) -->zd<--
// //   2. (   10) -->4294967296<--

// // # 0038 (ssize_t)
//   ft_printf("|%zd|\n", -0);
//   printf("|%zd|\n", -0);
// //   1. (    2) -->zd<--
// //   2. (    1) -->0<--

// // # 0039 (ssize_t)
//   ft_printf("|%zd|\n", -1);
//   printf("|%zd|\n", -1);
// //   1. (    2) -->zd<--
// //   2. (    2) -->-1<--

// // # 0040 (intmax_t)
//   ft_printf("|%ju|\n", 4999999999);
//   printf("|%ju|\n", 4999999999);
// //   1. (    2) -->ju<--
// //   2. (   10) -->4999999999<--

// // # 0041 (size_t)
//   ft_printf("|%ju|\n", 4294967296);
//   printf("|%ju|\n", 4294967296);
// //   1. (    2) -->ju<--
// //   2. (   10) -->4294967296<--

// // # 0042 (unsigned long)
//   ft_printf("|%U|\n", 4294967295);
//   printf("|%U|\n", 4294967295);
// //   1. (    1) -->U<--
// //   2. (   10) -->4294967295<--

// // # 0043 (unsigned long)
//   ft_printf("|%hU|\n", 4294967296);
//   printf("|%hU|\n", 4294967296);
// //   1. (    1) -->U<--
// //   2. (   10) -->4294967296<--

// // # 0044 (unsigned long)
//   ft_printf("|%U|\n", 4294967296);
//   printf("|%U|\n", 4294967296);
// //   1. (    1) -->U<--
// //   2. (   10) -->4294967296<--

// // # 0048 (unsigned long long)
//   ft_printf("|%lhl|\n", 9223372036854775807);
//   printf("|%lhl|\n", 9223372036854775807);
// //   1. (    3) -->lhl<--
// //   2. (    0) --><--

// // # 0049 (unsigned long long)
//   ft_printf("|%lhlz|\n", 9223372036854775807);
//   printf("|%lhlz|\n", 9223372036854775807);
// //   1. (   22) -->TERM_PROGRAM=iTerm.app<--
// //   2. (    0) --><--

// // # 0050 (unsigned long long)
//   ft_printf("|%zj|\n", 9223372036854775807);
//   printf("|%zj|\n", 9223372036854775807);
// //   1. (    2) -->zj<--
// //   2. (    0) --><--

// // # 0051 (unsigned long)
//   ft_printf("|%lhh|\n", 2147483647);
//   printf("|%lhh|\n", 2147483647);
// //   1. (    3) -->lhh<--
// //   2. (    0) --><--

// // # 0053 (int)
//   ft_printf("|@main_ftprintf: %####0000 33..1..#00d\\n|\n", 256);
//   printf("|@main_ftprintf: %####0000 33..1..#00d\\n|\n", 256);
// //   1. (   77) -->@main_ftprintf:                               00000000000000000000000000256\\n<--
// //   2. (   51) -->@main_ftprintf:                               256\\n<--

// // # 0054 (int)
//   ft_printf("|@main_ftprintf: %####0000 33..1d|\n", 256);
//   printf("|@main_ftprintf: %####0000 33..1d|\n", 256);
// //   1. (   75) -->@main_ftprintf:                               00000000000000000000000000256<--
// //   2. (   49) -->@main_ftprintf:

// /*
// a -	b	space		x
// b - c	width		x
// c - d	prefix
// d - e	precision	x
// e - f	nbr			x
// 30 					+		  3
//                               256
// */

// 	// ft_printf("|% |\n");
// 	// printf("|% |\n");
// 	// ft_printf("|% |\n");
// 	// printf("%.16f\n", 1.15);
// 	// printf("%.15f\n", 1.15);
// 	// printf("%f\n", 1.15);
// 	// printf("%.20f\n", 1.01);

// 	//   ft_printf("|% h|");
// //   1. (    2) --> h<--
// //   2. (    0) --><--
// 	// ft_printf("|%jx|\n", 4294967296);
// 	// printf("|%jx|\n", 4294967296);
// 	// ft_printf("|% |\n");
// 	// printf("|% |\n");
// 	// // test_d();

// 	// ft_printf("|% h|\n");
// 	// printf("|% h|\n");
// 	printf("\n");
// }


// int main(void)
// {
// 	// sizes();
// 	// maxes();

// 	// //	--- d ---
// 	test_d();
// 	// spacet();
// 	// widt();
// 	// plust();
// 	// prect();
// 	// zerot();
// 	// minust();

// 	// percent();
// 	// chart();
// 	// octals();
// 	// hext();
// 	// unsigt();
// 	// strt();
// 	// adrt();
// 	// printed();

// 	// floatt();

// }

	/*	NOT WORKING
		+03.0	arg 0
		+03.8	arg 0
		+08.0	all		(zeroes comes after +, padding to num, not width)
		+-8.0	all
		+-8.3	0


	*/

	// double	z = 0, fm = 100.1234, f = -100.1234;
	// printf("%-8s", "%+08.0f");
	// printf("|%+08.0f|\t|%+08.0f|\t|%+08.0f|\n", z, fm , f);
	// ft_printf("\t|%+08.0f|\t|%+08.0f|\t|%+08.0f|\n", z, fm , f);

	// printf("%-8s", "%f");
	// printf("|%f|\n", (double)0);
	// ft_printf("\t|%f|\n", (double)0);
	// printf("num = 6985.123459876\n");
	// ft_printf("|%.2f|\n", 6985.123459876);	//	6985.12 3459876000197
	// printf("|%.2f|\n", 6985.123459876);	//	6985.12 3459876000197

	// ft_printf("|%f|\n", 6985.123459876);	//	6985.123459 876000197
	// printf("|%f|\n", 6985.123459876);	//	6985.123459 876000197

	// ft_printf("|%.10f|\n", 6985.123459876);	//	6985.1234598760 00197
	// printf("|%.10f|\n", 6985.123459876);	//	6985.1234598760 00197

	// ft_printf("%-8s|%f|\n", "%f", 1.1);
	// printf("%-8s|%f|\n", "%f", 1.1);
	// printf("\n\n\n");
	// printf("print\t%.10f\n", 6985.123459876);
	// ft_printf("  %.10f", 6985.123459876);
	// printf("num = 100.525\n");
	// ft_printf("%f", 100.525);
	// printf("num = 6985123.12345987610101789123\n");
	// ft_printf("%f", 6985123.12345987610101789123);
	// printf("num = 1234567891.4\n");
	// ft_printf("%f", 1234567891.4);
	// printf("num = 7.1234567891234567\n");
	// ft_printf("%f", 7.1234567891234567);

// 	printf("\n");
// }


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
