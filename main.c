#include "cub3d.h"

int		ft_read_cub_file(t_list **head, int size, t_all *g, t_arg *parse)
{
	int		i;
	t_list	*tmp;

	tmp = *head;
	i = -1;
	if (!(g->map = ft_calloc(size + 1, sizeof(char *))))
		return (0);
	while (tmp)
	{
		g->map[++i] = tmp->content;
		tmp = tmp->next;
	}
	if (ft_parse_input(g, parse) == 0)
		return (0);
	return (1);
}

int		ft_argv_check(int argc, char **argv)
{
	char	*arg1;
	char	*arg2;
	char	*dot;

	arg1 = argv[1];
	arg2 = argv[2];
	if (argc < 2 || argc > 3)
		return (0);
	if (!(dot = ft_strchr(arg1, '.')))
		return (0);
	if (ft_strncmp(".cub", dot, 4) != 0 || ft_strlen(dot) != 4)
		return (0);
	if (arg2 && (ft_strncmp("--save", arg2, 6) != 0 || ft_strlen(arg2) != 6))
		return (0);
	if (argc == 3)
		return (2);
	return (1);
}

int		main(int argc, char **argv)
{
	int			fd;
	char		*line;
	t_list		*head;
	t_all		g;
	t_arg		parse;

	line = NULL;
	head = NULL;
	g.save = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_error(11));
	if (ft_argv_check(argc, argv) == 0)
		return (ft_error(11));
	if (ft_argv_check(argc, argv) == 2)
		g.save = 1;
	while (get_next_line(fd, &line) > 0)
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	if (ft_read_cub_file(&head, ft_lstsize(head), &g, &parse) == 0)
		return (0);
	if (ft_makewindow(&g, &parse) == 0)
		return (0);
	return (0);
}
