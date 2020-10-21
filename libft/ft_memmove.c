#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_ft;
	const char	*src_ft;
	size_t		i;

	if (!(dest) && !(src))
		return (NULL);
	dest_ft = dest;
	src_ft = src;
	i = 0;
	if (dest_ft <= src_ft)
	{
		while (i < n)
		{
			dest_ft[i] = src_ft[i];
			i++;
		}
	}
	else
	{
		while (n--)
			dest_ft[n] = src_ft[n];
	}
	return (dest);
}
