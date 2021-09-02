#include "../header_files/so_long.h"

#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define NORMAL "\033[0m"

void	error_args(int error_nbr)
{
	printf("%s[ERROR]%s ", RED, NORMAL);
	if (error_nbr == 0)
	{
		printf("Use the program as follows: ");
		printf("%s./so_long <map file>%s\n", YELLOW, NORMAL);
	}
	if (error_nbr == 1)
		printf("Parameter must be a %s.ber%s file\n", YELLOW, NORMAL);
	exit (0);
}

void	error_reading(t_list **map, int error_nbr)
{
	ft_lstclear(map, free);
	map = NULL;
	printf("%s[ERROR]%s ", RED, NORMAL);
	if (error_nbr == 0)
		printf("Something went wrong while reading .ber file\n");
	else if (error_nbr == 1)
		printf("The map must be rectangular\n");
	else if (error_nbr == 2)
	{
		printf("The map must be composed of only 5 possible characters:\n");
		printf("0 -> Empty space\n1 -> Wall\nC -> Collectible\n");
		printf("E -> Map exit\nP -> Player's starting position\n");
	}
	else if (error_nbr == 3)
		printf("The map must have at least:\n1 Exit\n1 Collectible\n1 Player");
	else if (error_nbr == 4)
		printf("The map must be surrounded by walls ('1')\n");
	exit(0);
}
