#include <stdio.h>
#include "libft.h"
#include "libftprintf.h"

int max(int ap, ...);
int ft_printf(const char *ap, ...);


int main()
{
	max(3, 14,42,15,24);
	printf("hey og %%d:%d %%%%: %%,%%f: %f\n", 1, 1.5);
	// printf("%d\n",)
	// printf("---ORIGINAL PRINTF---\n");
	// printf("char %c\n", 42);
	// printf("string %5s\n", "hey");
	// printf("pointer in hex %p\n", (void *)12323);
	// printf("decimal %+d\n", 424242);
	// printf("int %12.10i\n", 424242);
	// printf("unsigned %-10u\n", 424242);
	// printf("float %10.3f ----NOT NEEDED\n", (float)424242);
	// printf("hex %x\n", (void *)12323);
	// printf("HEX %X\n", (void *)12323);
	// printf("precentage %%\n");
}
/* 
int ft_printf(const char *ap, ... )
{
	va_list	args;
	double		x;
	int		i;

	va_start(args, ap);
	for (i = 0; i < strlen(ap) ; i++)
	{
		if (ap[i] == '%' && ap[i + 1] == 'd')
		{
			x = va_arg(args, int);
			printf("%d", x);
			i += 2;
		}
		else if (ap[i] == '%' && ap[i + 1] == 'i')
		{
			x = va_arg(args, int);
			printf("%d", x);
			i += 2;
		}
		else if (ap[i] == '%' && ap[i + 1] == 'f')
		{
			x = va_arg(args, double);
			printf("%f", x);
			i += 2;
		}
		else if (ap[i] == '%' && ap[i + 1] == 'u')
		{
			x = va_arg(args, unsigned int);
			printf("%u", x);
			i += 2;
		}
		else if (ap[i] == '%' && ap[i + 1] == '%')
		{
			printf("%c", ap[i]);
			i += 2;
		}
		printf("%c", ap[i]);
		
	}
	va_end(args);
	return i;
} */


int max(int ap, ...)
{
	va_list args;
	int x;
	int max;

	va_start(args, ap);
	for(int i = 0; i<ap;i++)
	{
		x = va_arg(args, int);
		if(i== 0)
			max = x;
		else if (x > max)
			max = x;
		printf("argc:%d", i);
		printf(" =  x:%d\n", x);
	}
	printf("\nmax: %d\n", max);
	va_end(args);
	return (0);
}