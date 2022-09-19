# ft_printf

First project of Hive Helsinki Algorithm-branch. <br>
My implementation of the standard C-library function printf.

## About
Allowed functions for this project:
* write
* malloc
* free
* exit
* functions of man 3 stdarg

## Description
ft_printf is prototyped:
```
int ft_printf(const char *format, ...);
```
## Usage

1. make
2. gcc main.c libftprintf.a
3. ./a.out
4. You can modify the main.c to test how the function works.

## Specifiers
* %%  percent-sign
* %d  integer (%ld long), (%lld long long)
* %b  binary
* %o  octal 
* %x or %X hexadecimal
* %p  address
* %n  save the current return-value to a integer, long long (%ln) or signed char (%hn)
* %f  float (%Lf double) 

## Optional usage
```
%[flags][width][.precision][length]specifier
```
Flags: +, -, (space), 0, # <br>
Width: 4 (integer), or if given as an extra argument, use * <br>
Precision: .4 (.integer), or if given as an extra argument, .* <br>
Length: h(short), l(long), ll(long long), L(lond double with float)
