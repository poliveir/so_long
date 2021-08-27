#include "../header_files/so_long.h"

static void	check_amounts(t_mlx *mlx, int c, int opt)
{
	static int	exit;
	static int	collectible;
	static int	player;

	if (opt == 1)
	{
		if (c == 'E')
			exit++;
		else if (c == 'C')
		{
			collectible++;
			mlx->game.collectibles++;
		}
		else if (c == 'P')
			player++;
	}
	if (opt == 2)
		if (!exit || !collectible || !player)
			error_reading(*(mlx->map), 3);
}

static void	check_components(t_mlx *mlx)
{
	t_list	*temp;
	char	*line;

	mlx->game.exit = 0;
	mlx->game.movements = 0;
	mlx->game.collectibles = 0;
	temp = *(mlx->map);
	while (temp)
	{
		line = temp->content;
		while (*line)
		{
			if (*line != '0' && *line != '1'
				&& *line != 'C' && *line != 'E'
				&& *line != 'P')
				error_reading(*(mlx->map), 2);
			check_amounts(mlx, *line, 1);
			line++;
		}
		temp = temp->next;
	}
	check_amounts(mlx, *line, 2);
}

static void	check_walls(t_list *map, t_mlx *mlx)
{
	t_list	*temp;
	char	*line;

	temp = *(mlx->map);
	line = temp->content;
	while (*line)
		if (*line++ != '1')
			error_reading(*(mlx->map), 4);
	temp = temp->next;
	while (temp->next)
	{
		line = temp->content;
		if (*line++ != '1')
			error_reading(*(mlx->map), 4);
		while (*(line + 1))
			line++;
		if (*line != '1')
			error_reading(*(mlx->map), 4);
		temp = temp->next;
	}
	line = temp->content;
	while (*line)
		if (*line++ != '1')
			error_reading(*(mlx->map), 4);
}

static void	save_map(t_win *win, t_mlx *mlx)
{
	int		length;
	t_list	*temp;

	check_components(mlx);
	check_walls(*(mlx->map), mlx);
	temp = *(mlx->map);
	length = ft_strlen((*(mlx->map))->content);
	temp = temp->next;
	while (temp)
	{
		if (ft_strlen(temp->content) != length)
			error_reading(*(mlx->map), 1);
		temp = temp->next;
	}
	win->width = ft_strlen((*(mlx->map))->content);
	win->height = ft_lstsize(*(mlx->map));
	if (win->height == win->width)
		error_reading(*(mlx->map), 1);
}

void	read_map(t_mlx *mlx, char *map_file)
{
	int			fd;
	int			ret;
	static char	*line = NULL;

	mlx->map = malloc(sizeof(count_lines(map_file)));
	*(mlx->map) = NULL;
	fd = open(map_file, O_RDONLY);
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret > 0)
		{
			ft_lstadd_back(mlx->map, ft_lstnew(line));
			line = NULL;
			continue ;
		}
		else
			break ;
	}
	close(fd);
	if (ret == -1)
		error_reading(*(mlx->map), 0);
	else if (ret == 0 && line[0] != '\0')
		ft_lstadd_back(mlx->map, ft_lstnew(line));
	save_map(&(mlx->win), mlx);
}
