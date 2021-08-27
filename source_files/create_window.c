#include "../header_files/so_long.h"

void	create_window(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win.win = mlx_new_window(mlx->mlx, mlx->win.width * 50,
			mlx->win.height * 50, "so_long");
}
