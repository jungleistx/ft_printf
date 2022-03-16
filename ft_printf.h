/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvuorenl <rvuorenl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:18:13 by rvuorenl          #+#    #+#             */
/*   Updated: 2022/03/16 12:48:58 by rvuorenl         ###   ########.fr       */
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

int	ft_printf(const char *str, ...);

typedef struct  		s_info
{
    uint16_t    		flags;  //
    int         		res;    // res from printf
    int         		tmpres;	// needed?
	unsigned long long	cur_arg;
	char				*str;
    int         		i;
    int         		padding;	// pad - count
	int					f_dec;	// count for floats # of decimal numbers
    int         		tmpnum;    // needed for long long % 10 res ?, before reverse
}t_info;

typedef enum e_spec
{
	H,
	HH,
	L,
	LL
}

# define SPEC "dicouxXnspf"	// zu same as l (sizeof)

typedef enum e_flags
{
	PLUS = 1,
	MINUS = 2,
	HASH = 4,
	ZERO = 8,
	SPACE = 16
}

/*
0   ' '
1   +
2   -
3   0
4   ll
5



*/

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


	// printf("\nINT\n");
	// printf("\t%%d\t\t|%d|\n\t%% d\t\t|% d|\n", 42, 42);
	// printf("\t%%+d\t\t|%+d|\n\t%%-d\t\t|%-d|\n", 42, 42);
	// printf("\t%%04d\t\t|%04d|\n\t%%-4d\t\t|%-4d|\n", 42, 42);
	// printf("\t%%-04d\t\t|%-04d|\n\t%%", 42)


	printf("|%d|\n", 42);
	printf("|%+d|\n", 42);
	printf("|%+0d|\n", 42);
	printf("|%+04d|\n", 42);
	printf("|%+-d|\n", 42);
	printf("|%+-4d|\n", 42);
	printf("|%+*d|\n", 4, 42);

	printf("\n|%d|\n", -42);
	printf("|%+d|\n", -42);
	printf("|%+0d|\n", -42);
	printf("|%+04d|\n", -42);
	printf("|%+-d|\n", -42);
	printf("|%+-4d|\n", -42);
	printf("|%+*d|\n", 4, -42);
	printf("|%*d|\n", 4, -42);
	printf("|%4d|\n", -42);
	// printf("|%+ d|\n", 42);
	// printf("|%+ 4d|\n", 42);
	// NOT
	// + ' '
	// 0 -
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