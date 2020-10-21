#ifndef CUB3D_H
# define CUB3D_H

# define _USE_MATH_DEFINES
# include <math.h>
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include "mlx_linux/mlx.h"
# define BLOCK 16

typedef struct		s_texture
{
	void			*img;
	void			*addr;
	int				bpp;
	int				line_length;
	int				endian;
	int				width;
	int				height;
	char			*type;
	float			y;
	int				sprite_x;
	int				sprite_y;
}					t_texture;

typedef struct		s_all
{
	char			**map;
	int				map_x;
	int				map_y;
	float			x;
	float			y;
	float			player_x;
	float			player_y;
	float			ray_dir;
	float			ray_start;
	float			ray_end;
	float			ray_len;
	float			ray_step;
	int				wall_x;
	float			sprite_ray_len[30];
	int				sprite_x_draw[30];
	float			spriteheight[30];

	float			rays[2000];
	float			sprite_x[30];
	float			sprite_y[30];

	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;

	int				ceil_color;
	int				floor_color;
	int				winwidth;
	int				winheight;
	int				block;

	float			lineheight;
	float			drawstart;
	float			drawend;
	t_texture		*tex_so;
	t_texture		*tex_no;
	t_texture		*tex_we;
	t_texture		*tex_ea;
	t_texture		*tex_sprite;
	int				save;
	int				map_start_raw;
}					t_all;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

/*
** аргументы входного файла
*/
typedef struct		s_arg
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*sprite;
	t_rgb			fl;
	t_rgb			ceil;
	char			*player_start_dir;
	int				map_start_raw;
	int				map_end_raw;
	int				map_start_col;
	int				map_end_col;
	int				args_end_raw;
}					t_arg;

void				ft_draw_fov (t_all *g);
int					ft_deal_key2(int key, t_all *g);
int					ft_parse_input(t_all *g, t_arg *parse);
int					ft_player_start_dir(t_all *g, t_arg *parse);
int					ft_draw_map(t_all *g);
int					ft_correct_player_coord(t_all *g);
int					ft_error(int error);
int					ft_makeimage(t_all *g, t_arg *parse);
int					ft_bitmap(t_all *g);
int					ft_exit(t_all *g, int window);
int					ft_makewindow(t_all *g, t_arg *parse);
int					ft_resolution(t_all *g);
int					ft_parse_textures(t_all *g, t_arg *parse);
int					ft_floor_color(t_all *g, t_arg *parse);
int					ft_ceilling_color(t_all *g, t_arg *parse);
int					ft_deal_key(int key, t_all *g);
void				ft_draw_walls(t_all *g);
void				ft_draw_sprite(t_all *g);
void				ft_draw_west(t_all *g);
int					ft_draw_ceilling_floor(t_all *g);
void				ft_draw_south(t_all *g);
int					get_pixel_color(t_texture *text, int x, int y);
void				my_mlx_pixel_put(t_all *data, int x, int y, int color);
int					ft_parse_map3(t_all *g, t_arg *parse);

#endif
