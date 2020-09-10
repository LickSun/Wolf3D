/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 12:23:12 by lmidori           #+#    #+#             */
/*   Updated: 2020/09/08 13:44:38 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <sys/errno.h>
# include <fcntl.h>
# include "get_next_line.h"
# include <math.h>
# include "../minilibx_mms_20200219/mlx.h"
# include "../libft/libft.h"

# define CUB_SIZE 32
# define FOV (M_PI / 3)

typedef struct		s_texture{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				height;
	int				width;
	char			*path;
}					t_texture;

typedef struct		s_player{
	double			x_pos;
	double			y_pos;
	double			a_pos;
	double			x_break;
	double			y_break;
	int				flag;
}					t_player;

typedef struct		s_sprite{
	int				x;
	int				y;
	double			len;
	double			angle;
	int				size;
	struct s_sprite	*next;
}					t_sprite;

typedef struct		s_mlx{
	void			*mlx;
	void			*win;
	void			*img;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	char			*addr;
}					t_mlx;

typedef struct		s_all
{
	int				scr_width;
	int				scr_height;
	char			**map;
	int				map_len;
	int				map_height;
	int				fd;
	t_list			*head;
	t_mlx			mlx;
	t_player		player;
	t_texture		texture_n;
	t_texture		texture_s;
	t_texture		texture_w;
	t_texture		texture_e;
	t_texture		texture_spr;
	t_sprite		*sprite;
	int				color_floor;
	int				color_ceilling;
	int				spr_flag;
	double			*rays;
	int				y_start_wall;
	int				y_end_wall;
	double			coef;
}					t_all;

void				ft_init_struct(t_all *all);
int					ft_init_mlx(t_all *all);
int					ft_init_text(t_all *all, t_texture *texture);
int					ft_init_textures(t_all *all);
int					ft_valid_file(t_all *all, char *str);
int					ft_valid_arguments(int argc, char **argv);
int					ft_check_name(int len, char *str);
int					ft_parse_file(t_all *all);
int					ft_parse_lines(t_list **head, t_all *all);
int					ft_init_params(t_all *all, t_list **head);
int					ft_check_params(t_all *all);
t_list				*ft_skip_empty_lines(t_list *tmp);
int					ft_find_params(t_all *all, char *ptr);
int					ft_read_sizes(t_all *all, char *str);
int					ft_read_floor_cell(t_all *all, char *str);
int					ft_read_texture(char *name, char *str, t_texture *texture);
char				*ft_skip_spaces(char *ptr);
int					ft_numb_len(unsigned int numb);
int					ft_valid_atoi(const char *nptr);
char				*ft_skip_numb(char *ptr);
int					ft_find_len(char *ptr);
int					ft_read_colors(char ch, int *tmp, t_all *all);
char				**read_map(t_all *all, t_list **head, int size);
int					flood_fill(int map_height, int x, int y, char **map);
int					ft_check_map(char **map);
int					ft_fill_map(t_all *all, char **map);
t_sprite			*ft_lstnew_sprite(int x, int y);
t_sprite			*ft_lstlast_sprite(t_sprite *lst);
void				ft_lstadd_back_sprite(t_sprite **lst, t_sprite *tmp);
void				ft_sprclear(t_sprite **lst);
int					ft_init_player(t_all *all, char ch, int i, int j);
int					ft_init_p_s(t_all *all);
int					ft_cell_check(t_all *all, t_sprite **spr, int i, int j);
int					ft_key_up(t_all *all);
int					ft_key_down(t_all *all);
int					ft_key_left(t_all *all);
int					ft_key_right(t_all *all);
int					ft_key_action(int keycode, t_all *all);
int					ft_key_turn_left(t_all *all);
int					ft_key_turn_right(t_all *all);
int					ft_key_press(int keycode, t_all *all);
void				ft_free_all(t_all *all);
int					ft_close_window(t_all *all);
void				my_mlx_pixel_put(t_all *all, int x, int y, int color);
int					ft_get_color_texture(t_texture *texture, int x, int y);
int					ft_get_color_win(t_all *data, int x, int y);
void				ft_fill_black(t_all *all);
void				ft_swap(t_sprite **head, t_sprite *tmp, t_sprite *sled);
void				ft_sort_sprite_len(t_sprite **root);
void				ft_len_sprite(t_all *all, t_sprite *root);
void				ft_sort_sprites(t_all *all);
void				ft_init_spr_params(t_all *all, t_sprite *spr);
void				ft_draw_sprite(t_all *all, t_sprite *spr,
									int h_offset, int v_offset);
void				ft_rend_sprite(t_all *all, t_sprite *spr);
void				ft_rend_sprites(t_all *all);
void				ft_raycast(t_all *all, double angle);
t_texture			*ft_find_texture(t_all *all, double angle);
void				ft_rend_floor_ceilling(t_all *all, int x, int y_start_wall);
void				ft_rend_3d(t_all *all, int x, double h_wall, double angle);
double				ft_text_pos(t_all *all, double angle);
void				ft_rend_window(t_all *all);
int					ft_rend_all(int argc, t_all *all);
void				int_to_char(int n, unsigned char *src);
void				bmp_header(t_all *all, int file_size, int fd);
void				ft_fool_bmp(t_all *all, int fd);
int					ft_screen_shot(t_all *all);
int					get_next_line(int fd, char **line);
int					ft_check_all(t_all *all, t_list *tmp);

#endif
