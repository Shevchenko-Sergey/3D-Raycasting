#include "cub3d.h"

int		ft_error(int error)
{
	if (error == 10)
		ft_putstr_fd("Error\nNo player's start mark on the map or multiple \
player's start position in .cub file\n", 2);
	else if (error == 11)
		ft_putstr_fd("Error\nFor the program to work correctly, \
enter .cub file. And type --save if you want screenshot\n", 2);
	else if (error == 12)
		ft_putstr_fd("Error\nWrong resolution (R) in .cub file\n", 2);
	else if (error == 13)
		ft_putstr_fd("Error\nMissing (C) ceiling color in .cub file\n", 2);
	else if (error == 14)
		ft_putstr_fd("Error\nMissing (F) floor color in .cub file\n", 2);
	else if (error == 15)
		ft_putstr_fd("Error\nMissing (R) resolution in .cub file\n", 2);
	else if (error == 16)
		ft_putstr_fd("Error\nMissing texture path in .cub file\n", 2);
	else if (error == 17)
		ft_putstr_fd("Error\nCan't build image\n", 2);
	else if (error == 18)
		ft_putstr_fd("Error\nThe map isn't surrounded by walls\n", 2);
	else if (error == 19)
		ft_putstr_fd("Error\nThe map isn't valid\n", 2);
	else if (error == 20)
		ft_putstr_fd("Error\nThe map is missing\n", 2);
	return (0);
}

int		ft_ceilling_color(t_all *g, t_arg *parse)
{
	int		j;
	char	*color;

	color = NULL;
	j = -1;
	while (g->map[++j])
		if (ft_strnstr(g->map[j], "C", ft_strlen(g->map[j])))
			color = g->map[j];
	if (!color)
		return (ft_error(13));
	while (!ft_isdigit(*color) && *color != '-' && *color != '\0')
	{
		color++;
		if (ft_isalpha(*color))
			return (ft_error(19));
	}
	parse->ceil.r = ft_atoi(color);
	while ((*color != ',') && *color != '\0')
		color++;
	parse->ceil.g = ft_atoi(++color);
	while ((*color != ',') && *color != '\0')
		color++;
	parse->ceil.b = ft_atoi(++color);
	g->ceil_color = 65536 * parse->ceil.r + 256 * parse->ceil.g + parse->ceil.b;
	return (1);
}

int		ft_floor_color(t_all *g, t_arg *parse)
{
	int		j;
	char	*color;

	color = NULL;
	j = -1;
	while (g->map[++j])
		if (ft_strnstr(g->map[j], "F", ft_strlen(g->map[j])))
			color = g->map[j];
	if (!color)
		return (ft_error(14));
	while (!ft_isdigit(*color) && *color != '-' && *color != '\0')
	{
		color++;
		if (ft_isalpha(*color))
			return (ft_error(19));
	}
	parse->fl.r = ft_atoi(color);
	while ((*color != ',') && *color != '\0')
		color++;
	parse->fl.g = ft_atoi(++color);
	while ((*color != ',') && *color != '\0')
		color++;
	parse->fl.b = ft_atoi(++color);
	g->floor_color = 256 * 256 * parse->fl.r + 256 * parse->fl.g + parse->fl.b;
	return (1);
}

int		ft_resolution(t_all *g)
{
	int		j;
	char	*res;

	res = NULL;
	g->winwidth = -1;
	g->winheight = -1;
	j = -1;
	while (g->map[++j])
		if (ft_strnstr(g->map[j], "R", ft_strlen(g->map[j])))
			res = g->map[j];
	if (!res)
		return (ft_error(15));
	while (!ft_isdigit(*res) && *res != '-' && *res != '\0')
	{
		res++;
		if (ft_isalpha(*res))
			return (ft_error(12));
	}
	g->winwidth = ft_atoi(res);
	while (ft_isdigit(*res) && *res != '\0')
		res++;
	g->winheight = ft_atoi(++res);
	(g->winwidth > 1920) ? g->winwidth = 1920 : 0;
	(g->winheight > 1080) ? g->winheight = 1080 : 0;
	return (g->winwidth < 100 || g->winheight < 100) ? (ft_error(12)) : 1;
}

int		ft_parse_textures(t_all *g, t_arg *parse)
{
	int j;

	parse->no = NULL;
	parse->so = NULL;
	parse->we = NULL;
	parse->ea = NULL;
	parse->sprite = NULL;
	j = -1;
	while (g->map[++j] && j < parse->map_start_raw)
	{
		if (ft_strnstr(g->map[j], "NO ", ft_strlen(g->map[j])))
			parse->no = ft_strnstr(g->map[j], "./xpm", ft_strlen(g->map[j]));
		if (ft_strnstr(g->map[j], "SO ", ft_strlen(g->map[j])))
			parse->so = ft_strnstr(g->map[j], "./xpm", ft_strlen(g->map[j]));
		if (ft_strnstr(g->map[j], "WE ", ft_strlen(g->map[j])))
			parse->we = ft_strnstr(g->map[j], "./xpm", ft_strlen(g->map[j]));
		if (ft_strnstr(g->map[j], "EA ", ft_strlen(g->map[j])))
			parse->ea = ft_strnstr(g->map[j], "./xpm", ft_strlen(g->map[j]));
		if (ft_strnstr(g->map[j], "S", ft_strlen(g->map[j])))
			parse->sprite = ft_strnstr(g->map[j], \
								"./xpm", ft_strlen(g->map[j]));
	}
	return (!(parse->no) || !(parse->so) || !(parse->we) || \
			!(parse->ea) || !(parse->sprite)) ? ft_error(16) : 1;
}
