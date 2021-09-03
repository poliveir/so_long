#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

/*LIBFT:*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *s1);

char	*ft_strjoin(char const *s1, char const *s2);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

t_list	*ft_lstnew(void *content);

void	ft_lstdelone(t_list *lst, void (*del)(void *));

void	ft_lstclear(t_list **lst, void (*del)(void *));

t_list	*ft_lstlast(t_list *lst);

void	ft_lstadd_back(t_list **lst, t_list *new);

int		ft_lstsize(t_list *lst);

/*GNL:*/

int		get_next_line(int fd, char **line);

/*SO_LONG:*/

typedef struct s_game
{
	int	x;
	int	y;
	int	move;
	int	movements;
	int	exit;
	int	collectibles;
}				t_game;

typedef struct s_win
{
	void	*win;
	int		height;
	int		width;
}				t_win;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_mlx
{
	void		*mlx;
	t_win		win;
	t_img		img;
	t_list		**map;
	char		**map_grid;
	t_game		game;
}				t_mlx;

void	error_args(int error_nbr);

void	error_reading(t_list **map, int error_nbr);

void	args_check(int argc, char **argv);

void	read_map(t_mlx *mlx, char *map_file);

int		count_lines(char *map_file);

void	create_window(t_mlx *mlx);

void	create_image(t_mlx *mlx);

void	draw_map(t_mlx *mlx);

void	select_and_draw_img(t_mlx *mlx, int i, int j);

void	draw_tile(t_mlx *mlx, char *img, int i, int j);

void	register_player_pos(t_mlx *mlx, int x, int y);

void	update_map(t_mlx *mlx);

int		close_window(t_mlx *mlx);

#endif
