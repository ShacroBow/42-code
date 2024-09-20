#include <unistd.h>
#include <stdio.h>

void	hexprint(unsigned char Byte);
void	hexquad(void *str, int size);
void	hexaddress(void *str);
void	address_padding(int size);
void	ft_print_memory(void *addr, unsigned int size);
int		strlength(unsigned char *s);
void	print_string(char *string, int size, int position);

void	print_string(char *string, int size, int position)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((string[position + i] < 32 && string[position + i] >= 0)
			|| (string[position + i] >= 127))
		{
			write(1, ".", 1);
		}
		else
			write(1, &string[position + i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_print_memory(void *addr, unsigned int size)
{
	int	i;
	int	position;

	i = size / 16;
	position = 0;
	while (i >= 0)
	{
		if (i > 0)
		{
			hexaddress(addr + (position * 16));
			hexquad(addr + (position * 16), 16);
			print_string(addr, 16, (position * 16));
		}
		else if (i == 0)
		{
			hexaddress(addr + (position * 16));
			hexquad(addr + (position * 16), (size % 16));
			print_string(addr, (size % 16), (position * 16));
		}
		i--;
		position++;
		position++;
		position++;
	}
}

void	address_padding(int size)
{
	int	k;

	k = 16 - size;
	while (k != 0)
	{
		write(1, " ", 1);
		write(1, " ", 1);
		if (k % 2 == 0)
		{
			write(1, " ", 1);
		}
		k--;
	}
}

void	hexquad(void *str, int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i != size)
	{
		if (j % 2 == 0)
		{
			write(1, " ", 1);
		}
		hexprint(*((unsigned char *) str + i));
		i++;
		j++;
	}
	if (size < 16)
	{
		address_padding(size);
	}
}

void	hexaddress(void *str)
{
	int	size;
	int	i;

	size = 16;
	i = 0;
	while (i != 16)
	{
		if (j % 2 == 0)
		{
			write(1, " ", 1);
		}
		hexprint(*((unsigned char *) str + i));
		i++;
		j++;
	}
	write(1, ":", 1);
	write(1, " ", 1);
}

void	hexprint(unsigned char Byte)
{
	int	hel;

	hel = 0;
	if ((Byte / 16) < 10)
		hel = (Byte / 16) + 48;
	else
		hel = (Byte / 16) + 87;
	if ((Byte % 16) < 10)
		hel = (Byte % 16) + 48;
	else
		hel = (Byte % 16) + 87;

	write(1, &hel, 1);
}

/* int	strlength(unsigned char *s)
{
	int	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
} */
/* 
int main()
{
	
	char *S = "Salut les aminches c'est cool show mem on\n fait de truc\n  terrible hello my friend";
	char *S1 = "Salut les a\nminches c\0\0\0\0\0\0\0\0\0\0\0\n fait de truc\n  terrible i wan to eat";
	char *S2 = "Salut les a\nminches c'est cool show mem on\n fait de truc\n  terrible i wan to eat";
	char *S3 = "Salut les a\nminches c'est cool show mem on\n fait de truc\n terrible i wan to eat";
	
	ft_print_memory(S, strlength(S)); //when there are no \0 inside
	write(1, "\n", 1);
	write(1, "\n", 1);
	ft_print_memory(S1, 71); //when there are \0 inside

	return 0;
} */