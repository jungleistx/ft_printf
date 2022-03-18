/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvuorenl <rvuorenl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:10:08 by rvuorenl          #+#    #+#             */
/*   Updated: 2022/03/18 18:11:42 by rvuorenl         ###   ########.fr       */
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

void	ft_putchar_multi(char c, int i)
{
	while (i-- > 0)
		write(1, &c, 1);
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




// 	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-
// 	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-
// 	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-
// 	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-


// digits in num	DONE
int	count_digits(unsigned long long num)
{
	int	res;

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
	// info->
}

// d hd hhd ld, i hi hhi li, o hho ho lo llo, u hu hhu lu llu, x hx hhx lx llx  = unsig long long
// lld lli = reverse if minus, unsig long long
// c = - && -num
// s = num && (-num??)

void	check_width(const char* str, t_info *info, va_list args)
{
	int	i;
	int	tmp;

	i = 0;
	if (ft_isdigit(str[i]))
	{
		info->width = ft_atoi(&str[i]);
		i += count_digits((unsigned long long)info->width);
	}
	if (str[i++] == '*')
		info->width = va_arg(args, int);
	if (str[i] == '.')
	{
		info->flags |= DOT;
		if (str[++i] == '*')
		{
			info->prec = va_arg(args, int);
			// info->i++; 	// what
		}
		else
		{
			info->prec = ft_atoi(&str[i]);
			i += count_digits((unsigned long long)info->prec);
		}
	}
}

int	check_specifier(const char *str, t_info *info, va_list args)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (str[j] == 'h')
	{
		if (str[++j] == 'h')
			j++;
	}
	else if (str[j] == 'l')
	{
		if (str[++j] == 'l')
			j++;
	}
	while (SPECS[i])	// "diouxXncspf" etc
	{
		if (SPECS[i++] == str[j])
		{
			info->i += j;	//	check if correct pos
			return (1);
		}
	}
	return (0);
}

//should return -1 if error ?
int	check_flags(const char *str, t_info *info, va_list args)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			info->flags |= SPACE;
		else if (str[i] == '+')
			info->flags |= PLUS;
		else if (str[i] == '-')
			info->flags |= MINUS;
		else if (str[i] == '0')
			info->flags |= ZERO;
		else if (str[i] == '#')
			info->flags |= HASH;
		else	// this point we have flags (only)
		{
			check_width(str, info, args);
			if (!check_specifier(str, info, args))
				return (0);
			return ;
		}
		i++;
	}
}
// 				-
// 		% [flags]	[width]		[.precision]	[length]	specifier


// void	check_length(const char *s, t_info *info)
// {
// 	if (s[info->i] == 'l' && s[info->i + 1] == 'l')
// 		info->flags |= (1 << 4);
// 	while (s[info->i] == 'l' || s[info->i] == 'h')
// 		info->i++;
// }




int	ft_printf(const char *str, ...)
{
	int		n;
	va_list	args;
	t_info	info;

	reset_info(&info);
	va_start(args, str);
	info.i = 0;
	while (str[info.i])
	{
		n = 0;
		while (str[info.i] != '%' && str[info.i] != '\0')
		{
			info.i++;
			n++;
		}
		info.res += n;
		// if (n > 0)		// commented for testing, UNCOMMENT
			// write(1, &str[info.i - n], n);
		if (str[info.i++] == '%')
		{
			// get_info_specifier(&str[i], args, &info);
			if (!check_flags(&str[info.i], &info, args))
				return (-1);
			// check_specifier()
			if (!check_error_input(&info, str[info.i]))
				return (-1);
			// info.res += check_specifier(&str[info.i], &info, args);
			break ;

			// info.flags = 0;
		}
	}
	va_end(args);
	return (info.res);
}


int main(void)
{
	// sizes();
	// maxes();
	tests();


}

