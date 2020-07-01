#include <stdio.h>
#include "ft_printf.h"
# include <stdint.h>
# include <limits.h>

int main()
{
	char buf[200];
	buf[0] = 'H';
	buf[1] = 'A';
	intmax_t test = (intmax_t)INT_MAX + 1;
	ft_sprintf(buf, "%x", 42);
	puts(buf);
}