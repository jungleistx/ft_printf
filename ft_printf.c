/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvuorenl <rvuorenl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:10:08 by rvuorenl          #+#    #+#             */
/*   Updated: 2022/03/11 18:08:29 by rvuorenl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>	// DELETE
#include <unistd.h>
#include <stdlib.h>
// #include "ft_printf.h" // all includes

# include <limits.h> 	// DELETE
# include <float.h>		// DELETE

void	sizes(void)			// DELETE
{
	printf("\n<type>\t\t\t<sizeof>\t<size in bits>\n");
	printf("\nchar \t\t\t%lu\t\t%lu\n", sizeof(char), sizeof(char)*8);
	printf("unsigned char \t\t%lu\t\t%lu\n", sizeof(unsigned char), sizeof(unsigned char)*8);
	printf("\nuint16_t \t\t%lu\t\t%lu\n", sizeof(uint16_t), sizeof(uint16_t)*8);
	printf("short \t\t\t%lu\t\t%lu\n", sizeof(short), sizeof(short)*8);
	printf("unsigned short \t\t%lu\t\t%lu\n", sizeof(unsigned short), sizeof(unsigned short)*8);
	printf("\nint \t\t\t%lu\t\t%lu\n", sizeof(int), sizeof(int)*8);
	printf("unsigned int \t\t%lu\t\t%lu\n", sizeof(unsigned int), sizeof(unsigned int)*8);
	printf("float \t\t\t%lu\t\t%lu\n", sizeof(float), sizeof(float)*8);
	printf("\ndouble \t\t\t%lu\t\t%lu\n", sizeof(double), sizeof(double)*8);
	printf("long \t\t\t%lu\t\t%lu\n", sizeof(long), sizeof(long)*8);
	printf("long long \t\t%lu\t\t%lu\n", sizeof(long long), sizeof(long long)*8);
	printf("unsigned long \t\t%lu\t\t%lu\n", sizeof(unsigned long), sizeof(unsigned long)*8);
	printf("unsigned long long \t%lu\t\t%lu\n", sizeof(unsigned long long), sizeof(unsigned long long)*8);
	printf("uint64_t \t\t%lu\t\t%lu\n", sizeof(uint64_t), sizeof(uint64_t)*8);
	printf("\nvoid*\t\t\t%lu\t\t%lu\n", sizeof(void*), sizeof(void*)*8);
	printf("char*\t\t\t%lu\t\t%lu\n", sizeof(char*), sizeof(char*)*8);
	printf("int*\t\t\t%lu\t\t%lu\n", sizeof(int*), sizeof(int*)*8);
	printf("float*\t\t\t%lu\t\t%lu\n", sizeof(float*), sizeof(float*)*8);
	printf("long*\t\t\t%lu\t\t%lu\n", sizeof(long*), sizeof(long*)*8);
	printf("long long*\t\t%lu\t\t%lu\n\n", sizeof(long long*), sizeof(long long*)*8);
}

void	maxes(void)
{
	printf("\n\t--- limits ---\n<type>\t\t\t<min_value>\t\t<max_value>\n\n");
	printf("unsigned short\t\t0\t\t\t%u\n",USHRT_MAX);
	printf("unsigned int\t\t0\t\t\t%u\n", UINT_MAX);
	printf("unsigned long\t\t0\t\t\t%lu\n", ULONG_MAX);
	printf("unsigned long long\t0\t\t\t%llu\n", ULLONG_MAX);
	printf("\nshort\t\t\t%d\t\t\t%d\n", SHRT_MIN, SHRT_MAX);
	printf("int\t\t\t%d\t\t%d\n", INT_MIN, INT_MAX);
	printf("long\t\t\t%ld\t%ld\n", LONG_MIN, LONG_MAX);
	printf("long long\t\t%lld\t%lld\n\n", LLONG_MIN, LLONG_MAX);
}

void nonpointer(void)		// DELETE
{
	char char_ptr[5] = {'a', 'b', 'c', 'd', 'e'};
	int int_ar[5] = {1, 2, 3, 4, 5};

	printf("\nadd of char_ptr = %p\n", char_ptr);
	printf("add of int_ar   = %p\n\n", int_ar);

	long non_pointer;
	non_pointer = (long) char_ptr; // 8 byte datatype can hold the value of an address
	int i = 0;
	while (i < 5)
	{
		printf("nonpointer points to 0x%08lx, value is %c\n", non_pointer, *((char*)non_pointer));
		printf("nonpointer = %ld\n\n", non_pointer);
		non_pointer += sizeof(char);
		i++;
	}
	printf("---\n\n");
	i = 0;
	non_pointer = (long) int_ar;

	while (i < 5)
	{
		printf("nonpointer points to %p, value is %d\n", (int*)non_pointer, *((int*)non_pointer));
		printf("nonpointer = %ld\n\n", non_pointer);
		non_pointer += sizeof(int);
		i++;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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














int	count_digits(int num)
{
	int	res;

	res = 0;
	// if (num < 0)		NEEDED? does it count - as a digit to padding
		// res++;
	while (num > 0)
	{
		num /= 10;
		res++;
	}
	return (res);
}

// int	specifiers(char *s, )

int	ft_printf(const char *str, ...)
{
	int		n;
	int		i;
	va_list	args;

	va_start(args, str);
	i = 0;
	while (str[i])
	{
		n = 0;
		if (str[i] != '%' || str[i] != '\0')
		{
			i++;
			n++;
		}
		if (n > 0)
			write(1, &str[i - n], n);
		if (str[i] == '%')
		{
			if (str[++i] == 'd')	// always i++
			{
				ft_putnbr(va_arg(args, int));
                i++;
			}
			// specifiers(&str[i])
			// if (str[++i] == 'd')
			// 	ft_putnbr(va_arg(args, int));
			// // else if (str[i] == )
			// i++;
		}
	}
	va_end(args);
	return (0);
}

void check_type(void *ptr, char type)	//UNFINISHED
{
	unsigned long long num;

	if (type == 'd')
	{
		if (*(int*)ptr < 0)
			num = (unsigned long long) (-1 * (*(int*)ptr));
		else
			num = (unsigned long long)*(int*)ptr;

	}
	else if (type == 'l')
	{
		// if (-9223372036854775808)
		if (*(long long*)ptr < 0)
			num = (unsigned long long) (-1 * (*(long long*)ptr));
		else
			num = (unsigned long long)*(long long*)ptr;
	}
	else if (type == 's')
	{
		if (*(short*)ptr < 0)
			num = (unsigned long long) (-1 * (*(short*)ptr));
		else
			num = (unsigned long long)*(short*)ptr;
	}
	else
		num = 0;

	printf("%llu\n", num);
}

int	h_flag_signed(void *ptr)
{
	short	num;
	int		res;

	res = 0;
	num = (short)*(int*)ptr;
	res = count_numbers(num, 's');	// takes type as argument

	return (res);

}

int	h_flag_unsigned(void *ptr, char type)
{
	unsigned short	num;
	int				res;

	res = 0;
	num = 0;
	if (type == 'd' || type == 'i')
	{
		if (*(int*)ptr < 0)
			num = *(int*)ptr * -1;
		}
		else
			num = (short)

	}
	else if (type == 'o' || type == 'u' || type == 'x' || type == 'X')
	{
		num = (unsigned short)*(unsigned int*)ptr;
	}
	return (res);

}



int main(void)
{
	sizes();
	maxes();

	// int x = 42;
	// ft_printf("|random '%d'\n'%d' another '%d'|\n", x, x + x, x * 5);
	// printf("|random '%d'\n'%d' another '%d'|\n", x, x + x, x * 5);
	// ft_printf("|\n%d * %d = %d\n|", 14, 2, 14*2);
	// printf("|\n%d * %d = %d\n|", 14, 2, 14*2);

	/* testcases

	int i = 42;
    float x = 100.5;

	printf("'%05d'\n", i); // 5 total length,
    printf("'%+d'\n", i);
    printf("'%-d'\n", i);
    printf("'%4d'\n", i);
    printf("'% d'\n", i);
    printf("\n'%-10.3f'\n", x); // 10 = total len, .3 = 3 after '.'
    printf("'%010.3f'\n", x); // 10 = total len, .3 = 3 after '.'
    printf("'%10.3f'\n", x); // 10 = total len, .3 = 3 after '.'
    printf("'%+10.3f'\n", x); // 10 = total len, .3 = 3 after '.'
    printf("\n%x\n", i);
    printf("%04X\n", i);
    printf("%#X\n", i);
    printf("'%#06X'\n", i);
	 */

}


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
