#include "libft.h"

static	size_t	ft_str_length(char const *s, unsigned int start, size_t len)
{
	size_t count;
	size_t size;

	count = 0;
	size = 0;
	while (s[count])
	{
		if (count == start)
		{
			while (size < len && s[count + size])
				size++;
			return (size);
		}
		count++;
	}
	return (0);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	i;
	char	*ret_str;

	if (!s)
		return (NULL);
	i = 0;
	count = 0;
	if (!(ret_str = malloc((ft_str_length(s, start, len) + 1))))
		return (NULL);
	while (s[count])
	{
		if (count == start)
		{
			ret_str[i] = s[count];
			while (i < len && s[count])
				ret_str[i++] = s[count++];
			ret_str[i] = '\0';
			return (ret_str);
		}
		count++;
	}
	ret_str[i] = '\0';
	return (ret_str);
}
