#include "cub3d.h"

void	ft_draw_fov2(t_all *g)
{
	while (g->wall_x < g->winwidth)
	{
		g->x = g->player_x;
		g->y = g->player_y;
		g->ray_len = 0;
		while (g->map[(int)g->y / BLOCK][(int)g->x / BLOCK] != '1')
		{
			g->x = g->player_x + g->ray_len * cos(g->ray_start);
			g->y = g->player_y + g->ray_len * sin(g->ray_start);
			g->ray_len += 1;
		}
		g->ray_len -= 2;
		g->x = g->player_x + g->ray_len * cos(g->ray_start);
		g->y = g->player_y + g->ray_len * sin(g->ray_start);
		while (g->map[(int)g->y / BLOCK][(int)g->x / BLOCK] != '1')
		{
			g->x = g->player_x + g->ray_len * cos(g->ray_start);
			g->y = g->player_y + g->ray_len * sin(g->ray_start);
			g->ray_len += 0.01;
		}
		g->rays[g->wall_x] = g->ray_len / BLOCK;
		ft_draw_walls(g);
		g->ray_start += g->ray_step;
		g->wall_x++;
	}
}

void	ft_draw_fov(t_all *g)
{
	g->ray_step = (1.0 / g->winwidth);
	g->ray_start = g->ray_dir - 0.5;
	g->ray_end = g->ray_dir + 0.5;
	g->ray_len = 0;
	g->wall_x = 0;
	ft_draw_fov2(g);
	g->ray_step = (1.0 / g->winwidth);
	g->ray_start = g->ray_dir - 0.5;
	g->ray_end = g->ray_dir + 0.5;
	g->ray_len = 0;
	g->wall_x = 0;
	ft_draw_sprite(g);
}

int		ft_init(t_all *g, t_arg *parse)
{
	g->tex_so = malloc(sizeof(t_texture));
	g->tex_no = malloc(sizeof(t_texture));
	g->tex_we = malloc(sizeof(t_texture));
	g->tex_ea = malloc(sizeof(t_texture));
	g->tex_sprite = malloc(sizeof(t_texture));
	if (!(g->tex_so->img = mlx_xpm_file_to_image(g->mlx, parse->so, \
							&g->tex_so->width, &g->tex_so->height)))
		return (ft_error(17));
	g->tex_so->addr = mlx_get_data_addr(g->tex_so->img, &g->tex_so->bpp, \
							&g->tex_so->line_length, &g->tex_so->endian);
	if (!(g->tex_no->img = mlx_xpm_file_to_image(g->mlx, parse->no, \
							&g->tex_no->width, &g->tex_no->height)))
		return (ft_error(17));
	g->tex_no->addr = mlx_get_data_addr(g->tex_no->img, &g->tex_no->bpp, \
								&g->tex_no->line_length, &g->tex_no->endian);
	if (!(g->tex_we->img = mlx_xpm_file_to_image(g->mlx, parse->we, \
								&g->tex_we->width, &g->tex_we->height)))
		return (ft_error(17));
	g->tex_we->addr = mlx_get_data_addr(g->tex_we->img, &g->tex_we->bpp, \
							&g->tex_we->line_length, &g->tex_we->endian);
	return (1);
}

int		ft_makeimage(t_all *g, t_arg *parse)
{
	g->img = mlx_new_image(g->mlx, g->winwidth, g->winheight);
	g->addr = mlx_get_data_addr(g->img, &g->bits_per_pixel, \
								&g->line_length, &g->endian);
	if (ft_init(g, parse) == 0)
		return (0);
	if (!(g->tex_ea->img = mlx_xpm_file_to_image(g->mlx, parse->ea, \
							&g->tex_ea->width, &g->tex_ea->height)))
		return (ft_error(17));
	g->tex_ea->addr = mlx_get_data_addr(g->tex_ea->img, &g->tex_ea->bpp, \
							&g->tex_ea->line_length, &g->tex_ea->endian);
	if (!(g->tex_sprite->img = mlx_xpm_file_to_image(g->mlx, parse->sprite, \
		&g->tex_sprite->width, &g->tex_sprite->height)))
		return (ft_error(17));
	g->tex_sprite->addr = mlx_get_data_addr(g->tex_sprite->img, \
	&g->tex_sprite->bpp, &g->tex_sprite->line_length, &g->tex_sprite->endian);
	ft_draw_fov(g);
	return (1);
}

int		ft_makewindow(t_all *g, t_arg *parse)
{
	g->mlx = mlx_init();
	if (ft_makeimage(g, parse) == 0)
		return (0);
	if (g->save == 1)
		return (ft_bitmap(g));
	g->win = mlx_new_window(g->mlx, g->winwidth, g->winheight, "cub3D");
	mlx_hook(g->win, 2, 1L << 0, ft_deal_key, g);
	mlx_hook(g->win, 17, 1L << 17, ft_exit, g);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	mlx_loop(g->mlx);
	return (1);
}
