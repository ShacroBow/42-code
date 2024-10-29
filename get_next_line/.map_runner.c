#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <termios.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include "get_next_line.h"

#define MAP_WIDTH 11
#define MAP_HEIGHT 10
#define MAP_NAME ".map1.txt"

static struct termios old_termios, new_termios;

void reset_terminal()
{
	printf("\e[m"); // reset color
	printf("\e[?25h"); // show cursor again
	fflush(stdout);
	tcsetattr(STDIN_FILENO, TCSANOW, &old_termios);
}

void configure_terminal()
{
	tcgetattr(STDIN_FILENO, &old_termios);
	new_termios = old_termios;

	new_termios.c_lflag &= ~(ICANON | ECHO); // turn off terminal echo and enable non-canonical input
	new_termios.c_cc[VMIN] = 1;
	new_termios.c_cc[VTIME] = 0;

	tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);

	printf("\e[?25l"); // hide cursor
	atexit(&reset_terminal);
}

void signal_handler(int signum)
{
	reset_terminal();
	signal(signum, SIG_DFL);
	raise(signum);
}

int read_key(char *buf, int k)
{
	if ((buf[k] == '\033') && (buf[k + 1] == '['))
	{
		switch (buf[k + 2])
		{
			case 'A': return 1; // up
			case 'B': return 2; // down
			case 'C': return 3; // right
			case 'D': return 4; // left
		}
	}
	else if (buf[k] == 'q')
	{
		return 5; // quit
	}
	return 0;
}

void print_key(int key)
{
	if (key == 1) printf("Up\n");
	if (key == 2) printf("Down\n");
	if (key == 3) printf("Right\n");
	if (key == 4) printf("Left\n");
}

int read_input() {
	char buf[4096];
	int final_key = 0;
	int k = 0;
	int key = 0;
	int n = read(STDIN_FILENO, buf, sizeof(buf));

	while (k < n)
	{
		key = read_key(buf, k);
		if (key >= 1 && key <= 5)
		{
			final_key = key;
			k += 3;
		}
		else
			k++;
	}
	return final_key;
}

void load_map(char *mapname, char map[MAP_HEIGHT][MAP_WIDTH + 1])
{
	char buf[MAP_WIDTH + 1];
	
	int fd = open(mapname, O_RDONLY);
	if (fd <= 0)
	{
		perror("\nFailed to load map");
		close(fd);
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		read(fd, buf, MAP_WIDTH);
		buf[MAP_WIDTH] = '\0';
		strncpy(map[i], buf, MAP_WIDTH + 1);
	}
	close(fd);
}

void save_map(char *mapname, char map[MAP_HEIGHT][MAP_WIDTH + 1])
{
	int fd = open(mapname, O_RDWR);
	if (fd <= 0)
	{
		perror("\nFailed to save map");
		close(fd);
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		write(fd, map[i], MAP_WIDTH);
	}
	close(fd);
}

void print_map(char *mapname)
{
	char *ptr;
	int fd = open(mapname, O_RDONLY);
	while ((ptr = get_next_line(fd)))
	{	
		printf("%s", ptr);
		free(ptr);
	}
	close(fd);
}

void findplayer(int *player_x, int *player_y, char map[MAP_HEIGHT][MAP_WIDTH + 1])
{
	*player_x = 0;
	*player_y = 0;
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		*player_x = 0;
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			if (map[*player_y][*player_x] == '@')
			{
				return;
			}
			*player_x += 1;
		}
		*player_y += 1;
	}
}

int main()
{
	configure_terminal();
	signal(SIGINT, signal_handler);

	char map[MAP_HEIGHT][MAP_WIDTH + 1];
	int player_x = 0, player_y = 0;

	load_map(MAP_NAME, map);
	print_map(MAP_NAME);

	struct timespec req = {0, 1000000000};
	struct timespec rem = {};

	while (1)
	{
		int key = read_input();
		if (key == 5)
			break; // Exit on 'q'
		print_key(key);

		findplayer(&player_x, &player_y, map);
		map[player_y][player_x] = ' ';

		if (key == 1 && player_y > 0 && map[player_y - 1][player_x] != '#')
			player_y--;
		else if (key == 2 && player_y < MAP_HEIGHT - 1 && map[player_y + 1][player_x] != '#')
			player_y++;
		else if (key == 3 && player_x < MAP_WIDTH - 1 && map[player_y][player_x + 1] != '#')
			player_x++;
		else if (key == 4 && player_x > 0 && map[player_y][player_x - 1] != '#')
			player_x--;
		
		map[player_y][player_x] = '@';

		printf("\033[H\033[J"); // Clear the screen
		save_map(MAP_NAME, map);
		print_map(MAP_NAME);
		print_key(key);
		nanosleep(&req, &rem);
	}
	return 0;
}