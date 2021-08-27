#VARIABLES:

NAME			= so_long

SRCS			= source_files/main.c source_files/args_check.c source_files/error.c source_files/read_map.c \
				source_files/utils1.c source_files/utils2.c source_files/create_window.c \
				source_files/draw_map.c source_files/get_next_line.c source_files/update_map.c

OBJS			= $(SRCS:.c=.o)

CC			= gcc

CFLAGS		= -fsanitize=address -Wall -Werror -Wextra

#RULES:

.SILENT:
all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)

	$(CC) $(SRCS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf *.o $(SRCS_DIR)/*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
