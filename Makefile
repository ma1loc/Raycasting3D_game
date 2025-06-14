NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address
RM = rm -rf

MLX_FLAGS = -L/home/x-hunter/cub3D/minilibix-linux -L/usr/lib -lXext -lX11 -lm -lz
MLX_INCLUDE = -Iminilibx-linux

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDE = -I$(LIBFT_DIR)

SRC = get_next_line.c get_next_line_utils.c read_map.c main.c utils.c check_func.c\
	  cleanup.c parsing.c count_func.c validate_func.c process_func.c store_func.c\

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
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean re all

.SECONDARY:
