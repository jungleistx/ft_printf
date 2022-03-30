/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvuorenl <rvuorenl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:10:08 by rvuorenl          #+#    #+#             */
/*   Updated: 2022/03/30 14:52:01 by rvuorenl         ###   ########.fr       */
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
	if (num < 0)	//needed?, negative flag adds to arg_len ??
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

void	reset_info(t_info *info, int res)
{
	if (res == 0)
	{
		info->i = 0;
		info->res = 0;
	}
	info->flags = 0;
	info->tmpres = 0;
	info->f_dec_len = 0;
	info->f_dec = 0;
	info->arg_len = 0;
	info->width = 0;
	info->prec = 0;
	// info->
}

// void	reset_info_no_res(t_info *info)
// {
// 	info->flags = 0;
// 	info->tmpres = 0;
// 	info->f_dec_len = 0;
// 	info->f_dec = 0;
// 	info->width = 0;
// 	info->arg_len = 0;
// 	// info->
// }

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
	return (0);
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
	// printf(">>>flags start i = %d<<<", info->i);
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
			// printf(">>> flags end i = %d<<<", info->i);
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

void	print_prefix_flag(t_info *i)
{
	if ((i->flags & PLUS) && !(i->flags & NEGATIVE))
	{
		i->res += write(1, "+", 1);
		i->prec--;	// i->width-- || i->arg_len-- ???
	}
	else if (i->flags & NEGATIVE)
	{
		i->res += write(1, "-", 1);
		// i->prec--;
		// i->arg_len--;
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
	// printf(">>> assing i = %d<<<", i->i);
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
	// printbin_2(&i->flags);
	assing_number(i, args);
	// printf("&&& w = %d, len = %d&&&", i->width, i->arg_len);
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
	if (i->width > i->arg_len && !(i->flags & MINUS) && !(i->flags & ZERO))
		i->res += ft_putchar_multi(' ', i->width - i->arg_len);
	print_prefix_flag(i);

	// printf("&&& prefix w = %d, len = %d&&&", i->width, i->arg_len);
	// printf(">>> number bef zero i = %d<<<", i->i);
	if (i->flags & ZERO)
		print_zero_flag(i);
	// printf(">>> number aft zero i = %d, res = %d<<<\n", i->i, i->res);

	ft_putnbr_l(i->cur_arg);
	if (i->flags & MINUS)
		print_minus_flag(i);
	return (i->res);
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
	assing_number(info, args);
	while (info->width > 1 && !(info->flags & MINUS))
	{
		info->res += write(1, " ", 1);
		info->width--;
	}
	info->res += write(1, &info->cur_arg, 1);
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

void	assing_octal(t_info *info, va_list args)
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
	printf(" >> arg %lld, len %d<< ", info->cur_arg, info->arg_len);
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

int	print_octal(t_info *info, va_list args)
{
	// OK
	assing_octal(info, args);
	check_octal_flags(info);

	// if (info->width > info->arg_len || info->flags & ZERO)
	// 	info->res +=

	if ((info->flags & HASH) && (info->cur_arg > 0))
		info->res += write(1, "0", 1);
	// if (info->flags & MINUS)
	// if (info->flags & MINUS)

	// printf(" >>>octal tmp = %lld<<< ", tmp);
	ft_putnbr_l(info->cur_arg);

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

int	check_specifier(const char *str, t_info *info, va_list args)
{
	// printbin_2(&info->flags);
	// printf(">>> specs i = %d<<<", info->i);


	int	i;

	// special case for str[0] == 'n' ?
	i = 0;
	// # define SPECS "dicouxXnspf"	// zu same as l (sizeof)
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

	reset_info(&info, 0);
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
				// printf(">>> bef flags i = %d<<<", info.i);
				check_flags(&str[info.i], &info, args);
				// printf(">>> aft flags i = %d<<<", info.i);
				if (!check_specifier(&str[info.i], &info, args))
					exit_error("error, specifier not found!\n");
					// exit_error("error\n");
				// printf("print >>>i %d\t'%c'<<<", info.i, str[info.i]);
			}
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
	// tests();

	// octal

	printf("\n%-10s|%8o|\n", "%8o", 12345);
	printf("%-10s|%.8o|\n", "%.8o", 12345);
	printf("%-10s|%-o|\n", "%-o", 12345);
	printf("%-10s|%-8o|\n", "%-8o", 12345);
	printf("%-10s|%0o|\n", "%0o", 12345);
	printf("%-10s|%08o|\n", "%08o", 12345);

	printf("\n%-10s|%7.8o|\n", "%7.8o", 12345);
	printf("%-10s|%#7.8o|\n", "%#7.8o", 12345);
	printf("%-10s|%8.7o|\n", "%8.7o", 12345);
	printf("%-10s|%8.3o|\n", "%8.3o", 12345);
	printf("%-10s|%#8.7o|\n\n", "%#8.7o", 12345);


	// printf("\n%-10s|%o|\n", "%o", 0);
	// printf("%-10s|%#o|\n", "%#o", 0);
	// printf("%-10s|%#0o|\n", "%#0o", 0);
	// printf("%-10s|%#.o|\n", "%#.o", 0);
	// printf("%-10s|%#0.o|\n", "%#0.o", 0);
	// printf("%-10s|%.o|\n", "%.o", 0);
	// printf("%-10s|%0.o|\n", "%0.o", 0);
	// printf("%-10s|%.3o|\n", "%.3o", 0);
	// printf("%-10s|%0.3o|\n", "%0.3o", 0);

	// %d width prec zero tests
	// printf("\n|%04.5d|\n", 123);
	// ft_printf("|%04.5d|\n", 123);
	// printf("\n|%05.4d|\n", 123);
	// ft_printf("|%05.4d|\n", 123);
	// printf("\n|%4.5d|\n", 123);
	// ft_printf("|%4.5d|\n", 123);
	// printf("\n|%5.4d|\n", 123);
	// ft_printf("|%5.4d|\n", 123);

	// ft_printf("\n\n|%o|\n", 12345);
	// ft_printf("|%o|\n", 0);
	// ft_printf("|%o|\n", 8);


	// printf("\n|%o|\n", 12345);
	// ft_printf("|%o|\n", 12345);
	// printf("|%o|\n", 7);
	// ft_printf("|%o|\n", 7);
	// printf("|%o|\n", 8);
	// ft_printf("|%o|\n", 8);
	// printf("|%o|\n", 9);
	// ft_printf("|%o|\n", 9);
	// printf("|%o|\n", 0);
	// ft_printf("|%o|\n", 0);
	// printf("|%#o|\n", 12345);
	// ft_printf("|%#o|\n", 12345);
	// printf("|%#o|\n", 7);
	// ft_printf("|%#o|\n", 7);
	// printf("|%#o|\n", 8);
	// ft_printf("|%#o|\n", 8);
	// printf("|%#o|\n", 9);
	// ft_printf("|%#o|\n", 9);
	// printf("|%#o|\n", 0);
	// ft_printf("|%#o|\n", 0);



	// 						int x = 42;
	// 						int y = -42;
	// 						int z = 0;
	// printf("\n|%d| |%d| |%d| \n", x, y, z);
	// ft_printf("|%d| |%d| |%d| \n", x, y, z);
	// printf("|%2d| |%2d| |%2d| \n", x, y, z);
	// ft_printf("|%2d| |%2d| |%2d| \n", x, y, z);
	// printf("|%4d| |%4d| |%4d| \n", x, y, z);
	// ft_printf("|%4d| |%4d| |%4d| \n", x, y, z);
	// printf("|%+-d| |%+-d| |%+-d|\n", x, y, z);
	// ft_printf("|%+-d| |%+-d| |%+-d|\n", x, y, z);
	// printf("|%+-4d| |%+-4d| |%+-4d|\n", x, y, z);
	// ft_printf("|%+-4d| |%+-4d| |%+-4d|\n", x, y, z);
	// printf("\n|%i| |%i| |%i| \n", x, y, z);
	// ft_printf("|%i| |%i| |%i| \n", x, y, z);
	// printf("|%2i| |%2i| |%2i| \n", x, y, z);
	// ft_printf("|%2i| |%2i| |%2i| \n", x, y, z);
	// printf("|%4i| |%4i| |%4i| \n", x, y, z);
	// ft_printf("|%4i| |%4i| |%4i| \n", x, y, z);
	// printf("|%+-i| |%+-i| |%+-i|\n", x, y, z);
	// ft_printf("|%+-i| |%+-i| |%+-i|\n", x, y, z);
	// printf("|%+-4i| |%+-4i| |%+-4i|\n", x, y, z);
	// ft_printf("|%+-4i| |%+-4i| |%+-4i|\n", x, y, z);
	// printf("\n|%05d| |%05d| |%05d| \n", x, y, z);
	// ft_printf("|%05d| |%05d| |%05d| \n", x, y, z);
	// printf("\n|%05i| |%05i| |%05i| \n", x, y, z);
	// ft_printf("|%05i| |%05i| |%05i| \n", x, y, z);
	// printf("|%05.6d| |%05.6d| |%05.6d| \n", x, y, z);
	// ft_printf("|%05.6d| |%05.6d| |%05.6d| \n", x, y, z);


	// char ch = 'x';
	// printf("\n\n|%c| test\n", ch);
	// ft_printf("|%c| test\n", ch);
	// printf("|%*c| test\n",4,  ch);
	// ft_printf("|%*c| test\n",4,  ch);
	// printf("|%3c| test\n", ch);
	// ft_printf("|%3c| test\n", ch);
	// printf("|%-4c| test\n", ch);
	// ft_printf("|%-4c| test\n", ch);
	// char ch1 = 0;
	// printf("\n|%c|\n", ch1);
	// ft_printf("\n|%c|\n", ch1);



	// hex
	// printf("\n|%x|\n", 123456);
	// printf("|%x|\n", 123456);




	printf("\n");
}


/*
c
	no precision
	no space
	no 0
	no +

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
