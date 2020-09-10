
.PHONY: all re fclean clean

NAME = cub3D

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

MLX1 = minilibx_mms_20200219

MLX2 = minilibx_opengl_20191021

DIR_S = src

DIR_O = obj

SOURCES = bmp_create.c check_all.c close_window.c cub3d.c draw_sprite.c help_funcs.c init_funcs.c \
			init_player.c key_action.c keycode_funcs.c my_mlx_pixel_put.c parse_args.c parse_file.c \
			read_map.c rend_3d.c rend_window.c sort_sprites.c sprite_lst.c valid_arg.c \
			get_next_line.c get_next_line_utils.c

HEADER = src

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT) bonus
	@cp libft/libft.a ./
	@make -C $(MLX1)
	@cp minilibx_mms_20200219/libmlx.dylib ./
	@make -C $(MLX2)
	@cp minilibx_opengl_20191021/libmlx.a ./
	@gcc $(FLAGS) ./libft.a ./libmlx.a ./libmlx.dylib -framework OpenGl -framework AppKit $(SRCS) -o $(NAME)
	@echo Cub3d was successfully compiled

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/cub3d.h
	@mkdir -p obj
	@gcc $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@make -C $(LIBFT) clean
	@rm -rf $(DIR_O)
	@echo Cleaned objects files

fclean: clean
	@make -C $(LIBFT) fclean
	@make -C $(MLX1) clean
	@make -C $(MLX2) clean
	@rm -f $(NAME)
	@rm -f libft.a
	@rm -f libmlx.a
	@rm -f libmlx.dylib
	@echo Cleaned libs
	@echo Cleaned $(NAME)

re: fclean all
