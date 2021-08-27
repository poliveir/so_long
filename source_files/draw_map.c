#include "../header_files/so_long.h"

void	draw_tile(t_mlx *mlx, char *img, int i, int j)
{
	int	height;
	int	width;

	mlx->img.addr = mlx_get_data_addr(mlx->img.img,
			&(mlx->img.bits_per_pixel), &(mlx->img.line_length),
			&(mlx->img.endian));
	mlx->img.img = mlx_xpm_file_to_image(mlx->mlx, img,
			&width, &height);
	mlx_put_image_to_window(mlx->mlx, mlx->win.win,
		mlx->img.img, j * 50, i * 50);
}

void	register_player_pos(t_mlx *mlx, int y, int x)
{
	mlx->game.x = x;
	mlx->game.y = y;
}

static void	build_grid(t_mlx *mlx)
{
	int		i;
	int		j;
	t_list	*temp;
	char	*str;

	mlx->map_grid = malloc(sizeof(char *) * (mlx->win.height));
	i = 0;
	temp = *(mlx->map);
	while (i < mlx->win.height)
	{
		(mlx->map_grid)[i] = malloc(mlx->win.width);
		j = 0;
		str = temp->content;
		while (*str)
		{
			if (*str == 'P')
				register_player_pos(mlx, i, j);
			(mlx->map_grid)[i][j] = *str++;
			j++;
		}
		temp = temp->next;
		i++;
	}
}

void	select_and_draw_img(t_mlx *mlx, int i, int j)
{
	if ((mlx->map_grid)[i][j] == '1')
		draw_tile(mlx, "./images/Appletree.xpm", i, j);
	else if ((mlx->map_grid)[i][j] == 'E')
		draw_tile(mlx, "./images/House.xpm", i, j);
	else if ((mlx->map_grid)[i][j] == 'C')
		draw_tile(mlx, "./images/Apple.xpm", i, j);
	else if ((mlx->map_grid)[i][j] == '0')
		draw_tile(mlx, "./images/Grass.xpm", i, j);
	else if ((mlx->map_grid)[i][j] == 'P')
		draw_tile(mlx, "./images/Littleredhood.xpm", i, j);
	else
		return ;
}

void	draw_map(t_mlx *mlx)
{
	int	i;
	int	j;
	int	color;

	build_grid(mlx);
	j = 0;
	while (j < mlx->win.height)
	{
		i = 0;
		while (i < mlx->win.width)
		{
			select_and_draw_img(mlx, j, i);
			i++;
		}
		j++;
	}
}
