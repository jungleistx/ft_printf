#include "includes/ft_printf.h"

int main(void)
{
	int a = 42;
	long b = 109222114;
	char c = 'A';
	char *str = "Hello";

	ft_printf("int: %d\n", a);
	ft_printf("long: %ld\n", b);
	ft_printf("char: %c\n", c);
	ft_printf("string: %s\n", str);
	ft_printf("hex of value %d: %x\n", a, a);
	ft_printf("octal of value %d: %o\n", a, a);
	ft_printf("binary of value %d: %b\n", a, a);
  
  return (0);
}
