#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dest_ft;
	unsigned char	*src_ft;
	size_t			count;

	count = 0;
	dest_ft = (unsigned char *)dest;
	src_ft = (unsigned char *)src;
	while (count < n)
	{
		dest_ft[count] = src_ft[count];
		if (src_ft[count] == (unsigned char)c)
			return (dest + count + 1);
		count++;
	}
	return (NULL);
}
