#include "../header_files/so_long.h"

static void	update_game_status(t_mlx *mlx, int x, int y)
{
	mlx->game.y += y;
	mlx->game.x += x;
	mlx->game.movements++;
}

static int	save_new_position(t_mlx *mlx, int x, int y)
{
	if ((mlx->map_grid)[mlx->game.y + y][mlx->game.x + x] == '0')
	{
		(mlx->map_grid)[mlx->game.y + y][mlx->game.x + x] = 'P';
		(mlx->map_grid)[mlx->game.y][mlx->game.x] = '0';
	}
	else if ((mlx->map_grid)[mlx->game.y + y][mlx->game.x + x] == 'C')
	{
		(mlx->map_grid)[mlx->game.y + y][mlx->game.x + x] = 'P';
		(mlx->map_grid)[mlx->game.y][mlx->game.x] = '0';
		mlx->game.collectibles--;
	}
	else if ((mlx->map_grid)[mlx->game.y + y][mlx->game.x + x] == 'E'
			&& !mlx->game.collectibles)
	{
		(mlx->map_grid)[mlx->game.y + y][mlx->game.x + x] = 'P';
		(mlx->map_grid)[mlx->game.y][mlx->game.x + x] = '0';
		mlx->game.exit = 1;
	}
	else
		return (0);
	update_game_status(mlx, x, y);
	printf("Nº movements = |%d|\n", mlx->game.movements);
	return (1);
}

static int	update_grid(t_mlx *mlx)
{
	int		x_move;
	int		y_move;

	x_move = 0;
	y_move = 0;
	if (mlx->game.move == 'W')
		y_move = -1;
	else if (mlx->game.move == 'S')
		y_move = 1;
	else if (mlx->game.move == 'A')
		x_move = -1;
	else if (mlx->game.move == 'D')
		x_move = 1;
	return (save_new_position(mlx, x_move, y_move));
}

void	update_map(t_mlx *mlx)
{
	int	i;
	int	j;

	if (!(update_grid(mlx)))
		return ;
	i = 0;
	while (i < mlx->win.height)
	{
		j = 0;
		while (j < mlx->win.width)
		{
			select_and_draw_img(mlx, i, j);
			j++;
		}
		i++;
	}
}
