#include "cub3d.h"

void	ft_draw_walls2(t_all *g)
{
	if (g->drawstart < 0)
	{
		g->tex_we->y = (g->tex_we->height - \
					((g->tex_we->height * g->winheight) / g->lineheight)) / 2;
		g->tex_ea->y = (g->tex_ea->height - \
					((g->tex_ea->height * g->winheight) / g->lineheight)) / 2;
		g->drawstart = 0;
	}
	g->drawend = g->lineheight / 2 + g->winheight / 2;
	(g->drawend >= g->winheight) ? (g->drawend = g->winheight - 1) : 0;
	ft_draw_west(g);
}

void	ft_draw_walls(t_all *g)
{
	g->tex_so->y = 0;
	g->tex_no->y = 0;
	g->tex_we->y = 0;
	g->tex_ea->y = 0;
	g->lineheight = (g->winheight / (g->ray_len *  \
					cos(g->ray_dir - g->ray_start))) * BLOCK;
	g->drawstart = -g->lineheight / 2 + g->winheight / 2;
	if (g->drawstart < 0)
	{
		g->tex_so->y = (g->tex_so->height - \
					((g->tex_so->height * g->winheight) / g->lineheight)) / 2;
		g->tex_no->y = (g->tex_no->height - \
					((g->tex_no->height * g->winheight) / g->lineheight)) / 2;
		g->drawstart = 0;
	}
	else
		ft_draw_ceilling_floor(g);
	g->drawend = g->lineheight / 2 + g->winheight / 2;
	(g->drawend >= g->winheight) ? (g->drawend = g->winheight - 1) \
										: ft_draw_ceilling_floor(g);
	ft_draw_south(g);
	g->lineheight = (g->winheight / (g->ray_len *  \
					cos(g->ray_dir - g->ray_start))) * BLOCK;
	g->drawstart = -g->lineheight / 2 + g->winheight / 2;
	ft_draw_walls2(g);
}

void	ft_draw_sprite2(t_all *g, int w, float ray_len, float spriteheight)
{
	float	x;
	int		color;

	color = 0;
	x = 0;
	while (x < g->tex_sprite->width && w < g->winwidth && w > -1000)
	{
		g->tex_sprite->y = 0;
		g->drawstart = -spriteheight / 2 + g->winheight / 2;
		g->drawend = spriteheight / 2 + g->winheight / 2;
		while (g->drawstart <= g->drawend)
		{
			color = get_pixel_color(g->tex_sprite, x, g->tex_sprite->y);
			if (color != 0 && (g->rays[w] > ray_len) && w > 0)
				my_mlx_pixel_put(g, w, g->drawstart, color);
			g->tex_sprite->y += (g->tex_sprite->height - 1) / spriteheight;
			g->drawstart++;
		}
		w++;
		x = x + (g->tex_sprite->width - 1) / spriteheight;
	}
}

void	ft_sort_sprites(t_all *g, int n)
{
	float	swap;
	int		count;
	int		m;

	count = 0;
	while (count++ < n)
	{
		m = n;
		while (--m >= 0)
			if (g->sprite_ray_len[m - 1] > g->sprite_ray_len[m])
			{
				swap = g->sprite_ray_len[m];
				g->sprite_ray_len[m] = g->sprite_ray_len[m - 1];
				g->sprite_ray_len[m - 1] = swap;
				swap = g->spriteheight[m];
				g->spriteheight[m] = g->spriteheight[m - 1];
				g->spriteheight[m - 1] = swap;
				swap = g->sprite_x_draw[m];
				g->sprite_x_draw[m] = g->sprite_x_draw[m - 1];
				g->sprite_x_draw[m - 1] = swap;
			}
	}
	while (--n >= 0)
		ft_draw_sprite2(g, g->sprite_x_draw[n], \
						g->sprite_ray_len[n], g->spriteheight[n]);
}

void	ft_draw_sprite(t_all *g)
{
	float	sprite_angle;
	int		n;

	n = 0;
	while (g->sprite_x[n] > 0 && g->sprite_y[n] > 0)
	{
		sprite_angle = atan2(g->sprite_y[n] - g->player_y / BLOCK, \
							g->sprite_x[n] - g->player_x / BLOCK);
		while (sprite_angle - g->ray_dir > M_PI)
			sprite_angle -= 2 * M_PI;
		while (sprite_angle - g->ray_dir < -M_PI)
			sprite_angle += 2 * M_PI;
		g->sprite_ray_len[n] = sqrt(pow(g->player_x / BLOCK - \
		g->sprite_x[n], 2) + pow(g->player_y / BLOCK - g->sprite_y[n], 2));
		g->spriteheight[n] = g->winheight / (g->sprite_ray_len[n] * \
									cos(g->ray_dir - sprite_angle));
		if (g->spriteheight[n] > g->winheight)
			g->spriteheight[n] = 0;
		g->sprite_x_draw[n] = g->winwidth / 2 - (g->winwidth * \
						(g->ray_dir - sprite_angle) + g->spriteheight[n] / 2);
		n++;
	}
	ft_sort_sprites(g, n);
}
