/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvuorenl <rvuorenl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:10:08 by rvuorenl          #+#    #+#             */
/*   Updated: 2022/03/28 15:48:44 by rvuorenl         ###   ########.fr       */
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
	if (num < 0)
		res++;
	while (num != 0)
	{
		num /= 10;
		res++;
	}
	return (res);
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

void	reset_info(t_info *info)
{
	info->flags = 0;
	info->res = 0;
	info->tmpres = 0;
	info->i = 0;
	info->f_dec_len = 0;
	info->f_dec = 0;
	info->arg_len = 0;
	info->width = 0;
	// info->
}

void	reset_info_no_res(t_info *info)
{
	info->flags = 0;
	info->tmpres = 0;
	info->f_dec_len = 0;
	info->f_dec = 0;
	info->width = 0;
	info->arg_len = 0;
	// info->
}

// OK
int	dot_ast_flag(const char *str, t_info *info, va_list args)
{
	int	i;

	i = 0;
	if (str[i++] == '.')
	{
		info->flags |= DOT;
		if (str[i] == '*')
			info->prec = va_arg(args, int);
		else
			info->prec = ft_atoi(&str[i]);
		if (info->prec < 0)
			info->prec = 0;
		if (str[i] == '*')
			return (i);
		i = count_digits((long long)info->prec) - 1;
	}
	else
		info->width = va_arg(args, int);
	return (i);
}

//	OK
int	digit_flag(const char *str, t_info *info)
{
	int	i;

	i = 0;
	if (str[i] == '0')
		info->flags |= ZERO;
	else
	{
		info->width = ft_atoi(&str[i]);
		i = count_digits((long long)info->width);
		i--;
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
		info->flags |= SHORT;
}

void	check_flags(const char *str, t_info *info, va_list args)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == ' ')
			info->flags |= SPACE;
		else if (str[i] == '+')
			info->flags |= PLUS;
		else if (str[i] == '-')
			info->flags |= MINUS;
		else if (ft_isdigit((int)str[i]))
			i += digit_flag(&str[i], info);
		else if (str[i] == '#')
			info->flags |= HASH;
		else if (str[i] == '.' || str[i] == '*')
			i += dot_ast_flag(&str[i], info, args);
		else if (str[i] == 'l' || str[i] == 'L' || str[i] == 'h')
			check_len_flags(str[i], info);
		else	// this point we have flags + wid + prec
		{
			info->i += i;
			return ;
		}
	}
}

void	print_minus_flag(t_info *i)
{
	if (i->width > i->prec && i->prec > i->arg_len)
		i->res += ft_putchar_multi(' ', i->width - i->prec);
	else if (i->width > i->arg_len)
		i->res += ft_putchar_multi(' ', i->width - i->arg_len);
}

void	print_zero_flag(t_info *i)
{
	if (i->prec > i->arg_len)
		i->res += write(1, "0", i->prec - i->arg_len);
	else if (i->width > i->arg_len)
		i->res += write(1, "0", i->width - i->arg_len);
}

void	print_prefix_flag(t_info *i)
{
	if ((i->flags & PLUS) && !(i->flags & NEGATIVE))
	{
		i->res += write(1, "+", 1);
		i->prec--;
	}
	else if (i->flags & NEGATIVE)
	{
		i->res += write(1, "-", 1);
		i->prec--;
	}
}

void	print_space_flag(t_info *i)
{
	if (i->flags & NEGATIVE)
		i->prec++;
	else if (i->flags & PLUS)
	{
		i->res += write(1, "+", 1);
		i->flags ^= PLUS;
	}
	else
	{
		i->res += write(1, " ", 1);
		i->width--;
	}
}

void	neg_number(long long num, t_info *i)
{
	i->cur_arg = (unsigned long long) (num * -1);
	i->flags |= NEGATIVE;
	// i->prec--; 	// added from width, needs to be in dot version?

}

void	assing_number(t_info *i, va_list args)
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

	if ((i->flags & PLUS) && !(i->flags & NEGATIVE))
		i->arg_len++;	// ?
		// i->prec++;
}

int	print_number(t_info *i, va_list args)
{
	// printf(">>%d<<\n", i->width);
	assing_number(i, args);
	// printf(">>> w = %d, len = %d<<<", i->width, i->arg_len);
	if (i->flags & SPACE)
		print_space_flag(i);
	// printf("----width %d, prec %d----\n", i->width, i->prec);
	if (i->flags & DOT)
	{
		if (i->prec < i->arg_len)
			i->prec = i->arg_len;
	}
	// printf("----width %d, prec %d----\n", i->width, i->prec);
	// if (i->width > i->prec && (i->flags & DOT))
	if (i->width > i->arg_len && !(i->flags & MINUS))
		i->res += ft_putchar_multi(' ', i->width - i->arg_len);
	print_prefix_flag(i);
	if (i->flags & ZERO)
		print_zero_flag(i);
	ft_putnbr_l(i->cur_arg);
	if (i->flags & MINUS)
		print_minus_flag(i);
	return (i->res);
}

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

int	check_specifier(const char *str, t_info *info, va_list args)
{
	// printbin_2(&info->flags);
	// # define SPECS "dicouxXnspf"	// zu same as l (sizeof)
	int	i;

	i = 0;
	// special case for str[0] == 'n' ?
	while (SPECS[i])
	{
		if (SPECS[i] == str[0])
		{
			info->res += g_disp_table[i](info, args);
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

	reset_info(&info);
	va_start(args, str);
	while (str[info.i])
	{
		if (str[info.i] != '%')
			info.res += write_non_percent(str, &info);
		if (str[info.i] == '%')
		{
			if (str[++info.i] == '%')
				write_percent(&info);
			else
			{
				check_flags(&str[info.i], &info, args);
				if (!check_specifier(&str[info.i], &info, args))
					exit_error("error, specifier not found!\n");
					// exit_error("error\n");
			}
			reset_info_no_res(&info);
		}
	}
	va_end(args);
	return (info.res);
}


int main(void)
{
	// sizes();
	// maxes();
	// tests();

	int x = 42;
	int y = -42;
	int z = 0;

	// working		not all together??
	// d width

	printf("\n|%d| |%d| |%d| \n", x, y, z);
	ft_printf("|%d| |%d| |%d| \n", x, y, z);
	printf("\n|%2d| |%2d| |%2d| \n", x, y, z);
	ft_printf("|%2d| |%2d| |%2d| \n", x, y, z);
	printf("\n|%4d| |%4d| |%4d| \n", x, y, z);
	ft_printf("|%4d| |%4d| |%4d| \n", x, y, z);
	//
	printf("\t\t|%+-d| |%+-d| |%+-d|\n", x, y, z);
	ft_printf("\t\t|%+-d| |%+-d| |%+-d|\n", x, y, z);
	//
	printf("|%+-4d|\n", x);
	ft_printf("|%+-4d|\n", x);
	printf("|%+-4d| |%+-4d| |%+-4d|\n", x, y, z);
	ft_printf("|%+-4d| |%+-4d| |%+-4d|\n", x, y, z);

}
/*	NOT WORKING
- flag


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
