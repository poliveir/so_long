#include "../header_files/so_long.h"

void	args_check(int argc, char **argv)
{
	int		argv_len;

	if (argc == 2)
	{
		argv_len = ft_strlen(argv[1]);
		if (ft_strncmp(argv[1] + (argv_len - 4), ".ber", 4) != 0)
			error_args(1);
	}
	else
		error_args(0);
}
