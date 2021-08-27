#include "../header_files/so_long.h"

int	get_next_line(int fd, char **line)
{
	int		ret;
	char	*temp;
	char	buf[2];

	if (!line || read(fd, buf, 0) < 0)
		return (-1);
	if (!(*line))
		*line = ft_strdup("");
	while (1)
	{
		ret = read(fd, buf, 1);
		if (ret > 0 && buf[0] != '\n')
		{
			buf[ret] = '\0';
			temp = ft_strjoin(*line, buf);
			free(*line);
			*line = temp;
			continue ;
		}
		else
			break ;
	}
	return (ret);
}

int	count_lines(char *map_file)
{
	char	buf[1];
	int		n_lines;
	int		fd;

	n_lines = 0;
	open(map_file, O_RDONLY);
	while (read(fd, buf, 1))
	{
		if (buf[0] == '\n')
			n_lines++;
	}
	close(fd);
	return (n_lines);
}
