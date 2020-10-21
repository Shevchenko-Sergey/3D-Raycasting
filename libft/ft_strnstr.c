#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int c;
	unsigned int l;

	c = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (c < len && big[c])
	{
		l = 0;
		if (little[l] == big[c])
		{
			while (c + l < len && big[c + l] == little[l])
			{
				l++;
				if (!little[l])
					return ((char*)&big[c]);
			}
		}
		c++;
	}
	return (0);
}
