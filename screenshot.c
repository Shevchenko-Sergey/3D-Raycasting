#include "cub3d.h"

int		ft_get_pixel_color2(t_all *g, int x, int y)
{
	char		*dst;

	dst = g->addr + (y * g->line_length + x * (g->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}

void	ft_bmdata(t_all *g, int fd)
{
	int				i;
	int				j;
	int				color;

	i = g->winheight - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < g->winwidth)
		{
			color = ft_get_pixel_color2(g, j, i);
			write(fd, &color, 4);
			j++;
		}
		i--;
	}
}

void	ft_bminfo(t_all *g, int fd)
{
	int				n;
	unsigned char	header[40];

	n = 0;
	while (n < 40)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(40);
	n = g->winwidth;
	header[4] = (unsigned char)(n % 256);
	header[5] = (unsigned char)(n / 256 % 256);
	header[6] = (unsigned char)(n / 256 / 256 % 256);
	header[7] = (unsigned char)(n / 256 / 256 / 256);
	n = g->winheight;
	header[8] = (unsigned char)(n % 256);
	header[9] = (unsigned char)(n / 256 % 256);
	header[10] = (unsigned char)(n / 256 / 256 % 256);
	header[11] = (unsigned char)(n / 256 / 256 / 256);
	header[12] = (unsigned char)(1);
	header[14] = (unsigned char)(32);
	write(fd, header, 40);
}

void	ft_bmfile(t_all *g, int fd)
{
	int				n;
	unsigned char	header[14];

	n = 0;
	while (n < 14)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(66);
	header[1] = (unsigned char)(77);
	n = g->winwidth * g->winheight * 4 + 54;
	header[2] = (unsigned char)(n % 256);
	header[3] = (unsigned char)(n / 256 % 256);
	header[4] = (unsigned char)(n / 256 / 256 % 256);
	header[5] = (unsigned char)(n / 256 / 256 / 256);
	header[10] = (unsigned char)(54);
	write(fd, header, 14);
}

int		ft_bitmap(t_all *g)
{
	int		fd;

	fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	ft_bmfile(g, fd);
	ft_bminfo(g, fd);
	ft_bmdata(g, fd);
	close(fd);
	ft_exit(g, 0);
	return (1);
}
