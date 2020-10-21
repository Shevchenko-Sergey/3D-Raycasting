#include "cub3d.h"

int		ft_draw_ceilling_floor(t_all *g)
{
	float	drawstart;
	float	drawend;
	float	lineheight;

	lineheight = (g->winheight / (g->ray_len *  \
				cos(g->ray_dir - g->ray_start))) * BLOCK;
	drawstart = -lineheight / 2 + g->winheight / 2;
	drawend = lineheight / 2 + g->winheight / 2;
	while (drawstart >= 0)
		my_mlx_pixel_put(g, g->wall_x, drawstart--, g->ceil_color);
	while (drawend <= g->winheight - 1)
		my_mlx_pixel_put(g, g->wall_x, drawend++, g->floor_color);
	return (0);
}

void	ft_draw_east(t_all *g)
{
	int		color_ea;
	float	hit_y;
	float	w;
	int		reffer;
	float	drawstart;

	drawstart = g->drawstart;
	reffer = 0;
	w = g->lineheight;
	g->lineheight = g->drawend - g->drawstart + 1;
	hit_y = (g->y / BLOCK - (int)(g->y / BLOCK)) * g->tex_we->width;
	if (((int)(g->x * 100) % 100 == 0) && (g->map[(int)g->y / BLOCK]\
	[(int)(g->x + 1) / BLOCK] != '1' || g->map[(int)g->y / BLOCK]\
	[(int)(g->x - 1) / BLOCK] != '1') && (g->player_x < g->x))
		reffer = -10;
	while (drawstart <= g->drawend)
	{
		color_ea = get_pixel_color(g->tex_ea, hit_y, g->tex_ea->y);
		if (reffer == -10)
			my_mlx_pixel_put(g, g->wall_x, drawstart, color_ea);
		g->tex_ea->y += (g->tex_ea->height - 1) / (g->lineheight - 1 + \
		(w - g->lineheight - 1));
		drawstart++;
	}
}

void	ft_draw_west(t_all *g)
{
	int		color_we;
	float	hit_y;
	float	w;
	int		reffer;
	float	drawstart;

	drawstart = g->drawstart - 1;
	reffer = 0;
	w = g->lineheight;
	g->lineheight = g->drawend - g->drawstart + 1;
	hit_y = (g->y / BLOCK - (int)(g->y / BLOCK)) * g->tex_we->width;
	if (((int)(g->x * 100) % 100 == 99) && (g->map[(int)g->y / BLOCK]\
	[(int)(g->x + 1) / BLOCK] != '1' || g->map[(int)g->y / BLOCK]\
	[(int)(g->x - 1) / BLOCK] != '1') && (g->player_x > g->x))
		reffer = 10;
	while (++drawstart <= g->drawend)
	{
		color_we = get_pixel_color(g->tex_we, hit_y, g->tex_we->y);
		if (reffer == 10)
			my_mlx_pixel_put(g, g->wall_x, drawstart, color_we);
		g->tex_we->y += (g->tex_we->height - 1) / (g->lineheight - 1 + \
		(w - g->lineheight - 1));
	}
	g->lineheight = w;
	ft_draw_east(g);
}

void	ft_draw_north(t_all *g)
{
	int		color_no;
	float	hit_x;
	float	w;
	int		reffer;
	float	drawstart;

	drawstart = g->drawstart;
	reffer = 0;
	w = g->lineheight;
	g->lineheight = g->drawend - g->drawstart + 1;
	hit_x = (g->x / BLOCK - (int)(g->x / BLOCK)) * g->tex_so->width;
	if (((int)(g->y * 100) % 100 == 99) && (g->map[(int)(g->y + 1)\
	/ BLOCK][(int)g->x / BLOCK] != '1' || g->map[(int)(g->y - 1) / BLOCK]\
	[(int)g->x / BLOCK] != '1') && (g->player_y > g->y))
		reffer = -10;
	while (drawstart <= g->drawend)
	{
		color_no = get_pixel_color(g->tex_no, hit_x, g->tex_no->y);
		if (reffer == -10)
			my_mlx_pixel_put(g, g->wall_x, drawstart, color_no);
		g->tex_no->y += (g->tex_no->height - 1) / (g->lineheight - 1 + \
		(w - g->lineheight - 1));
		drawstart++;
	}
}

void	ft_draw_south(t_all *g)
{
	int		color_so;
	float	hit_x;
	float	w;
	int		reffer;
	float	drawstart;

	drawstart = g->drawstart - 1;
	reffer = 0;
	w = g->lineheight;
	g->lineheight = g->drawend - g->drawstart + 1;
	hit_x = (g->x / BLOCK - (int)(g->x / BLOCK)) * g->tex_so->width;
	if (((int)(g->y * 100) % 100 == 0) && (g->map[(int)(g->y + 1) / BLOCK]\
	[(int)g->x / BLOCK] != '1' || g->map[(int)(g->y - 1) / BLOCK]\
	[(int)g->x / BLOCK] != '1') && (g->player_y < g->y))
		reffer = 10;
	while (++drawstart <= g->drawend)
	{
		color_so = get_pixel_color(g->tex_so, hit_x, g->tex_so->y);
		if (reffer == 10)
			my_mlx_pixel_put(g, g->wall_x, drawstart, color_so);
		g->tex_so->y += (g->tex_so->height - 1) / (g->lineheight - 1 + \
		(w - g->lineheight - 1));
	}
	g->lineheight = w;
	ft_draw_north(g);
}
