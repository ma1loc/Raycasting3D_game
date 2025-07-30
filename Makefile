NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Isrcs
RM = rm -rf

MLX_DIR = minilibx-linux
MLX_INCLUDE = -I$(MLX_DIR)
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz


LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDE = -I$(LIBFT_DIR)

SRC = ./srcs/main.c ./gnl/get_next_line.c  ./parsing/read_map.c ./parsing/utils.c ./parsing/check_func.c \
	./parsing/cleanup.c ./parsing/parsing.c ./parsing/count_func.c ./parsing/validate_func.c \
	./parsing/process_func.c ./parsing/store_func.c ./game_utils/game_clean.c ./game_utils/game_init.c \
	./game_utils/key_event.c ./game_utils/player_movements.c ./game_randring/img_randring.c \
	./game_randring/game_loop.c ./ray-casting/cast_rays.c ./game_utils/trig_calculator.c \
	./ray-casting/get_intersection.c ./game_randring/top_view_draw.c ./game_utils/game_init_utils.c \
	./game_randring/front_view_draw.c ./game_randring/wall_textures.c ./parsing/check_func2.c \
	./parsing/store_func2.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(LDFLAGS) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(LDFLAGS) $(CFLAGS) $(MLX_INCLUDE) $(LIBFT_INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all
