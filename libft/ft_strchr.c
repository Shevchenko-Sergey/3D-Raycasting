#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	int count;

	count = 0;
	if (*s == '\0' && c == '\0')
		return ((char *)s);
	while (s[count])
	{
		if (s[count] == c)
			return ((char *)s + count);
		count++;
		if (s[count] == c)
			return ((char *)s + count);
	}
	return (NULL);
}
