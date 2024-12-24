#include "pushswap.h"


static void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

void ft_print(int command)
{
	if (command < 0 || command > 11)
	{ 
		if (command == 0)
			ft_putstr("sa");
		if (command == 1)
			ft_putstr("sb");
		if (command == 2)
			ft_putstr("ss");
		if (command == 3)
			ft_putstr("pa");
		if (command == 4)
			ft_putstr("pb");
		if (command == 5)
			ft_putstr("ra");
		if (command == 6)
			ft_putstr("rb");
		if (command == 7)
			ft_putstr("rr");
		if (command == 8)
			ft_putstr("rra");
		if (command == 9)
			ft_putstr("rrb");
		if (command == 10)
			ft_putstr("rrr");
	}
}