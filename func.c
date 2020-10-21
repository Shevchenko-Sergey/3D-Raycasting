#include "cub3d.h"

int		get_pixel_color(t_texture *text, int x, int y)
{
	char		*dst;

	dst = text->addr + (y * text->line_length + x * (text->bpp / 8));
	return (*(unsigned int*)dst);
}

void	my_mlx_pixel_put(t_all *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		ft_exit(t_all *g, int window)
{
	mlx_destroy_image(g->mlx, g->img);
	mlx_destroy_image(g->mlx, g->tex_so->img);
	mlx_destroy_image(g->mlx, g->tex_no->img);
	mlx_destroy_image(g->mlx, g->tex_we->img);
	mlx_destroy_image(g->mlx, g->tex_ea->img);
	mlx_destroy_image(g->mlx, g->tex_sprite->img);
	free(g->map);
	free(g->tex_so);
	free(g->tex_no);
	free(g->tex_we);
	free(g->tex_ea);
	free(g->tex_sprite);
	g->map = NULL;
	g->tex_so = NULL;
	g->tex_no = NULL;
	g->tex_we = NULL;
	g->tex_ea = NULL;
	g->tex_sprite = NULL;
	if (window == 1)
		mlx_destroy_window(g->mlx, g->win);
	exit(0);
}

int		ft_deal_key(int key, t_all *g)
{
	mlx_destroy_image(g->mlx, g->img);
	g->img = mlx_new_image(g->mlx, g->winwidth, g->winheight);
	g->addr = mlx_get_data_addr(g->img, &g->bits_per_pixel, \
	&g->line_length, &g->endian);
	if (key == 65361)
		g->ray_dir -= 0.1;
	if (key == 65363)
		g->ray_dir += 0.1;
	if (key == 119)
		if (g->map[(int)(g->player_y + BLOCK / 3 * sin(g->ray_dir)) / BLOCK]\
		[(int)(g->player_x + BLOCK / 3 * cos(g->ray_dir)) / BLOCK] != '1')
		{
			g->player_x += cos(g->ray_dir);
			g->player_y += sin(g->ray_dir);
		}
	if (key == 115)
		if (g->map[(int)(g->player_y - BLOCK / 3 * sin(g->ray_dir)) / BLOCK]\
		[(int)(g->player_x - BLOCK / 3 * cos(g->ray_dir)) / BLOCK] != '1')
		{
			g->player_x -= cos(g->ray_dir);
			g->player_y -= sin(g->ray_dir);
		}
	ft_deal_key2(key, g);
	return (0);
}

int		ft_deal_key2(int key, t_all *g)
{
	if (key == 97)
		if (g->map[(int)(g->player_y + BLOCK / 5 * sin(g->ray_dir - \
		M_PI / 2)) / BLOCK][(int)(g->player_x + BLOCK / 5 * \
		cos(g->ray_dir - M_PI / 2)) / BLOCK] != '1')
		{
			g->player_x += cos(g->ray_dir - M_PI / 2);
			g->player_y += sin(g->ray_dir - M_PI / 2);
		}
	if (key == 100)
		if (g->map[(int)(g->player_y + BLOCK / 5 * sin(g->ray_dir + \
		M_PI / 2)) / BLOCK][(int)(g->player_x + BLOCK / 5 * \
		cos(g->ray_dir + M_PI / 2)) / BLOCK] != '1')
		{
			g->player_x += cos(g->ray_dir + M_PI / 2);
			g->player_y += sin(g->ray_dir + M_PI / 2);
		}
	if (key == 65307)
		ft_exit(g, 1);
	ft_draw_fov(g);
	mlx_do_sync(g->mlx);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	return (0);
}
