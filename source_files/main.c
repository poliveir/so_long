#include "../header_files/so_long.h"

int	close_window(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->win.height)
	{
		free((mlx->map_grid)[i]);
		(mlx->map_grid)[i++] = NULL;
	}
	free (mlx->map_grid);
	mlx->map_grid = NULL;
	ft_lstclear(mlx->map, free);
	exit(0);
}

static int	key_pressed(int keycode, t_mlx *mlx)
{
	mlx->game.move = 0;
	if (keycode == 53)
		close_window(mlx);
	else if (keycode == 13)
		mlx->game.move = 'W';
	else if (keycode == 1)
		mlx->game.move = 'S';
	else if (keycode == 0)
		mlx->game.move = 'A';
	else if (keycode == 2)
		mlx->game.move = 'D';
	else
		return (0);
	update_map(mlx);
	if (mlx->game.exit)
		close_window(mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	args_check(argc, argv);
	read_map(&mlx, argv[1]);
	create_window(&mlx);
	draw_map(&mlx);
	mlx_hook(mlx.win.win, 2, 1L << 0, key_pressed, &mlx);
	mlx_hook(mlx.win.win, 17, 0, close_window, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
