NAME = cub2D
CC = cc
INCLUDE = -Isrcs
CFLAGS = -Wall -Wextra -Werror $(INCLUDE) -g3 -fsanitize=address
RM = rm -rf

# MLX_FLAGS = -L/home/yanflous/cub3D/minilibix-linux -L/usr/lib -lXext -lX11 -lm -lz
MLX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX_INCLUDE = -Iminilibx-linux

SRC = ./srcs/main.c ./init_config/init_player_config.c ./init_config/key_event.c \
	./init_config/init_player_position.c ./init_config/init_game_config.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

# $(LIBFT):
# 	make -C $(LIBFT_DIR)

%.o: %.c cub2d.h
	$(CC) $(CFLAGS) $(MLX_INCLUDE) $(LIBFT_INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ)
# make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all

# .SECONDARY:
