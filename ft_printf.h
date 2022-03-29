/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvuorenl <rvuorenl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:18:13 by rvuorenl          #+#    #+#             */
/*   Updated: 2022/03/29 15:11:09 by rvuorenl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>    // write
# include <stdlib.h>    // malloc free exit
// # include "./libft/libft.h"

//delete
# include <stdio.h>
# include <limits.h>
# include <float.h>


// only used specs
# define SPECS "dicouxXnspf"	// zu same as l (sizeof)

int	ft_printf(const char *str, ...);

typedef struct  		s_info
{
    uint16_t    		flags;  // holds flags
    int         		res;    // res from printf

	// needed
	int					arg_len;
	int					width;	// minimum of printed, already stored ??
	int					prec;
	int					f_dec;	// count for floats # of decimal numbers
	int					f_dec_len;	// floats after . len

	long long			tmp;

	char				*str;	// ? for what
	unsigned long long	cur_arg; // send to funcs	//needed?




	int					min_len;	// ?
	// int					f_last;	//	store last % 10 before * -1

    int         		i;		// needed ?
    int         		tmpres;	// needed?
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

	// ASTR = 64,	// straight up take arg to ->prec or ->width
	// NEG_NUM = 128	// ?
}t_flags;

typedef	int		(*func_pointer) (t_info *, va_list);

int	ft_atoi(const char *str);
int	ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int	ft_putchar_multi(char c, int i);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putnbr(int n);
int	count_digits(long long num);
int	check_error_input(t_info *info, char specifier);
void	reset_info(t_info *info, int res);
void	check_width(const char* str, t_info *info, va_list args);
void	check_flags(const char *str, t_info *info, va_list args);
int	ft_printf(const char *str, ...);
int	print_number(t_info *i, va_list args);
int	print_char(t_info *info, va_list args);

// # define SPECS "dicouxXnspf"	// zu same as l (sizeof)
static const func_pointer g_disp_table[] =
{
	print_number,
	print_number,
	print_char

	// print_octal
	// print_hex
	// print_hex
	// calc_newline
	// print_str
	// print_address
	// print_float
};


// typedef void					(*t_print_conversion)(t_pformat *cur, \
// va_list ap);

// char *specs = "dioucxPms"
// dc
// 	(const char *str)
// while specs[i]
// {
// 	if specs[i++] == str[0]
// 		g_disp_table[i](str, info *, va_list);
// }














void printbin_2(uint16_t *ptr)
{
	int i = 15;
	while (i >= 0)
	{
		if (i == 11 || i == 7 || i == 3)
			printf(" ");
		if ( *ptr & (1UL << i)  )
			printf("1");
		else
			printf("0");
		i--;
	}
	printf("\n");
}

void printbin(uint64_t *map, char *str)
{
	printf("---printbin---\t\t>>>%s<<<\n", str);
	printf("\tnum = %llu\n\n", *map);
	uint16_t *ptr;
	ptr = (uint16_t*)map;
	ptr += 3;
	int i = 0;
	while (i < 4)
	{
		printbin_2(ptr);
		i++;
		ptr -= 1;
	}
}

void	tests(void)	// DELETE
{
	// printf("\nCHAR\n\t%%c\t\t|%c|\n", 'a');
	// printf("\t%%-c\t\t|%-c|\n", 'b');
	// printf("\t%%-4c\t\t|%-4c|\n", 'c');
	// printf("\t%%*c\t\t|%*c|\n", 4, 'd');
	// printf("\t%%4c\t\t|%4c|\n", 'e');
	// printf("CHAR UNDEFINED:\n\t'%% c'\n\t'%%#c'\n\t'%%+c'\n\t'%%04c'\n");
	// printf("\nSTRINGS, str = \"hello\"\n");
	// printf("\t%%.2s\t\t|%.2s|\n", "hello"); // .num = maxlen
	// printf("\t%%7s\t\t|%7s|\n", "hello");	// if num > len, padding left
	// printf("\t%%-7s\t\t|%-7s|\n", "hello");	// if num > len, padding right
	// printf("STRINGS UNDEFINED\n\t%%#s\n\t%% s\n");

	int i = 9, j = -9;
	printf("\n%s", "% [flags][width][.precision][length]specifier\n");
	printf("\n--- d ---\n");
	printf("%-7s\t|%d|\t|%d|\n", "%d", i, j);
	printf("%-7s\t|%.0d|\t|%.0d|\n", "%.0d", i, j);
	printf("%-7s\t|%4.0d|\t|%4.0d|\n", "%4.0d", i, j);
	printf("%-7s\t|%-4.0d|\t|%-4.0d|\n", "%-4.0d", i, j);
	printf("%-7s\t|%+04.0d|\t|%+04.0d|\n", "%+04.0d", i, j);

	printf("\n%-7s\t\t|%+d|\t\t|%+d|\n", "%+d", i, j);
	printf("%-7s\t\t|%+4d|\t\t|%+4d|\n", "%+4d", i, j);
	printf("%-7s\t\t|%+0d|\t\t|%+0d|\n", "%+0d", i, j);
	printf("%-7s\t\t|%+01d|\t\t|%+01d|\n", "%+01d", i, j);
	printf("%-7s\t\t|%+02d|\t\t|%+02d|\n", "%+02d", i, j);
	printf("%-7s\t\t|%+04d|\t\t|%+04d|\n", "%+04d", i, j);
	printf("%-7s\t\t|%+2d|\t\t|%+2d|\n", "%+2d", i, j);
	printf("%-7s\t\t|%+1d|\t\t|%+1d|\n", "%+1d", i, j);
	printf("%-7s\t\t|%+1.1d|\t\t|%+1.1d|\n", "%+1.1d", i, j);
	printf("%-7s\t\t|%+4.1d|\t\t|%+4.1d|\n", "%+4.1d", i, j);
	printf("%-7s\t\t|%+4.5d|\t|%+4.5d|\n", "%+4.5d", i, j);

	printf("\n%-7s\t\t|% d|\t\t|% d|\n", "% d", i, j);
	printf("%-7s\t\t|% .1d|\t\t|% .1d|\n", "% .1d", i, j);
	printf("%-7s\t\t|% .4d|\t\t|% .4d|\n", "% .4d", i, j);
	printf("%-7s\t\t|% 1d|\t\t|% 1d|\n", "% 1d", i, j);
	printf("%-7s\t\t|% 1.1d|\t\t|% 1.1d|\n", "% 1.1d", i, j);
	printf("%-7s\t\t|% 1.5d|\t|% 1.5d|\n", "% 1.5d", i, j);
	printf("%-7s\t\t|% 2d|\t\t|% 2d|\n", "% 2d", i, j);
	printf("%-7s\t\t|% 4d|\t\t|% 4d|\n", "% 4d", i, j);
	printf("%-7s\t\t|% 4.1d|\t\t|% 4.1d|\n", "% 4.1d", i, j);
	printf("%-7s\t\t|% 4.5d|\t|% 4.5d|\n", "% 4.5d", i, j);
	printf("%-7s\t\t|% 6.4d|\t|% 6.4d|\n", "% 6.4d", i, j);
	printf("%-7s\t\t|% 0d|\t\t|% 0d|\n", "% 0d", i, j);
	printf("%-7s\t\t|% 0.1d|\t\t|% 0.1d|\n", "% 0.1d", i, j);
	printf("%-7s\t\t|% 0.5d|\t|% 0.5d|\n", "% 0.5d", i, j);
	printf("%-7s\t\t|% 01d|\t\t|% 01d|\n", "% 01d", i, j);
	printf("%-7s\t\t|% 01.5d|\t|% 01.5d|\n", "% 01.5d", i, j);
	printf("%-7s\t\t|% 02d|\t\t|% 02d|\n", "% 02d", i, j);
	printf("%-7s\t\t|% 04d|\t\t|% 04d|\n", "% 04d", i, j);
	printf("%-7s\t\t|% 04.1d|\t\t|% 04.1d|\n", "% 04.1d", i, j);
	printf("%-7s\t\t|% 04.5d|\t|% 04.5d|\n", "% 04.5d", i, j);
	printf("%-7s\t\t|% 05.3d|\t|% 05.3d|\n", "% 05.3d", i, j);

	printf("\n%-7s\t\t|%+1.5d|\t|%+1.5d|\n", "%+1.5d", i, j);
	printf("%-7s\t\t|%- d|\t\t|%- d|\n", "%- d", i, j);
	printf("%-7s\t\t|%- .1d|\t\t|%- .1d|\n", "%- .1d", i, j);
	printf("%-7s\t\t|%- .4d|\t\t|%- .4d|\n", "%- .4d", i, j);
	printf("%-7s\t\t|%- 1d|\t\t|%- 1d|\n", "%- 1d", i, j);
	printf("%-7s\t\t|%- 1.1d|\t\t|%- 1.1d|\n", "%- 1.1d", i, j);
	printf("%-7s\t\t|%- 1.5d|\t|%- 1.5d|\n", "%- 1.5d", i, j);
	printf("%-7s\t\t|%- 2d|\t\t|%- 2d|\n", "%- 2d", i, j);
	printf("%-7s\t\t|%- 4d|\t\t|%- 4d|\n", "%- 4d", i, j);
	printf("%-7s\t\t|%- 4.1d|\t\t|%- 4.1d|\n", "%- 4.1d", i, j);
	printf("%-7s\t\t|%- 4.5d|\t|%- 4.5d|\n", "%- 4.5d", i, j);
	printf("%-7s\t\t|%+-d|\t\t|%+-d|\n", "%+-d", i, j);
	printf("%-7s\t\t|%+-1d|\t\t|%+-1d|\n", "%+-1d", i, j);
	printf("%-7s\t\t|%+-2d|\t\t|%+-2d|\n", "%+-2d", i, j);
	printf("%-7s\t\t|%+-4d|\t\t|%+-4d|\n", "%+-4d", i, j);

	printf("\n%-7s\t\t|%-d|\t\t|%-d|\n", "%-d", i, j);
	printf("%-7s\t\t|%-.1d|\t\t|%-.1d|\n", "%-.1d", i, j);
	printf("%-7s\t\t|%-.5d|\t\t|%-.5d|\n", "%-.5d", i, j);
	printf("%-7s\t\t|%-1d|\t\t|%-1d|\n", "%-1d", i, j);
	printf("%-7s\t\t|%-1.2d|\t\t|%-1.2d|\n", "%-1.2d", i, j);
	printf("%-7s\t\t|%-1.6d|\t|%-1.6d|\n", "%-1.6d", i, j);
	printf("%-7s\t\t|%-2d|\t\t|%-2d|\n", "%-2d", i, j);
	printf("%-7s\t\t|%-4d|\t\t|%-4d|\n", "%-4d", i, j);
	printf("%-7s\t\t|%-4.2d|\t\t|%-4.2d|\n", "%-4.2d", i, j);
	printf("%-7s\t\t|%-4.6d|\t|%-4.6d|\n", "%-4.6d", i, j);

	printf("\n%-7s\t\t|%0d|\t\t|%0d|\n", "%0d", i, j);
	printf("%-7s\t\t|%0.1d|\t\t|%0.1d|\n", "%0.1d", i, j);
	printf("%-7s\t\t|%0.4d|\t\t|%0.4d|\n", "%0.4d", i, j);
	printf("%-7s\t\t|%01d|\t\t|%01d|\n", "%01d", i, j);
	printf("%-7s\t\t|%01.4d|\t\t|%01.4d|\n", "%01.4d", i, j);
	printf("%-7s\t\t|%02d|\t\t|%02d|\n", "%02d", i, j);
	printf("%-7s\t\t|%04d|\t\t|%04d|\n", "%04d", i, j);
	printf("%-7s\t\t|%04.6d|\t|%04.6d|\n", "%04.6d", i, j);
	printf("%-7s\t\t|%06.4d|\t|%06.4d|\n", "%06.4d", i, j);

	printf("\n%-7s\t\t|%1d|\t\t|%1d|\n", "%1d", i, j);
	printf("%-7s\t\t|%2d|\t\t|%2d|\n", "%2d", i, j);
	printf("%-7s\t\t|%4d|\t\t|%4d|\n", "%4d", i, j);
	printf("%-7s\t\t|%1.1d|\t\t|%1.1d|\n", "%1.1d", i, j);
	printf("%-7s\t\t|%1.5d|\t\t|%1.5d|\n", "%1.5d", i, j);
	printf("%-7s\t\t|%4.1d|\t\t|%4.1d|\n", "%4.1d", i, j);
	printf("%-7s\t\t|%4.5d|\t\t|%4.5d|\n", "%4.5d", i, j);
	printf("%-7s\t\t|%5.4d|\t\t|%5.4d|\n", "%5.4d", i, j);

	printf("\n%-7s\t\t|%.1d|\t\t|%.1d|\n", "%.1d", i, j);
	printf("%-7s\t\t|%.2d|\t\t|%.2d|\n", "%.2d", i, j);
	printf("%-7s\t\t|%.5d|\t\t|%.5d|\n", "%.5d", i, j);
	printf("\n");



	// printf("|%+*d|\n", 4, 42);

	// printf("\n%08.4f\n", 42.10);

	// NOT
	// printf("|%+ d|\n", 42);
	// printf("|%+ 4d|\n", 42);

}

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
#endif