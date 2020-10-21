#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	int length;

	length = 0;
	while (s[length])
		length++;
	if (s[length] == c)
		return ((char *)s + length);
	while (length - 1 >= 0)
	{
		if (s[length - 1] == c)
			return ((char *)s + length - 1);
		length--;
	}
	return (NULL);
}
