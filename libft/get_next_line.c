/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelmore <dbelmore@student.21-school>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 17:11:27 by dbelmore          #+#    #+#             */
/*   Updated: 2020/10/15 09:46:39 by dbelmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFFER_SIZE 32

static	size_t	ft_strlcpy_gnl(char *dst, char *src, size_t size)
{
	size_t			src_length;
	size_t			count;

	*src = '\0';
	src++;
	count = 0;
	src_length = 0;
	while (src[src_length])
		src_length++;
	if (size != 0)
	{
		while ((count < size - 1) && (count < src_length))
		{
			dst[count] = src[count];
			count++;
		}
		dst[count] = '\0';
	}
	return (src_length);
}

static	char	*ft_strjoin1(char *s1, char const *s2)
{
	size_t			count;
	char			*s3;
	size_t			len_s1;
	size_t			len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	count = 0;
	s3 = (char *)malloc(len_s1 + len_s2 + 1);
	if (!s3)
		return (NULL);
	while (count < (len_s1 + len_s2))
	{
		if (count < len_s1)
			s3[count] = s1[count];
		if (count >= len_s1 && count < len_s2 + len_s1)
			s3[count] = s2[count - len_s1];
		count++;
	}
	s3[count] = '\0';
	free(s1);
	return (s3);
}

int				get_next_line(int fd, char **line)
{
	static	char	remainder[BUFFER_SIZE + 1];
	static	char	buf[BUFFER_SIZE + 1];
	ssize_t			read_bytes;
	char			*tmp_n;

	*line = "\0";
	if (!(*line = ft_strjoin(remainder, *line)))
		return (-1);
	if ((tmp_n = ft_strchr(*line, '\n')))
	{
		ft_strlcpy_gnl(remainder, tmp_n, BUFFER_SIZE);
		return (1);
	}
	while (!tmp_n && (read_bytes = read(fd, buf, BUFFER_SIZE)))
	{
		if (read_bytes == -1)
			return (-1);
		buf[read_bytes] = '\0';
		if ((tmp_n = ft_strchr(buf, '\n')))
			ft_strlcpy_gnl(remainder, tmp_n, BUFFER_SIZE);
		if (!(*line = ft_strjoin1(*line, buf)))
			return (-1);
	}
	(tmp_n == NULL) ? ft_bzero(remainder, BUFFER_SIZE + 1) : 0;
	return (tmp_n) ? 1 : 0;
}
