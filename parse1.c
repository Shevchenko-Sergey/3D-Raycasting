#include "cub3d.h"

int		ft_parse_map2(t_all *g, t_arg *parse)
{
	int j;
	int i;

	j = parse->map_start_raw;
	g->map_start_raw = parse->map_start_raw;
	while (++j < parse->map_end_raw)
	{
		i = parse->map_start_col - 1;
		while (g->map[j][++i])
		{
			if (!ft_strchr("1", g->map[g->map_start_raw][i]))
				return (ft_error(18));
			if (!ft_strchr("1", g->map[parse->map_end_raw][i]))
				return (ft_error(18));
			if (g->map[j][i] == '1')
				parse->map_end_col = i;
			if (!ft_strchr("012NSEW ", g->map[j][i]))
				return (ft_error(19));
		}
		if (g->map[j + 1] && (g->map[j - 1][parse->map_end_col] != '1' || \
			g->map[j + 1][parse->map_end_col] != '1'))
			return (ft_error(18));
	}
	return (ft_parse_map3(g, parse));
}

int		ft_parse_map(t_all *g, t_arg *parse)
{
	int j;
	int i;

	j = 0;
	i = 0;
	while (g->map[j] && !(ft_strnstr(g->map[j], "111", ft_strlen(g->map[j])) \
		&& ft_isalpha(g->map[j][0]) == 0))
		parse->map_start_raw = ++j;
	if (!g->map[j])
		return (ft_error(20));
	while (--j > 0)
		if (ft_strchr("RNSWESCF", g->map[j][0]) && g->map[j][0] != '\0')
		{
			parse->args_end_raw = j;
			break ;
		}
	i = 0;
	while (g->map[parse->map_start_raw][i] != '1')
		parse->map_start_col = ++i;
	j = parse->map_start_raw;
	while (g->map[j])
		j++;
	while (!(ft_strnstr(g->map[j], "111", ft_strlen(g->map[j]))))
		parse->map_end_raw = --j;
	return (ft_parse_map2(g, parse));
}

int		ft_player_start_dir(t_all *g, t_arg *parse)
{
	int j;
	int i;
	int count;

	count = 0;
	j = parse->map_start_raw;
	while (g->map[++j])
	{
		i = -1;
		while (g->map[j][++i])
			if (ft_strchr("NSEW", g->map[j][i]))
			{
				parse->player_start_dir = ft_strchr("NSEW", g->map[j][i]);
				g->player_x = (i + 0.5) * BLOCK;
				g->player_y = (j + 0.5) * BLOCK;
				count++;
			}
	}
	if (count > 1 || !parse->player_start_dir)
		return (ft_error(10));
	parse->player_start_dir[0] == 'N' ? g->ray_dir = (3 * M_PI / 2) : 0;
	parse->player_start_dir[0] == 'E' ? g->ray_dir = 0 : 0;
	parse->player_start_dir[0] == 'S' ? g->ray_dir = (M_PI / 2) : 0;
	parse->player_start_dir[0] == 'W' ? g->ray_dir = (M_PI) : 0;
	return (1);
}

int		ft_parse_sprites(t_all *g, t_arg *parse)
{
	int i;
	int j;
	int n;

	n = 0;
	j = parse->map_start_raw;
	while (g->map[++j])
	{
		i = -1;
		while (g->map[j][++i])
			if (ft_strchr("2", g->map[j][i]))
			{
				g->sprite_x[n] = (i + 0.5);
				g->sprite_y[n] = (j + 0.5);
				n++;
			}
	}
	return (1);
}

int		ft_parse_input(t_all *g, t_arg *parse)
{
	parse->player_start_dir = NULL;
	if (ft_parse_map(g, parse) == 0 || ft_player_start_dir(g, parse) == 0)
		return (0);
	if (ft_ceilling_color(g, parse) == 0 || ft_floor_color(g, parse) == 0)
		return (0);
	if (parse->fl.r < 0 || parse->fl.g < 0 || parse->fl.b < 0 || parse->ceil.g \
	< 0 || parse->ceil.b < 0 || parse->ceil.r < 0 || parse->fl.r > 255 || \
	parse->fl.g > 255 || parse->fl.b > 255 || parse->ceil.g > 255 || \
	parse->ceil.b > 255 || parse->ceil.r > 255)
		return (ft_error(17));
	if (ft_resolution(g) == 0 || ft_parse_textures(g, parse) == 0)
		return (0);
	ft_parse_sprites(g, parse);
	return (1);
}
