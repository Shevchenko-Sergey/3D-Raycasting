#include "cub3d.h"

int		ft_parse_map5(t_all *g, t_arg *parse)
{
	int		j;
	int		i;

	j = parse->map_start_raw;
	while (++j < parse->map_end_raw)
		if (g->map[j + 1] && (g->map[j - 1][parse->map_start_col] != '1' \
			|| g->map[j + 1][parse->map_start_col] != '1'))
			return (ft_error(18));
	j = parse->args_end_raw;
	while (++j < parse->map_start_raw)
	{
		i = 0;
		while (g->map[j][i++] != '\0')
			if (ft_isascii(g->map[j][i]))
				return (ft_error(19));
	}
	return (1);
}

int		ft_parse_map4(t_all *g, t_arg *parse)
{
	int		j;
	int		i;

	j = parse->map_start_raw;
	while (g->map[j] && j <= parse->map_end_raw)
	{
		i = parse->map_end_col + 1;
		while (g->map[j][i] != '\0')
		{
			if (ft_isascii(g->map[j][i]))
				return (ft_error(19));
			i++;
		}
		j++;
	}
	while (g->map[j])
	{
		i = 0;
		while (g->map[j][i++] != '\0')
			if (ft_isascii(g->map[j][i]))
				return (ft_error(19));
		j++;
	}
	return (ft_parse_map5(g, parse));
}

int		ft_parse_map3(t_all *g, t_arg *parse)
{
	int		j;
	int		i;

	j = parse->map_start_raw;
	while (g->map[j] && j <= parse->map_end_raw)
	{
		i = 0;
		while (i < parse->map_start_col)
		{
			if (!ft_strchr(" ", g->map[j][i]))
				return (ft_error(19));
			i++;
		}
		j++;
	}
	j = -1;
	while (g->map[++j] && j < parse->map_start_raw)
		if ((!ft_strchr("RNSWESCF ", g->map[j][0]) || \
			!ft_strchr("OEA ", g->map[j][1])) && g->map[j][0] != '\0')
			return (ft_error(19));
	return (ft_parse_map4(g, parse));
	printf("parse->map_start_col:%d  %d\n", parse->map_start_col, i);
	return (1);
}