/*	main tests

printf("\n|");
	ft_printf("hello '%d'", 42);
	printf("|\n");

	printf("\n|");
	ft_printf("hello '%0d'", 42);
	printf("|\n");

	printf("\n|");
	ft_printf("hello '%0d'", 42);
	printf("|\n");

	printf("\n|");
	ft_printf("hello '%0 -  -  0 -d'", 42);
	printf("|\n");

	printf("\n|");
	ft_printf("hello '%+-d'", 42);
	printf("|\n");

	int x = 42;
	ft_printf("|random '%d'\n'%d' another '%d'|\n", x, x + x, x * 5);
	printf("|random '%d'\n'%d' another '%d'|\n", x, x + x, x * 5);
	ft_printf("|\n%d * %d = %d\n|", 14, 2, 14*2);
	printf("|\n%d * %d = %d\n|", 14, 2, 14*2);



*/










// 	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-
// 	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-
// 	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-
// 	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-
// 	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-












// void check_type(void *ptr, char type)	//UNFINISHED
// {
// 	unsigned long long num;

// 	if (type == 'd')
// 	{
// 		if (*(int*)ptr < 0)
// 			num = (unsigned long long) (-1 * (*(int*)ptr));
// 		else
// 			num = (unsigned long long)*(int*)ptr;

// 	}
// 	else if (type == 'l')
// 	{
// 		// if (-9223372036854775808)
// 		if (*(long long*)ptr < 0)
// 			num = (unsigned long long) (-1 * (*(long long*)ptr));
// 		else
// 			num = (unsigned long long)*(long long*)ptr;
// 	}
// 	else if (type == 's')
// 	{
// 		if (*(short*)ptr < 0)
// 			num = (unsigned long long) (-1 * (*(short*)ptr));
// 		else
// 			num = (unsigned long long)*(short*)ptr;
// 	}
// 	else
// 		num = 0;

// 	printf("%llu\n", num);
// }

// int	h_flag_signed(void *ptr)
// {
// 	short	num;
// 	int		res;

// 	res = 0;
// 	num = (short)*(int*)ptr;
// 	res = count_numbers(num, 's');	// takes type as argument

// 	return (res);

// }

// int	h_flag_unsigned(void *ptr, char type)
// {
// 	unsigned short	num;
// 	int				res;

// 	res = 0;
// 	num = 0;
// 	if (type == 'd' || type == 'i')
// 	{
// 		if (*(int*)ptr < 0)
// 			num = *(int*)ptr * -1;
// 		}
// 		else
// 			num = (short)

// 	}
// 	else if (type == 'o' || type == 'u' || type == 'x' || type == 'X')
// 	{
// 		num = (unsigned short)*(unsigned int*)ptr;
// 	}
// 	return (res);

// }




// int	check_specifiers(const char *s, t_info *info, va_list args)
// {
// 	int		i;

// 	i = 0;
// 	if (str[i] == '%')
// 	{
// 		write(1, '%', 1);
// 		info->res++;
// 	}
// 	{
// 		info->cur_arg = va_arg(args, int);
// 		write(1, &info->cur_arg, 1);
// 		info->res++;
// 	}
// 	else if (s[i] == 's')
// 	{
// 		// flags ??
// 		// works straight away??						// CONT HERE
// 		info->str = va_arg(args, char*);
// 		info->res += ft_strlen(info->str);
// 		ft_putstr(info->str);
// 		// vs
// 		info->str = ft_strsub(va_arg(args, char*));
// 		info->res += ft_strlen(info->str);
// 		ft_putstr(info->str);
// 		ft_strdel(info->str);
// 		//
// 		i++;
// 	}
// 	else if (s[i] == 'c')
// 	else if (s[i] == 'p')
// 	{

// 	}
// 	else if (s[i] == 'f')
// 	{

// 	}

// 	else if (s[i] == 'l' || s[i] == 'c' || s[i] == 'd' || s[i] == 'i' || s[i] == 'l')
// 	{

// 	}
// 	else if (s[i] == 'u' || s[i] == 'x' || s[i] == 'X' || s[i] == 'o')
// 	{

// 	}


// 	else if (str[i] == 'c')
// 	{
// 		write(1, &str[i], 1);
// 		info->res++;
// 	}
// 	else if (str[i] == 'l')
// 	{
// 		if (str[i + 1] == 'l')
// 			// res++ ?


// 	}
// 	else if (str[i] == 'd' || str[i] == 'i')
// 	{

// 	}

// }


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
