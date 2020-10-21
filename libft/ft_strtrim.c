#include "libft.h"

static		size_t		ft_count_end(char const *s1, char const *set)
{
	size_t	count_end;
	size_t	i;
	size_t	s1_length;

	count_end = 0;
	s1_length = ft_strlen(s1);
	if (s1_length == 0)
		return (0);
	while (s1_length - 1 != 0)
	{
		i = 0;
		while (set[i] != s1[s1_length - 1] && set[i])
			i++;
		if (i != ft_strlen(set))
		{
			count_end++;
			s1_length--;
		}
		else
			break ;
	}
	return (count_end);
}

static		size_t		ft_count_beg(char const *s1, char const *set)
{
	size_t	count_beg;
	size_t	i;

	count_beg = 0;
	while (s1[count_beg])
	{
		i = 0;
		while (set[i] != s1[count_beg] && set[i])
			i++;
		if (i != ft_strlen(set))
			count_beg++;
		else
			break ;
	}
	return (count_beg);
}

char					*ft_strtrim(char const *s1, char const *set)
{
	char	*s1_trimmed;
	size_t	i;
	size_t	count_beg;
	size_t	s1_length;
	size_t	s1_trimmed_length;

	if (!s1 || !set)
		return (NULL);
	s1_length = ft_strlen(s1);
	count_beg = ft_count_beg(s1, set);
	i = 0;
	if (s1_length > count_beg + ft_count_end(s1, set))
	{
		s1_trimmed_length = (s1_length - count_beg - ft_count_end(s1, set));
		if (!(s1_trimmed = malloc(s1_length - count_beg - \
						ft_count_end(s1, set) + 1)))
			return (NULL);
		while (i < s1_trimmed_length)
			s1_trimmed[i++] = s1[count_beg++];
		s1_trimmed[i] = '\0';
		return (s1_trimmed);
	}
	s1_trimmed = malloc(1);
	s1_trimmed[0] = '\0';
	return (s1_trimmed);
}
