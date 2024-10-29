
#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"
#include <limits.h>

//hey
int main() {
	char *s2 = "hey buddy";
	printf("\n");
	ft_printf(" %s %s %s %s %s", " - ", "", "4", "", s2);
	printf("\n");
	printf(" %s %s %s %s %s", " - ", "", "4", "", s2);
	return 0;
}
