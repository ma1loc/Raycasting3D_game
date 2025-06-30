NAME = cub3D
CC = cc
INCLUDE = -Isrcs -Iparsing/libft
CFLAGS = -Wall -Wextra -Werror $(INCLUDE) -g3 -fsanitize=address
RM = rm -rf

MLX_FLAGS = -Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm -lz
MLX_INCLUDE = -Iminilibx-linux

SRC = parsing/get_next_line.c parsing/get_next_line_utils.c parsing/read_map.c \
	parsing/utils.c parsing/check_func.c parsing/cleanup.c parsing/parsing.c parsing/count_func.c\
	parsing/validate_func.c parsing/process_func.c parsing/store_func.c ./srcs/main.c\
	raycasting/init_config/init_player_config.c raycasting/init_config/init_player_directions.c raycasting/init_config/init_game_config.c \
	raycasting/init_config/init_setup.c raycasting/top_view/load_2d_image.c raycasting/top_view/draw_2d_image.c \
	raycasting/game_config/cast_rays.c raycasting/game_config/game_event.c raycasting/game_config/wall_collision.c \
	parsing/libft/ft_isalpha.c parsing/libft/ft_isprint.c parsing/libft/ft_memcpy.c  parsing/libft/ft_strchr.c  parsing/libft/ft_strlen.c  parsing/libft/ft_toupper.c \
	parsing/libft/ft_bzero.c parsing/libft/ft_isascii.c parsing/libft/ft_memchr.c  parsing/libft/ft_memmove.c parsing/libft/ft_strlcat.c parsing/libft/ft_strrchr.c \
	parsing/libft/ft_isalnum.c parsing/libft/ft_isdigit.c parsing/libft/ft_memcmp.c  parsing/libft/ft_memset.c  parsing/libft/ft_strlcpy.c parsing/libft/ft_tolower.c \
	parsing/libft/ft_strncmp.c parsing/libft/ft_strnstr.c parsing/libft/ft_atoi.c parsing/libft/ft_calloc.c parsing/libft/ft_strdup.c parsing/libft/ft_substr.c parsing/libft/ft_strjoin.c \
	parsing/libft/ft_strtrim.c parsing/libft/ft_itoa.c parsing/libft/ft_strmapi.c parsing/libft/ft_striteri.c parsing/libft/ft_putchar_fd.c parsing/libft/ft_putstr_fd.c \
	parsing/libft/ft_putendl_fd.c parsing/libft/ft_split.c parsing/libft/ft_putnbr_fd.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c cub3D.h
	$(CC) $(CFLAGS) $(MLX_INCLUDE) $(LIBFT_INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all

.SECONDARY:
