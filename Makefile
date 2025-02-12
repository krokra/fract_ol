NAME		= fractol

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g
INCLUDES	= -Iincludes -Iminilibx-linux

MLX_DIR		= mlx_linux
MLX_LIB		= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC_DIR		= src
SRC			=	fract_ol.c \
				parsing_utils.c \
				complex_utils.c \
				init_fractal.c \
				render_fractal.c \
				pixel_handling.c \
				my_mlx_pixel_put.c \
				ft_atof.c \
				events_handling.c \
				colors_utils.c \
				burningship.c \
				mouse_handling.c
				
				

OBJ_DIR		= obj
OBJ			= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
DEP			= $(OBJ:.o=.d)

all: $(MLX_LIB) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_FLAGS) -o $@

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

bonus : all

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re